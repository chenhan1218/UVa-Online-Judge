#include <iostream>
#include <algorithm>
#include <string>
using namespace std ;

#define MaxHeight 3000

int		h = 0 ;
int		w = 0 ;
string	grid[ MaxHeight ] ;

void dfs( int r, int c, char target )
{
	if( r < 0 || r >= h || c < 0 || c >= w || grid[ r ][ c ] != target )
		return ;
	
	grid[ r ][ c ] = 0 ;
	dfs( r-1, c, target ) ;
	dfs( r+1, c, target ) ;
	dfs( r, c+1, target ) ;
	dfs( r, c-1, target ) ;
}

int main()
{
	int		occur[ 26 ] = { 0 } ;
	int		index = 0 ;
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	cin >> casenum ;
	
	for( runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		cin >> h >> w ;
		for( i = 0 ; i < h ; i++ )
		{
			cin >> grid[ i ] ;
		}
		
		fill( occur, occur + 26, 0 ) ;
		for( i = 0 ; i < h ; i++ )
		{
			for( j = 0 ; j < w ; j++ )
			{
				if( grid[ i ][ j ] != 0 )
				{
					occur[ grid[ i ][ j ] - 'a' ] ++ ;\
					dfs( i, j, grid[ i ][ j ] ) ;
				}
			}
		}
		
		cout << "World #" << runningCase << endl ;
		while( *( max_element( occur, occur + 26 ) ) != 0 )
		{
			index = max_element( occur, occur + 26 ) - occur ;
			cout << (char)('a' + index) << ": " << occur[ index ] << endl ;
			occur[ index ] = 0 ;
		}
	}
	
	return 0 ;
}
