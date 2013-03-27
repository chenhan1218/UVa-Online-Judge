#include <iostream>
#include <vector>
using namespace std ;

#define MaxN 16
#define MaxPrime 100

int			previous[ MaxPrime + 1 ] = { 0 } ;
int			next[ MaxPrime + 1 ] = { 0 } ;

vector<int>	v ;
vector<bool>	used ;

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

void recur( int index, int n )
{
	int		i = 0 ;
	if( index == n )
	{
		if( next[ v[ 0 ] + v[ n - 1 ] ] > 0 )
		{
			cout << v[ 0 ] ;
			for( i = 1 ; i < n ; i++ )
				cout << " " << v[ i ] ;
			cout << endl ;
		}
	}
	else
	{
		for( i = 1 ; i <= n ; i++ )
		{
			if( used[ i ] == false && ( next[ v[ index - 1 ] + i ] > 0 ) )
			{
				used[ i ] = true ;
				v[ index ] = i ;
				recur( index + 1, n ) ;
				used[ i ] = false ;
			}
		}
	}
}

int main()
{
	int		n = 0 ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	
	cal( MaxPrime ) ;
	
	while( cin >> n )
	{
		cases++ ;
		
		v.assign( n, 0 ) ;
		used.assign( n + 1, false ) ;
		v[ 0 ] = 1 ;
		used[ 1 ] = true ;

		if( cases != 1 )
			cout << endl ;
		cout << "Case " << cases << ":" << endl ;
		recur( 1, n ) ;
	}
	
	return 0 ;
}
