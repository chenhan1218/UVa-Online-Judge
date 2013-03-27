#include <iostream>
#include <iomanip>
using namespace std ;

#include <cmath>

#define Max_n 32768

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
	int				pairs[ Max_n + 1 ] = { 0 } ;
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

	// calculate Goldbach's Conjecture pairs.
	pairs[ 4 ] = 1 ;
	for( prime = 3 ; prime <= Max_n ; prime = next[ prime ] )
	{
		for( i = 3 ; i <= prime && i <= Max_n - prime ; i = next[ i ] )
		{
			pairs[ prime + i ] += 1 ;
		}
	}

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}

		cout << pairs[ n ] << endl ;
	}

	return 0 ;
}
