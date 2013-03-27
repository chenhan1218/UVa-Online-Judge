#include <iostream>
#include <algorithm>
using namespace std ;

#define MaxB 5000000
#define Max_n 5000000

int			previous[ Max_n + 1 ] = { 0 } ;
int			next[ Max_n + 1 ] = { 0 } ;
int			isDePrime[ MaxB + 1 ] = { 0 } ;

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
	int		a = 0 ;
	int		b = 0 ;
	int		sum = 0 ;
	int		temp = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	cal( MaxB ) ;
	
	for( i = 2 ; i <= Max_n ; i = next[ i ] )
	{
		for( j = i ; j <= MaxB ; j += i )
			isDePrime[ j ] += i ;
	}
	
	for( j = 2 ; j <= MaxB ; j++ )
	{
		if( next[ isDePrime[ j ] ] == 0 )
			isDePrime[ j ] = 0 ;
		else
			isDePrime[ j ] = 1 ;
	}
	
	while( cin >> a >> b )
	{
		cout << count( &isDePrime[ a ], &isDePrime[ b ] + 1, 1 ) << endl ;
	}
	
	return 0 ;
}
