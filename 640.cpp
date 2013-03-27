#include <iostream>
using namespace std ;

int main()
{
	int *numbers = new int [ 1000001 ] ;
	for( int i = 0 ; i <= 1000000 ; i++ )
	{
		numbers[ i ] = 1 ;
	}

	int buffer , digits ;

	for( int i = 1 ; i < 999900 ; i++ )
	{
		buffer = i ;
		digits = i ;

		while( digits != 0 )
		{
			buffer += digits % 10 ;
			digits /= 10 ;
		}

		numbers[ buffer ] = 0 ;

		if( numbers[ i ] == 1 )
		{
			cout << i << endl ;
		}
	}

	for( int i = 999900 ; i <= 1000000 ; i++ )
	{
		buffer = i ;
		digits = i ;

		while( digits != 0 )
		{
			buffer += digits % 10 ;
			digits /= 10 ;
		}

		if( buffer <= 1000000 )
		{
			numbers[ buffer ] = 0 ;
		}

		if( numbers[ i ] == 1 )
		{
			cout << i << endl ;
		}
	}

	return 0 ;
}
