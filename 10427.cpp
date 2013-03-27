#include <iostream>
using namespace std ;

int main()
{
	long long int digit[ 10 ] = { 0 } ;
	digit[ 0 ] = 0 ;
	digit[ 1 ] = 9 ;
	for( int i = 2 ; i < 10 ; i++ )
	{
		digit[ i ] = digit[ i - 1 ] * 10 ;
	}
	for( int i = 1 ; i < 10 ; i++ )
	{
		digit[ i ] *= i ;
	}

	int N , digit_N , number ;

	while( cin >> N )
	{
		digit_N = 1 ;
		number = 1 ;
		while( N >= digit[ digit_N ] )
		{
			N -= digit[ digit_N ] ;
			digit_N++ ;
			number *= 10 ;
		}

		if( N == 0 )
		{
			cout << "9" << endl ;
		}
		else
		{
			number += N / digit_N ;
			N = N % digit_N ;

			if( N == 0 )
			{
				number-- ;

				cout << number % 10 << endl ;
			}
			else
			{
				while( N != digit_N )
				{
					number /= 10 ;
					N++ ;
				}

				cout << number % 10 << endl ;
			}
		}
	}

	return 0 ;
}
