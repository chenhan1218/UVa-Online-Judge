/* TLE version
#include <iostream>
using namespace std ;

#define MaxX 3000001
#define MaxPrime 3000001

int			previous[ MaxPrime + 1 ] = { 0 } ;
int			next[ MaxPrime + 1 ] = { 0 } ;

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

int	numFactorial( int n )
{
	int		ans = 0 ;
	int		prime = 0 ;
	int		temp = 0 ;
	int		i = 0 ;

	for( prime = 2 ; prime <= n ; prime = next[ prime ] )
	{
		temp = n ;
		while( temp >= prime )
		{
			temp /= prime ;
			ans += temp ;
		}
	}

	return ans ;
}

int main()
{
	int		n = 0 ;
	int		x = 0 ;
	int		prime = 0 ;
	int		cases = 0 ;
	int		lower = 0 ;
	int		upper = 0 ;
	int		temp = 0 ;
	int		i = 0 ;
	
	cal( MaxPrime ) ;
	
	while( cin >> n && n >= 0 )
	{
		cases++ ;
		lower = 0 ;
		upper = MaxX + 1 ;

		while( upper - lower > 1 )
		{
			if( numFactorial( (upper+lower) / 2 ) > n )
			{
				upper = (upper+lower) / 2 ;
			}
			else
			{
				lower = (upper+lower) / 2 ;
			}
		}
		
		if( numFactorial( lower ) == n )
		{
			cout << "Case " << cases << ": " << lower << "!" << endl ;
		}
		else
		{
			cout << "Case " << cases << ": Not possible." << endl ;
		}
	}
	
	return 0 ;
}
*/

#include <iostream>
using namespace std ;

#define MaxX 2703663
#define MaxPrime 3200

int			previous[ MaxPrime + 1 ] = { 0 } ;
int			next[ MaxPrime + 1 ] = { 0 } ;

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

int		numFactorial[ MaxX + 1 ] = { 0 } ;

int main()
{
	int		n = 0 ;
	int		x = 0 ;
	int		prime = 0 ;
	int		cases = 0 ;
	int		lower = 0 ;
	int		upper = 0 ;
	int		temp = 0 ;
	int		i = 0 ;
	
	cal( MaxPrime ) ;

	for( i = 2 ; i <= MaxX ; i++ )
	{
		for( prime = 2 ; prime * prime <= i ; prime = next[ prime ] )
		{
			if( i % prime == 0 )
				break ;
		}

		if( prime * prime <= i )
		{
			numFactorial[ i ] = numFactorial[ i / prime ] + numFactorial[ prime ] ;
		}
		else
		{
			numFactorial[ i ] = 1 ;
		}
	}

	for( i = 2 ; i <= MaxX ; i++ )
	{
		numFactorial[ i ] = numFactorial[ i - 1 ] + numFactorial[ i ] ;
	}

	while( cin >> n && n >= 0 )
	{
		cases++ ;

		x = lower_bound( numFactorial, numFactorial + MaxX + 1, n ) - numFactorial ;
		if( numFactorial[ x ] == n )
		{
			cout << "Case " << cases << ": " << x << "!" << endl ;
		}
		else
		{
			cout << "Case " << cases << ": Not possible." << endl ;
		}
	}
	
	return 0 ;
}

