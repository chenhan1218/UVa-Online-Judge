/*
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
1 2 3 4 5 6 
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 8 
1 2 3 4 5 6 7 8 9 
1 2 3 4 5 6 7 8 9 10 
1 2 3 4 5 6 7 8 9 10 11 
1 2 3 4 5 6 7 8 9 10 11 12 
1 2 3 4 5 6 7 8 9 10 11 12 13 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
*/
#include <iostream>
#include <iomanip>
using namespace std ;

#define Max_n 100000

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

int maxPrimeDivisor( int b )
{
	int		i = 2 ;
	while( next[ b ] == 0 )
	{
		while( b % i != 0 )
		{
			i = next[ i ] ;
		}

		b /= i ;
		i = next[ i ] ;
	}

	return b ;
}

int main()
{
	unsigned long long int n = 0 ;
	unsigned long long int powOfP = 0 ;
	unsigned long long int ans = 0 ;
	long long int b = 0 ;
	long long int p = 0 ;
	int		i = 0 ;

	cal( Max_n ) ;

	while( cin >> n >> b )
	{
		if( n == 0 && b == 0 )
			break ;

		p = maxPrimeDivisor( b ) ;

		ans = 0 ;
		powOfP = p ;
		while( powOfP <= n )
		{
			ans += ( ( n - powOfP + 1 ) + ( n % powOfP + 1 ) ) * ( n / powOfP ) / 2 ;
			powOfP *= p ;
		}

		cout << ans << endl ;
	}

	return 0 ;
}


