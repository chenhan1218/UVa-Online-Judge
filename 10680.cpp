#include <iostream>
using namespace std ;

const int MaxPrime = 1000000 ;
const int MaxN = 1000000 ;
int		digit[ MaxN + 1 ] = { 0 } ;
int		primeFactor[ MaxN + 1 ] = { 0 } ;

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

bool isPowPrime( int n, int &prime )
{
	int		temp = 0 ;
	for( prime = 2 ; prime <= n ; prime = next[ prime ] )
	{
		temp = n ;
		while( temp % prime == 0 )
			temp /= prime ;
		
		if( temp == 1 )
			return true ;
	}
	
	return false ;
}

int main()
{
	long long int	n = 0 ;
	long long int	prime = 0 ;
	long long int	temp = 0 ;
	int		i = 0 ;
	
	cal( MaxPrime ) ;
	for( prime = 2 ; prime <= MaxN ; prime = next[ prime ] )
	{
		temp = prime ;
		while( temp <= MaxN )
		{
			primeFactor[ temp ] = prime ;
			temp *= prime ;
		}
	}
	
	digit[ 1 ] = 1 ;
	for( i = 2 ; i <= MaxN ; i++ )
	{
		if( primeFactor[ i ] != 0 )
		{
			digit[ i ] = digit[ i - 1 ] * primeFactor[ i ] ;
			if( digit[ i ] % 10 == 0 )
				digit[ i ] /= 10 ;
			
			digit[ i ] %= 100 ;
		}
		else
		{
			digit[ i ] = digit[ i - 1 ] ;
		}
	}
	
	while( cin >> n && n != 0 )
	{
		cout << digit[ n ] % 10 << endl ;
	}
	
	return 0 ;
}
