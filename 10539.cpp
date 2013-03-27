#include <iostream>
using namespace std ;

#define MaxPrime 1000000

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
	long long int	n = 0 ;
	long long int	low = 0 ;
	long long int	high = 0 ;
	long long int	prime = 0 ;
	long long int	powPrime = 0 ;
	int		numAlmostPrime = 0 ;
	int		i = 0 ;

	cal( MaxPrime ) ;

	cin >> n ;
	for( i = 0 ; i < n ; i++ )
	{
		cin >> low >> high ;
		
		numAlmostPrime = 0 ;
		for( prime = 2 ; prime * prime <= high ; prime = next[ prime ] )
		{
			powPrime = prime * prime ;
			while( powPrime <= high )
			{
				if( powPrime >= low )
				{
					numAlmostPrime++ ;
				}
				
				powPrime *= prime ;
			}
		}
		
		cout << numAlmostPrime << endl ;
	}

	return 0 ;
}
