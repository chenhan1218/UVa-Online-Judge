#include <iostream>
#include <iomanip>
using namespace std ;

#define Max_n 500100

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
	next[ i - 2 ] = -1 ;
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
	long long int	n = Max_n ;
	long long int	numPrimes = 0 ;
	long long int	prime = 0 ;
	long long int	fact = 0 ;
	long long int	mult = 0 ;
	long long int	i = 0 ; // loop counter
	long long int	j = 0 ; // loop counter
	long long int	k = 0 ; // loop counter
	int		sopf[ Max_n + 1 ] = { 0 } ;
	int		lsopf[ Max_n + 1 ] = { 0 } ;
	int		T = 0 ;
	int		N = 0 ;
	int		M = 0 ;

	initial( n ) ;

	for( prime = 3 ; prime > 0 ; prime = next[ prime ] )
	{
		for( fact = prime ; prime * fact <= n ; fact = next[ fact ] )
		{
			for( mult = prime * fact ; mult <= n ; mult *= prime )
			{
				remove( mult ) ;
			}
		}
	}

	for( i = 2 ; i <= Max_n ; i++ )
	{
		// find first prime factor of i
		for( prime = 2 ; prime * prime <= i ; prime = next[ prime ] )
		{
			if( i % prime == 0 )
			{
				break ;
			}
		}

		if( prime * prime <= i ) // if we find first prime factor of i.
		{
			sopf[ i ] = sopf[ i / prime ] + prime ;
			if( sopf[ i ] == i )
			{
				lsopf[ i ] = 1 ;
			}
			else
			{
				lsopf[ i ] = lsopf[ sopf[ i ] ] + 1 ;
			}
		}
		else // if i is a prime.
		{
			sopf[ i ] = i ;
			lsopf[ i ] = 1 ;
		}
	}

	cin >> T ;
	for( i = 1 ; i <= T ; i++ )
	{
		cin >> N >> M ;
		if( N > M )
		{
			swap( N, M ) ;
		}

		cout << "Case #" << i << ":" << endl ;
		cout << *( max_element( lsopf + N, lsopf + M + 1 ) ) << endl ;
	}

	return 0 ;
}

