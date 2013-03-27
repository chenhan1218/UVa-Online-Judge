#include <iostream>
using namespace std ;

int main()
{
	bool prime_number[ 1041 ] ;
	for( int i = 0 ; i < 1041 ; i++ )
	{
		prime_number[ i ] = 0 ;
	}

	int **prime = new int *[ 176 ] ;
	prime[ 1 ] = new int [ 2 ] ;
	prime[ 1 ][ 0 ] = 2 ;
	prime[ 1 ][ 1 ] = 4 ;
	prime_number[ 2 ] = 1 ;

	prime[ 2 ] = new int [ 1 ] ;
	prime[ 2 ][ 0 ] = 3 ;
	prime[ 2 ][ 1 ] = 9 ;
	prime_number[ 3 ] = 1 ;


/* fucking exception, 1 is a prime number */
	prime_number[ 1 ] = 1 ;


	long long int largest_prime_number = 2 ;

	for( int i = 3 ; i < 176  ; i++ )
	{
		for( int j = prime[ i - 1 ][ 0 ] + 2 ; j < 1041 ; j = j + 2 )
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

				prime_number[ j ] = 1 ;

				break ;
			}
		}
	}

	char input[ 21 ] ;
	int value_input = 0 , ascii_input
		, ascii_a = static_cast<int>( 'a' ) , ascii_z = static_cast<int>( 'z' )
		, ascii_A = static_cast<int>( 'A' ) , ascii_Z = static_cast<int>( 'Z' ) ;
	int i ;
	while( cin >> input )
	{
		value_input = 0 ;

		i = 0 ;
		while( input[ i ] != '\0' )
		{
			ascii_input = static_cast<int>( input[ i ] ) ;

			if( ascii_input <= ascii_z && ascii_input >= ascii_a )
			{
				value_input += ascii_input - ascii_a + 1 ;
			}
			else if( ascii_input <= ascii_Z && ascii_input >= ascii_A )
			{
				value_input += ascii_input - ascii_A + 27 ;
			}

			i++ ;
		}

		if( prime_number[ value_input ] )
		{
			cout << "It is a prime word." << endl ;
		}
		else
		{
			cout << "It is not a prime word." << endl ;
		}
	}

	return 0 ;
}
