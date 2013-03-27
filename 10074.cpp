#include <iostream>
using namespace std ;

int main()
{
	int		M = 0 ;
	int		N = 0 ;
	
	// This record the max number of rows that the elements are all zero in that column
	//(count up start from maxRowLand[i][j] ).
	int		maxRowLand[ 101 ][ 101 ] = { 0 } ;
	int		isTree[ 101 ][ 101 ] = { 0 } ;
	
	while( cin >> M >> N  )
	{
		if( M == 0 && N == 0 )
			break ;
		
		int		ans = 0 ;
		for( int i = 1 ; i <= M ; i++ )
		{
			for( int j = 1 ; j <= N ; j++ )
			{
				cin >> isTree[ i ][ j ] ;
				if( isTree[ i ][ j ] == 0 )
				{
					maxRowLand[ i ][ j ] = maxRowLand[ i - 1 ][ j ] + 1 ;
					
					int		maxRow = maxRowLand[ i ][ j ] ;
					for( int k = 1 ; k <= j ; k++ )
					{
						maxRow = min( maxRow, maxRowLand[ i ][ j - k + 1 ] ) ;
						ans = max( ans, maxRow * k ) ;
					}
				}
				else
				{
					maxRowLand[ i ][ j ] = 0 ;
				}
			}
		}
		
		cout << ans << endl ;
	}
	
	return 0 ;
}
