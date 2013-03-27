#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int exponent_2[ 20 ] = { 0 } ;
	exponent_2[ 0 ] = 1 ;
	for( int i = 1 ; i < 20 ; i++ )
	{
		exponent_2[ i ] = exponent_2[ i - 1 ] * 2 ;
	}

	int n ;
	int i ;

	while( cin >> n )
	{
		if( n== 0 )
		{
			break ;
		}
		else if( n == 1 )
		{
			cout << "1" << endl ;
		}
		else
		{
			for( i = 1 ; i < 20 ; )
			{
				if( n > exponent_2[ i ] )
				{
					i++ ;
				}
				else if( n < exponent_2[ i ] )
				{
					n -= exponent_2[ i - 1 ] ;

					n *= 2 ;

					cout << n << endl ;

					break ;
				}
				else if( n == exponent_2[ i ] )
				{
					cout << n << endl ;

					break ;
				}
			}
		}
	}

	return 0 ;
}
