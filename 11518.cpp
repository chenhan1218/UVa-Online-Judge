#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

const int	MaxN = 10000 ;
bool	falldown[ MaxN + 1 ] = { 0 } ;
vector<int>	nextTile[ MaxN + 1 ] ;

void dfs( int z )
{
	if( falldown[ z ] == false )
	{
		falldown[ z ] = true ;
		for( vector<int>::size_type ix = 0 ; ix != nextTile[ z ].size() ; ix++ )
		{
			dfs( nextTile[ z ][ ix ] ) ;
		}
	}
}

int main()
{
	int		testcase = 0 ;
	
	cin >> testcase ;
	for( int runningCase = 1 ; runningCase <= testcase ; runningCase++ )
	{
		int		n = 0 ;
		int		m = 0 ;
		int		l = 0 ;
		int		x = 0 ;
		int		y = 0 ;
		int		z = 0 ;
		cin >> n >> m >> l ;

		fill( falldown + 1, falldown + n + 1, false ) ;
		for( int i = 1 ; i <= n ; i++ )
		{
			nextTile[ i ].clear() ;
		}
		
		for( int i = 0 ; i < m ; i++ )
		{
			cin >> x >> y ;
			nextTile[ x ].push_back( y ) ;
		}
		
		for( int i = 0 ; i < l ; i++ )
		{
			cin >> z ;
			dfs( z ) ;
		}
		
		cout << count( falldown + 1, falldown + n + 1, true ) << endl ;
	}
	
	return 0 ;
}
