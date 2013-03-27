#include <iostream>
#include <vector>
using namespace std ;

#define MaxPrime 40000

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

int main( int argc, char *argv[] )
{
	int		i = 0 ;
	long long int	n = 0 ;
	long long int	temp = 0 ;
	long long int	prime = 0 ;
	vector<long long int>	primeFactor ;
	
	cal( MaxPrime ) ;

	while( cin >> n && n != 0 )
	{
		if( n == 1 ) // special case
		{
			cout << 0 << endl ;
			continue ;
		}
		
		temp = n ;
		primeFactor.clear() ;
		for( prime = 2 ; prime * prime <= temp ; prime = next[ prime ] )
		{
			if( temp % prime == 0 )
			{
				primeFactor.push_back( prime ) ;
				do
				{
					temp /= prime ;
				} while( temp % prime == 0 ) ;
			}
		}
		
		if( temp != 1 )
		{
			primeFactor.push_back( temp ) ;
		}
		
		for( i = 0 ; i < primeFactor.size() ; i++ )
		{
			n = n / primeFactor[ i ] * ( primeFactor[ i ] - 1 ) ;
		}
		
		cout << n << endl ;
	}

	return 0 ;
}
