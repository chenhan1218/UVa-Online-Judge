#include <iostream>
#include <vector>
using namespace std ;

#define MaxPrime 65000

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

long long int	pow( long long int b, long long int p, long long int m )
{
	long long int	temp = 0 ;
	if( p == 0 )
	{
		return 1 ;
	}
	else if( p == 1 )
	{
		return b % m ;
	}
	else
	{
		temp = pow( b, p / 2, m ) ;
		if( p % 2 == 0 )
		{
			return ( temp * temp ) % m ;
		}
		else
		{
			return ( ( temp * temp ) % m * b ) % m ;
		}
	}
}

bool fermat_test( int n )
{
	int		a = 0 ;
	int		temp = 0 ;
	int		i = 0 ;
	for( a = 2 ; a <= n-1 ; a++ )
	{
		if( pow( a, n, n ) != a )
			return false ;
	}
	
	return true ;
}

int main()
{
	int		n = 0 ;
	int		i = 0 ;
	
	cin.sync_with_stdio( false ) ;
	cout.sync_with_stdio( false ) ;
	
	cal( MaxPrime ) ;
	
	while( cin >> n && n != 0 )
	{
		if( next[ n ] == 0 && fermat_test( n ) == true )
		{
			cout << "The number " << n << " is a Carmichael number." << endl ;
		}
		else
		{
			cout << n << " is normal." << endl ;
		}
	}
	
	return 0 ;
}
