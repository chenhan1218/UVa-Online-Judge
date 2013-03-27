#include <iostream>
using namespace std ;

#define MaxPrime 32000

int			previous[ MaxPrime + 1 ] = { 0 } ;
int			next[ MaxPrime + 1 ] = { 0 } ;

void initial( long long int n )
{
	long long int	i = 0 ; // loop counter

	previous[ 2 ] = 0 ;
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

bool isPrime( int n )
{
	if( n < 0 || n > MaxPrime )
		return false ;
	else
		return next[ n ] > 0 ;
}

int main( int argc, char *argv[] )
{
	int		x = 0 ;
	int		y = 0 ;

	cal( MaxPrime ) ;

	while( cin >> x >> y )
	{
		if( x == 0 && y == 0 )
			break ;
		
		if( x > y )
			swap( x, y ) ;
		
		for( int prime = 2 ; next[ prime ] <= y ; )
		{
			int	lastPrime = next[ prime ] ;
			while( next[ lastPrime ] <= MaxPrime && 
				next[ lastPrime ] - lastPrime == next[ prime ] - prime )
			{
				lastPrime = next[ lastPrime ] ;
			}
			
			if( lastPrime != next[ prime ] )
			{
				if( prime >= x && lastPrime <= y )
				{
					cout << prime ;
					for( int i = next[ prime ] ; i <= lastPrime ; i = next[ i ] )
						cout << " " << i ;
					cout << endl ;
				}
				
				prime = lastPrime ;
			}
			else
			{
				prime = next[ prime ] ;
			}
		}
	}

	return 0 ;
}
