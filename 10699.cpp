#include <iostream>
using namespace std ;

int main()
{
	int **prime = new int *[ 170 ] ;
	prime[ 1 ] = new int [ 2 ] ;
	prime[ 1 ][ 0 ] = 2 ;
	prime[ 1 ][ 1 ] = 4 ;
	prime[ 2 ] = new int [ 1 ] ;
	prime[ 2 ][ 0 ] = 3 ;
	prime[ 2 ][ 1 ] = 9 ;
	int largest_prime_number = 2 ;

	for( int i = 3 ; i < 170 ; i++ )
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

	int input , dealing_input , prime_number ;

	while( cin >> input )
	{
		if( input == 0 )
		{
			break ;
		}

		dealing_input = input ;
		prime_number = 0 ;

		for( int i = 1 ; prime[ i ][ 1 ] <= dealing_input && i < 170 ; i++ )
		{
			if( dealing_input % prime[ i ][ 0 ] == 0 )
			{
				prime_number++ ;

				dealing_input /= prime[ i ][ 0 ] ;

				while( dealing_input % prime[ i ][ 0 ] == 0 )
				{
					dealing_input /= prime[ i ][ 0 ] ;
				}
			}
		}
		if( dealing_input > 1 )
		{
			prime_number++ ;
		}

		cout << input << " : " << prime_number << endl ;
	}

	return 0 ;
}
