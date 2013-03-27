#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

#define MaxPrime 5000000
#define MaxN 10000000

vector<long long int>	aop ;
vector<long long int>	abunAop ;
long long int		sigma[ MaxN + 1 ] = { 0 } ;

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
	long long int		prime = 0 ;
	int		n = 0 ;
	int		i = 0 ;

	cal( MaxPrime ) ;

	for( prime = 3 ; (prime<<1) <= MaxN ; prime = next[ prime ] )
	{
		for( i = 1 ; (prime<<i) <= MaxN ; i++ )
		{
			aop.push_back( prime<<i ) ;
			sigma[ (prime<<i) ] = (1<<(i+1)) - ( prime + 1 ) ;
		}
	}

	sort( aop.begin(), aop.end() ) ;
	abunAop.push_back( sigma[ aop[ 0 ] ] ) ;
	for( i = 1 ; i < aop.size() ; i++ )
	{
		abunAop.push_back( abunAop.back() + sigma[ aop[ i ] ] ) ;
	}

	while( cin >> n && n != 0 )
	{
		if( n < aop[ 0 ] )
		{
			cout << n << " " << 0 << endl ;
		}
		else
		{
			cout << n << " " << abunAop[ upper_bound( aop.begin(), aop.end(), n ) - aop.begin() - 1 ] << endl ;
		}
	}

	return 0 ;
}

/* TLE version
#include <iostream>
using namespace std ;

#define MaxPrime 10000000

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

long long int abun( long long int n )
{
	long long int		ans = 0 ;
	long long int		prime = 0 ;
	long long int		sigma = 0 ;
	long long int		sigmaBase = 0 ;
	int		i = 0 ;

	for( prime = 3 ; prime <= n ; prime = next[ prime ] )
	{
		for( i = 1 ; (prime<<i) <= n ; i++ )
		{
			ans += (1<<(i+1)) - ( prime + 1 ) ;
		}
	}

	return ans ;
}

int main()
{
	int		n = 0 ;
	int		i = 0 ;

	cal( MaxPrime ) ;

	while( cin >> n && n != 0 )
	{
		cout << n << " " << abun( n ) << endl ;
	}

	return 0 ;
}
*/

