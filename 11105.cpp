#include <iostream>
#include <iomanip>
using namespace std ;

#include <cmath>

#define TRUE 1
#define FALSE 0
#define Max_n 1001000

int			previous[ Max_n + 1 ] = { 0 } ;
int			next[ Max_n + 1 ] = { 0 } ;
bool		isSemiPrime[ Max_n + 1 ] = { 0 } ;
int			semiPrimes[ Max_n + 1 ] = { 0 } ;

void initial( long long int n )
{
	long long	previousNumber = 0 ;
	long long	nextNumber = 0 ;
	long long	i = 0 ; // loop counter

	previous[ 5 ] = 0 ;
	next[ 5 ] = 9 ;

	for( i = 9, previousNumber = i - 4 , nextNumber = i + 4 ; i <= n ; 
		i += 4, previousNumber += 4, nextNumber += 4 )
	{
		previous[ i ] = previousNumber ;
		next[ i ] = nextNumber ;
	}
	next[ i - 4 ] = 0 ;
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
	long long 		h = 0 ;
	long long int	i = 0 ; // loop counter
	long long int	j = 0 ; // loop counter
	long long int	k = 0 ; // loop counter

	n = Max_n ;

	initial( n ) ;

	// Determine which numbers are primes.
	for( prime = 5 ; prime * prime <= n ; prime = next[ prime ] )
	{
		for( fact = prime ; prime * fact <= n ; fact = next[ fact ] )
		{
			for( mult = prime * fact ; mult <= n ; mult *= prime )
			{
				remove( mult ) ;
			}
		}
	}

	// Now determine which numbers are H-semi-primes.
	for( prime = 5 ; prime * prime <= n ; prime = next[ prime ] )
	{
		for( fact = prime ; ( mult = prime * fact ) <= n ; fact = next[ fact ] )
		{
			// Now mult is a H-semi-primes.
			isSemiPrime[ mult ] = TRUE ;
		}
	}

	semiPrimes[ 1 ] = 0 ;
	for( i = 5 ; i <= n ; i += 4 )
	{
		if( isSemiPrime[ i ] == TRUE )
		{
			semiPrimes[ i ] = semiPrimes[ i - 4 ] + 1 ;
		}
		else
		{
			semiPrimes[ i ] = semiPrimes[ i - 4 ] ;
		}
	}

	while( cin >> h )
	{
		if( h == 0 )
		{
			break ;
		}

		cout << h << " " << semiPrimes[ h ] << endl ;
	}

	return 0 ;
}
