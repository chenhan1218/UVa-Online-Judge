#include <iostream>
#include <algorithm>
#include <set>
using namespace std ;

const int	MaxNode = 26 ;

set<int>	neighbor[ MaxNode ] ;
bool	visited[ MaxNode ] = { 0 } ;

bool dfs( int n )
{
	if( visited[ n ] == false )
	{
		visited[ n ] = true ;
		
		for( set<int>::const_iterator iter = neighbor[ n ].begin() ; 
			iter != neighbor[ n ].end() ; ++iter )
		{
			dfs( *iter ) ;
		}
		return true ;
	}
	else
	{
		return false ;
	}
}

int main()
{
	int		testcase = 0 ;
	string	buffer ;
	char	largestNode ;
	
	cin >> testcase ;
	
	for( int running = 1 ; running <= testcase ; running++ )
	{
		cin >> largestNode ;
		getline( cin, buffer ) ; // absorb the endl
		int		node = largestNode - 'A' + 1 ;
		
		
		fill( visited, visited + node, false ) ;
		for( int i = 0 ; i < node ; i++ )
		{
			neighbor[ i ].clear() ;
		}
		
		while( getline( cin, buffer ) && buffer != "" )
		{
			neighbor[ buffer[ 0 ] - 'A' ].insert( buffer[ 1 ] - 'A' ) ;
			neighbor[ buffer[ 1 ] - 'A' ].insert( buffer[ 0 ] - 'A' ) ;
		}
		
		int		subgraphs = 0 ;
		for( int i = 0 ; i < node ; i++ )
		{
			if( dfs( i ) == true )
				subgraphs++ ;
		}
		
		if( running > 1 )
		{
			cout << endl ; //The outputs of two consecutive cases will be separated by a blank line. 
		}
		cout << subgraphs << endl ;
	}
	
	return 0 ;
}
