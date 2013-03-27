#include <iostream>
#include <vector>
using namespace std ;

bool	neighbor[ 6 ][ 6 ] = { 0 } ;
vector<int>	path ;

void dfs()
{
	int		i = 0 ;
	if( path.size() == 9 )
	{
		for( i = 0 ; i < path.size() ; i++ )
		{
			cout << path[ i ] ;
		}
		cout << endl ;
	}
	else if( path.size() == 0 )
	{
		path.push_back( 1 ) ;
		dfs() ;
		path.pop_back() ;
	}
	else
	{
		for( i = 1 ; i <= 5 ; i++ )
		{
			if( neighbor[ path.back() ][ i ] == true )
			{
				neighbor[ path.back() ][ i ] = false ;
				neighbor[ i ][ path.back() ] = false ;
				path.push_back( i ) ;
				dfs() ;
				path.pop_back() ;
				neighbor[ i ][ path.back() ] = true ;
				neighbor[ path.back() ][ i ] = true ;
			}
		}
	}
}

int main()
{
	int		i = 0 ;
	int		j = 0 ;
	
	for( i = 1 ; i <= 5 ; i++ )
	{
		for( j = 1 ; j <= 5 ; j++ )
		{
			if( i == j )
			{
				neighbor[ i ][ j ] = false ;
			}
			else
			{
				neighbor[ i ][ j ] = true ;
			}
		}
	}
	
	neighbor[ 1 ][ 4 ] = false ;
	neighbor[ 4 ][ 1 ] = false ;
	neighbor[ 2 ][ 4 ] = false ;
	neighbor[ 4 ][ 2 ] = false ;
	
	dfs() ;
	
	return 0 ;
}
