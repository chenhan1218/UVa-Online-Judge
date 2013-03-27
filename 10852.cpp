#include <iostream>
using namespace std ;

#define MaxPrime 10000

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

int main()
{
	int		n = 0 ;
	int		x = 0 ;
	int		p = 0 ;
	int		subtract = 0 ;
	int		ansPrime = 0 ;
	int		m = 0 ;
	int		i = 0 ;
	
	cal( MaxPrime ) ;

	cin >> m ;
	for( i = 0 ; i < m ; i++ )
	{
		cin >> n ;
		subtract = 0 ;
		ansPrime = 0 ;
		for( x = 2 ; x <= n ; x = next[ x ] )
		{
			p = n / x ;
			if( subtract < n - p * x )
			{
				subtract = n - p * x ;
				ansPrime = x ;
			}
		}
		
		cout << ansPrime << endl ;
	}

	return 0 ;
}
