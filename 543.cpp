#include <iostream>
#include <iomanip>
using namespace std ;

#include <cmath>

#define Max_n 1000010

int			previous[ Max_n + 1 ] ;
int			next[ Max_n + 1 ] ;

void initial( long long int n )
{
	long long int	i = 0 ; // loop counter

	previous[ 2 ] = 0 ;
	next[ 2 ] = 3 ;
	previous[ 3 ] = 2 ;
	next[ 3 ] = 5 ;
	for( i = 5 ; i <= n ; i += 2 )
	{
		previous[ i ] = i - 2 ;
		next[ i ] = i + 2 ;
	}
	next[ i - 2 ] = 0 ;

	for( i = 4 ; i <= n ; i+= 2 )
	{
		previous[ i ] = 0 ;
		next[ i ] = 0 ;
	}
}

void remove( int x )
{
	next[ previous[ x ] ] = next[ x ] ;
	previous[ next[ x ] ] = previous[ x ] ;

	previous[ x ] = 0 ;
	next[ x ] = 0 ;
}

int main()
{
	long long int	n = 0 ;
	long long int	numPrimes = 0 ;
	long long int	prime = 0 ;
	long long int	fact = 0 ;
	long long int	mult = 0 ;
	long long int	i = 0 ; // loop counter
	long long int	j = 0 ; // loop counter
	long long int	k = 0 ; // loop counter

	initial( Max_n ) ;

	// Start to calculate prime.
	for( prime = 3 ; prime * prime <= Max_n ; prime = next[ prime ] )
	{
		for( fact = prime ; prime * fact <= Max_n ; fact = next[ fact ] )
		{
			for( mult = prime * fact ; mult <= Max_n ; mult *= prime )
			{
				remove( mult ) ;
			}
		}
	}

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}

		for( i = 3 ; i <= n / 2 ; i = next[ i ] )
		{
			j = n - i ;
			if( next[ j ] != 0 )
			{
				break ;
			}
		}

		if( i > n / 2 )
		{
			// If there is no such pair, print a line saying ``Goldbach's conjecture is wrong."
			cout << "Goldbach's conjecture is wrong." << endl ;
		}
		else
		{
			cout << n << " = " << i << " + " << j << endl ;
		}
	}

	return 0 ;
}
