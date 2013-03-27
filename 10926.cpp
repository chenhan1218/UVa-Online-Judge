#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std ;

#define MaxN 100

vector<int>	dep[ MaxN + 1 ] ;
bool	visited[ MaxN + 1 ] = { 0 } ;

void dfs( int index )
{
	int		i = 0 ;
	
	if( visited[ index ] == false )
	{
		visited[ index ] = true ;
		
		for( i = 0 ; i < dep[ index ].size() ; i++ )
		{
			dfs( dep[ index ][ i ] ) ;
		}
	}
}

int main()
{
	int		n = 0 ;
	int		maxDepnum = 0 ;
	int		greatestTask = 0 ;
	int		t = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	while( cin >> n && n != 0 )
	{
		for( i = 1 ; i <= n ; i++ )
		{
			cin >> t ;
			dep[ i ].assign( t, 0 ) ;
			for( j = 0 ; j < t ; j++ )
			{
				cin >> dep[ i ][ j ] ;
			}
		}

		maxDepnum = 0 ;
		greatestTask = 0 ;
		for( i = 1 ; i <= n ; i++ )
		{
			fill( visited, visited + n + 1, false ) ;
			dfs( i ) ;
			if( count( visited, visited + n + 1, true ) - 1 > maxDepnum )
			{
				maxDepnum = count( visited, visited + n + 1, true ) - 1 ;
				greatestTask = i ;
			}
		}
		
		cout << greatestTask << endl ;
	}
	
	return 0 ;
}
