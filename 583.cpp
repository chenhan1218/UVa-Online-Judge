#include <iostream>
#include <vector>
using namespace std ;

#define MaxPrime 50000

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

vector<int> factorList( long long int n )
{
	vector<int>	factor ;
	int		prime = 0 ;

	if( n < 0 )
	{
		n /= -1 ;
		factor.push_back( -1 ) ;
	}

	for( prime = 2 ; prime <= MaxPrime && n != 1 ; prime = next[ prime ] )
	{
		while( n % prime == 0 )
		{
			n /= prime ;
			factor.push_back( prime ) ;
		}
	}

	if( n != 1 )
		factor.push_back( n ) ;

	return factor ;
}

int main()
{
	int		g = 0 ;
	vector<int>	factor ;
	int		i = 0 ;

	cin.sync_with_stdio( false ) ;
	cout.sync_with_stdio( false ) ;

	cal( MaxPrime ) ;

	while( cin >> g && g != 0 )
	{
		factor = factorList( g ) ;

		cout << g << " =" ;
		cout << " " << factor[ 0 ] ;
		for( i = 1 ; i < factor.size() ; i++ )
		{
			cout << " x " << factor[ i ] ;
		}
		cout << endl ;
	}

	return 0 ;
}

