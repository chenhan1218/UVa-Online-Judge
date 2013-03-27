#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	long long digit18 = 1000000000 ;
	digit18 *= digit18 ;

	long long int *Fibonacci[ 5001 ] ;
	Fibonacci[ 0 ] = new long long int [ 1 ] ;
	Fibonacci[ 0 ][ 0 ] = 0 ;
	Fibonacci[ 1 ] = new long long int [ 1 ] ;
	Fibonacci[ 1 ][ 0 ] = 1 ;

	int number_longint = 1 ;

	for( int i = 2 ; i <= 5000 ; i++ )
	{
		if( i % 80 == 0 )
		{
			number_longint++ ;

			const int dealing_number_longint = number_longint ;

			Fibonacci[ i ] = new long long int [ number_longint ] ;

			for( int j = 0 ; j < number_longint - 1 ; j++ )
			{
				Fibonacci[ i ][ j ] = Fibonacci[ i - 1 ][ j ] + Fibonacci[ i - 2 ][ j ] ;
			}

			Fibonacci[ i ][ number_longint - 1 ] = 0 ;
			for( int j = 0 ; j < number_longint - 1 ; j++ )
			{
				if( Fibonacci[ i ][ j ] >= digit18 )
				{
					Fibonacci[ i ][ j + 1 ] += Fibonacci[ i ][ j ] / digit18 ;

					Fibonacci[ i ][ j ] = Fibonacci[ i ][ j ] % digit18 ;
				}
			}
		}
		else if( i % 80 == 1 )
		{
			const int dealing_number_longint = number_longint ;

			Fibonacci[ i ] = new long long int [ number_longint ] ;

			for( int j = 0 ; j < number_longint - 1 ; j++ )
			{
				Fibonacci[ i ][ j ] = Fibonacci[ i - 1 ][ j ] + Fibonacci[ i - 2 ][ j ] ;
			}

			Fibonacci[ i ][ number_longint - 1 ] = Fibonacci[ i - 1 ][ number_longint - 1 ] ;
			for( int j = 0 ; j < number_longint - 1 ; j++ )
			{
				if( Fibonacci[ i ][ j ] >= digit18 )
				{
					Fibonacci[ i ][ j + 1 ] += Fibonacci[ i ][ j ] / digit18 ;

					Fibonacci[ i ][ j ] = Fibonacci[ i ][ j ] % digit18 ;
				}
			}
		}
		else
		{
			const int dealing_number_longint = number_longint ;

			Fibonacci[ i ] = new long long int [ number_longint ] ;

			for( int j = 0 ; j < number_longint ; j++ )
			{
				Fibonacci[ i ][ j ] = Fibonacci[ i - 1 ][ j ] + Fibonacci[ i - 2 ][ j ] ;
			}

			for( int j = 0 ; j < number_longint ; j++ )
			{
				if( Fibonacci[ i ][ j ] >= digit18 )
				{
					Fibonacci[ i ][ j + 1 ] += Fibonacci[ i ][ j ] / digit18 ;

					Fibonacci[ i ][ j ] = Fibonacci[ i ][ j ] % digit18 ;
				}
			}
		}
	}

	int input ;

	while( cin >> input )
	{
		if( input == 0 )
		{
			cout << "The Fibonacci number for 0 is 0" << endl ;
		}
		else
		{
			number_longint = input / 80 + 1 ;

			cout << "The Fibonacci number for " << input << " is " ;

			int i = number_longint - 1 ;

			while( Fibonacci[ input ][ i ] == 0 )
			{
				i-- ;
			}

			cout << Fibonacci[ input ][ i ] ;

			for( i = i - 1 ; i >= 0 ; i-- )
			{
				cout << setw( 18 ) << setfill('0') << Fibonacci[ input ][ i ] ;
			}

			cout << endl ;
		}
	}

	return 0 ;
}
