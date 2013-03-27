#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

#define MaxN 1000000

int			previous[ MaxN + 1 ] = { 0 } ;
int			next[ MaxN + 1 ] = { 0 } ;

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
	long long int	i = 0 ; // loop counter
	long long int	j = 0 ; // loop counter
	long long int	k = 0 ; // loop counter

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

int
main()
{
	long long int		n = 0 ;
	double	log10factorial[ MaxN + 1 ] = { 0 } ;
	long double	gcd = 0 ;
	long double	lcm = 0 ;
	long long int	prime = 0 ;
	long long int	power = 0 ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cal( MaxN ) ;
	log10factorial[ 1 ] = 0 ;

	for( i = 2 ; i <= MaxN ; i++ )
	{
		log10factorial[ i ] = log10factorial[ i - 1 ] + log10( i ) ;
	}

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}
		cases ++ ;

		gcd = 0 ;
		for( prime = 2 ; prime * 2 <= n ; prime = next[ prime ] )
		{
			power = prime ;
			while( n >= power )
			{
				gcd += ( n / (int)power )*( n / (int)power - 1 ) / 2 * log10( prime ) ;
				power *= prime ;
			}
		}

		lcm = log10factorial[ n ] * (n-1) - gcd ;

		cout << "Case " << cases << ": " << (long long int)(gcd/100)+1 
				<< " " << (long long int)(lcm/100)+1 << endl ;
	}

	return 0 ;
}
