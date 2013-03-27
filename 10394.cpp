#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int **prime = new int *[ 610 ] ;
	prime[ 1 ] = new int [ 2 ] ;
	prime[ 1 ][ 0 ] = 2 ;
	prime[ 1 ][ 1 ] = 4 ;
	prime[ 2 ] = new int [ 1 ] ;
	prime[ 2 ][ 0 ] = 3 ;
	prime[ 2 ][ 1 ] = 9 ;
	int largest_prime_number = 2 ;

	int **twin_prime = new int *[ 100001 ] ;
	twin_prime[ 1 ] = new int [ 2 ] ;
	twin_prime[ 1 ][ 0 ] = 3 ;
	twin_prime[ 1 ][ 1 ] = 5 ;

	int largest_prime_pair = 1 ;

	for( int i = 3 ; i < 610 ; i++ )
	{
		for( int j = prime[ i - 1 ][ 0 ] + 2 ;  ; j = j + 2 )
		{
			int k ;
			for( k = 1 ; prime[ k ][ 1 ] < j ; k++ )
			{
				if( j % prime[ k ][ 0 ] == 0 )
				{
					break ;
				}
			}

			if( prime[ k ][ 1 ] > j )
			{
				prime[ i ] = new int [ 2 ] ;

				prime[ i ][ 0 ] = j ;
				prime[ i ][ 1 ] = j * j ;

				break ;
			}
		}
	}

	int early_twin = -1 ;
	int later_twin = 1 ;

	int S ;
	int divisor , remainder ;

	while( cin >> S )
	{
		while( largest_prime_pair < S )
		{
			early_twin += 6 ;
			later_twin += 6 ;

			int i ;
			for( i = 1 ; prime[ i ][ 1 ] < early_twin ; i++ )
			{
				divisor = prime[ i ][ 0 ] ;
				if( ( remainder = early_twin % divisor ) == 0 || ( remainder + 2 ) == divisor )
				{
					break ;
				}
			}

			if( prime[ i ][ 1 ] > later_twin )
			{
				largest_prime_pair ++ ;

				twin_prime[ largest_prime_pair ] = new int [ 2 ] ;

				twin_prime[ largest_prime_pair ][ 0 ] = early_twin ;
				twin_prime[ largest_prime_pair ][ 1 ] = later_twin ;
			}
		}

		cout << "(" << twin_prime[ S ][ 0 ] << ", " << twin_prime[ S ][ 1 ] << ")" << endl ;
	}

	return 0 ;
}
