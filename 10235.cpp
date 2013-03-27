#include <iostream>
#include <iomanip>
using namespace std ;

#define Max_n 1000000

int			previous[ Max_n + 1 ] = { 0 } ;
int			next[ Max_n + 1 ] = { 0 } ;

void initial( long long int n )
{
	long long int	i = 0 ; // loop counter

	previous[ 2 ] = -1 ;
	next[ 2 ] = 3 ;
	previous[ 3 ] = 2 ;
	next[ 3 ] = 5 ;
	for( i = 3 ; i <= n ; i += 2 )
	{
		previous[ i ] = i - 2 ;
		next[ i ] = i + 2 ;
	}
}

void remove( int x )
{
	next[ previous[ x ] ] = next[ x ] ;
	previous[ next[ x ] ] = previous[ x ] ;

	previous[ x ] = 0 ;
	next[ x ] = 0 ;
}

void cal( long long int n )
{
	long long int	numPrimes = 0 ;
	long long int	prime = 0 ;
	long long int	fact = 0 ;
	long long int	mult = 0 ;

	initial( n ) ;

	for( prime = 3 ; prime * prime <= n ; prime = next[ prime ] )
	{
		for( fact = prime ; prime * fact <= n ; fact = next[ fact ] )
		{
			for( mult = prime * fact ; mult <= n ; mult *= prime )
			{
				remove( mult ) ;
			}
		}
	}
}

long long int reverse( int n )
{
	long long int value = 0 ;
	value = n % 10 ;

	while( n >= 10 )
	{
		n /= 10 ;
		value = value * 10 + n % 10 ;
	}

	return value ;
}

int
main()
{
	int		n = 0 ;
	int		reverseN = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cal( Max_n ) ;

	while( cin >> n )
	{
		reverseN = reverse( n ) ;

		if( next[ n ] != 0 )
		{
			if( n != reverseN && next[ reverseN ] != 0 )
			{
				cout << n << " is emirp." << endl ;
			}
			else
			{
				cout << n << " is prime." << endl ;
			}
		}
		else
		{
			cout << n << " is not prime." << endl ;
		}
	}

	return 0 ;
}
