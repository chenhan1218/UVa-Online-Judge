#include <iostream>
#include <algorithm>
using namespace std ;

#define MaxN 100

int		n = 0 ;
int		data[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;
int		diff[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;

void print( int a )
{
	int		i = 0 ;
	int		j = 0 ;

	for( i = 1 ; i <= a ; i++ )
	{
		for( j = 1 ; j <= a ; j++ )
		{
			cout << data[ i ][ j ] << "\t" ;
		}
		cout << endl ;
	}
}

int main()
{
	int		m = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;

	while( cin >> n && n != 0 )
	{
		for( i = 1 ; i <= n ; i++ )
			cin >> data[ i ][ i ] ;
		
		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n - i + 1 ; j++ )
			{
				data[ j ][ j + i - 1 ] = data[ j ][ j ] + data[ j + 1 ][ j + i - 1 ] ;
			}
		}
		
		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n - i + 1 ; j++ )
			{
				diff[ j ][ j + i - 1 ] = data[ j ][ j + i - 1 ] ;

				for( k = 1 ; k < i ; k++ )
				{
					diff[ j ][ j + i - 1 ] = max( diff[ j ][ j + i - 1 ], 
						data[ j ][ j + k - 1 ] - diff[ j + k ][ j + i - 1 ] ) ;
				}

				for( k = 1 ; k < i ; k++ )
				{
					diff[ j ][ j + i - 1 ] = max( diff[ j ][ j + i - 1 ], 
						data[ j + k ][ j + i - 1 ] - diff[ j ][ j + k - 1 ] ) ;
				}
			}
		}
		
		cout << diff[ 1 ][ n ] << endl ;
	}

	return 0 ;
}

