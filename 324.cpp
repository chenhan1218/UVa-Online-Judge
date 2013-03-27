#include <iostream>
#include <iomanip>
using namespace std ;

/*
#include <fstream>
using std::ofstream ;

ofstream outfile( "324.txt" ) ;
*/

int main()
{
	long long digit16 = 100000000 ;
	digit16 *= digit16 ;

	long long int *Factorial[ 367 ] ;
	Factorial[ 0 ] = new long long int [ 1 ] ;
	Factorial[ 0 ][ 0 ] = 0 ;
	Factorial[ 1 ] = new long long int [ 1 ] ;
	Factorial[ 1 ][ 0 ] = 1 ;

	int number_longint = 1 ;

	for( int i = 2 ; i <= 366 ; i++ )
	{
		if( i % 7 == 0 )
		{
			number_longint++ ;

			Factorial[ i ] = new long long int [ number_longint ] ;

			for( int j = 0 ; j < number_longint - 1 ; j++ )
			{
				Factorial[ i ][ j ] = Factorial[ i - 1 ][ j ] * i ;
			}

			Factorial[ i ][ number_longint - 1 ] = 0 ;
			for( int j = 0 ; j < number_longint - 1 ; j++ )
			{
				if( Factorial[ i ][ j ] >= digit16 )
				{
					Factorial[ i ][ j + 1 ] += Factorial[ i ][ j ] / digit16 ;

					Factorial[ i ][ j ] = Factorial[ i ][ j ] % digit16 ;
				}
			}
		}
		else
		{
			Factorial[ i ] = new long long int [ number_longint ] ;

			for( int j = 0 ; j < number_longint ; j++ )
			{
				Factorial[ i ][ j ] = Factorial[ i - 1 ][ j ] * i ;
			}

			for( int j = 0 ; j < number_longint ; j++ )
			{
				if( Factorial[ i ][ j ] >= digit16 )
				{
					Factorial[ i ][ j + 1 ] += Factorial[ i ][ j ] / digit16 ;

					Factorial[ i ][ j ] = Factorial[ i ][ j ] % digit16 ;
				}
			}
		}
	}

/*
	for( int test = 1 ; test <= 366 ; test++ )
	{
		number_longint = test / 7 + 1 ;

		outfile << "The Factorial number for " << test << " is " ;

		int i = number_longint - 1 ;

		while( Factorial[ test ][ i ] == 0 )
		{
			i-- ;
		}

		outfile << Factorial[ test ][ i ] ;

		for( i = i - 1 ; i >= 0 ; i-- )
		{
			outfile << setw( 16 ) << setfill('0') << Factorial[ test ][ i ] ;
		}

		outfile << endl ;
	}
*/

	int digit_counts[ 367 ][ 10 ] = { 0 } ;

	for( int i = 1 ; i <= 366 ; i++ )
	{
		number_longint = i / 7 + 1 ;

		int j = number_longint - 1 ;

		while( Factorial[ i ][ j ] == 0 )
		{
			j-- ;
		}

		while( Factorial[ i ][ j ] != 0 )
		{
			digit_counts[ i ][ Factorial[ i ][ j ] % 10 ] ++ ;
			Factorial[ i ][ j ] /= 10 ;
		}

		for( j = j - 1 ; j >= 0 ; j-- )
		{
			for( int k = 0 ; k < 16 ; k++ )
			{
				digit_counts[ i ][ Factorial[ i ][ j ] % 10 ] ++ ;
				Factorial[ i ][ j ] /= 10 ;
			}
		}
	}

	int input ;

	while( cin >> input )
	{
		if( input == 0 )
		{
			break ;
		}
		else
		{
			number_longint = input / 80 + 1 ;

			cout << input << "! --" << endl ;

			for( int i = 0 ; i < 5 ; i++ )
			{
				cout << "   (" << i << ")" << setw( 5 ) << digit_counts[ input ][ i ] << " " ;
			}
			cout << endl ;
			for( int i = 5 ; i < 10 ; i++ )
			{
				cout << "   (" << i << ")" << setw( 5 ) << digit_counts[ input ][ i ] << " " ;
			}
			cout << endl ;
		}
	}

	return 0 ;
}
