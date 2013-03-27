#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std ;

#define MaxN 30
#define MaxValue 50

long long int	squares[ MaxN * 2 + 1 ][ MaxN + 1 ] ;
bitset<(MaxN*2-1) * MaxValue * 2 + 1 > num[ MaxN * 2 + 1 ][ MaxN + 1 ] ;

int main()
{
	int		n = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> n && n != 0 )
	{
		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= i ; j++ )
			{
				cin >> squares[ i ][ j ] ;
				squares[ i ][ j ] = abs( squares[ i ][ j ] ) ;
			}
		}
		for( i = n + 1 ; i <= n * 2 - 1 ; i++ )
		{
			for( j = 1 ; j <= n * 2 - i ; j++ )
			{
				cin >> squares[ i ][ j ] ;
				squares[ i ][ j ] = abs( squares[ i ][ j ] ) ;
			}
		}

		num[ n * 2 ][ 1 ].reset() ;
		num[ n * 2 ][ 1 ][ MaxN * MaxValue ] = 1 ;
		num[ n * 2 ][ 2 ].reset() ;

		for( i = n * 2 - 1 ; i >= n ; i-- )
		{
			for( j = 1 ; j <= n * 2 - i ; j++ )
			{
				num[ i ][ j ] = 	( num[ i + 1 ][ j - 1 ] << squares[ i ][ j ] ) | 
								( num[ i + 1 ][ j - 1 ] >> squares[ i ][ j ] ) |
								( num[ i + 1 ][ j ] << squares[ i ][ j ] ) |
								( num[ i + 1 ][ j ] >> squares[ i ][ j ] ) ;
			}
			num[ i ][ n * 2 - i + 1 ].reset() ;
		}
		for( i = n - 1 ; i >= 1 ; i-- )
		{
			for( j = 1 ; j <= i ; j++ )
			{
				num[ i ][ j ] = 	( num[ i + 1 ][ j ] << squares[ i ][ j ] ) | 
								( num[ i + 1 ][ j ] >> squares[ i ][ j ] ) |
								( num[ i + 1 ][ j + 1 ] << squares[ i ][ j ] ) |
								( num[ i + 1 ][ j + 1 ] >> squares[ i ][ j ] ) ;
			}
		}

		i = 0 ;
		while( num[ 1 ][ 1 ][ i + MaxN * MaxValue ] == 0 )
			i++ ;
		cout << i << endl ;
	}

	return 0 ;
}

