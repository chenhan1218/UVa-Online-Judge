#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

bool	visited[ 26 ] = { 0 } ;
vector<int>	neighbor[ 26 ] ;

void dfs( int index, int &counter )
{
	int		i = 0 ;
	if( visited[ index ] == false )
	{
		visited[ index ] = true ;
		counter++ ;
		for( i = 0 ; i < neighbor[ index ].size() ; i++ )
			dfs( neighbor[ index ][ i ], counter ) ;
	}
}

int main()
{
	string	buffer ;
	int		numTree = 0 ;
	int		numAcorn = 0 ;
	int		counter = 0 ;
	int		t = 0 ;
	int		i = 0 ;

	cin >> t ;
	while( t > 0 )
	{
		t-- ;

		fill( visited, visited + 26, false ) ;
		for( i = 0 ; i < 26 ; i++ )
			neighbor[ i ].clear() ;
		
		while( cin >> buffer && buffer[ 0 ] != '*' )
		{
			neighbor[ buffer[ 1 ] - 'A' ].push_back( buffer[ 3 ] - 'A' ) ;
			neighbor[ buffer[ 3 ] - 'A' ].push_back( buffer[ 1 ] - 'A' ) ;
		}
		
		cin >> buffer ;
		numAcorn = 0 ;
		numTree = 0 ;
		for( i = 0 ; i < buffer.size() ; i += 2 )
		{
			if( visited[ buffer[ i ] - 'A' ] == false )
			{
				counter = 0 ;
				dfs( buffer[ i ] - 'A', counter ) ;
			
				if( counter == 1 )
					numAcorn++ ;
				else
					numTree++ ;
			}
		}
		
		cout << "There are " << numTree << " tree(s) and " << numAcorn << " acorn(s)." << endl ;
	}
	
	return 0 ;
}
