#include <iostream>
#include <vector>
using namespace std ;

#define MaxN 200

vector<int>	neighbor[ MaxN ] ;
int	colorMap[ MaxN ] = { 0 } ;
int	solved = true ;

void dfs( int n, int color )
{
	int		i = 0 ;
	if( colorMap[ n ] == -1 )
	{
		colorMap[ n ] = color ;
		for( i = 0 ; i < neighbor[ n ].size() ; i++ )
			dfs( neighbor[ n ][ i ], 1 - color ) ;
	}
	else
	{
		if( colorMap[ n ] != color )
			solved = false ;
	}
}

int main()
{
	int		n = 0 ;
	int		m = 0 ;
	int		a = 0 ;
	int		b = 0 ;
	int		i = 0 ;
	
	while( cin >> n && n != 0 )
	{
		for( i = 0 ; i < n ; i++ )
			neighbor[ i ].clear() ;
		fill( colorMap, colorMap + MaxN, -1 ) ;
		
		cin >> m ;
		for( i = 0 ; i < m ; i++ )
		{
			cin >> a >> b ;
			neighbor[ a ].push_back( b ) ;
			neighbor[ b ].push_back( a ) ;
		}
		
		solved = true ;
		dfs( 0, 0 ) ;
		
		if( solved == true )
			cout << "BICOLORABLE." << endl ;
		else
			cout << "NOT BICOLORABLE." << endl ;
	}
	
	
	return 0 ;
}
