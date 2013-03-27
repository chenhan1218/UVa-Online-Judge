#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

#define MaxPrime 1000000

int		previous[ MaxPrime + 1 ] = { 0 } ;
int		next[ MaxPrime + 1 ] = { 0 } ;
int		digitPrimes[ MaxPrime + 1 ] = { 0 } ;

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

long long int digit( long long int n )
{
	long long int	ans = 0 ;
	while( n > 0 )
	{
		ans += n % 10 ;
		n /= 10 ;
	}
	
	return ans ;
}

int main()
{
	int		n = 0 ;
	vector<int>	primeLst ;
	
	//cin.sync_with_stdio( false ) ;
	//cout.sync_with_stdio( false ) ;
	
	cal( MaxPrime ) ;
	
	for( int i = 1 ; i <= MaxPrime ; i++ )
	{
		digitPrimes[ i ] = digitPrimes[ i - 1 ] ;
		if( next[ i ] > 0 && next[ digit( i ) ] > 0 )
		{
			digitPrimes[ i ] ++ ;
		}
	}

	cin >> n ;
	while( n > 0 )
	{
		n-- ;
		
		int		t1 = 0 ;
		int		t2 = 0 ;
		scanf( "%d %d", &t1, &t2 ) ;
		printf( "%d\n", digitPrimes[ t2 ] - digitPrimes[ t1 - 1 ] ) ;
		/*
		cin >> t1 >> t2 ;
		
		cout << digitPrimes[ t2 ] - digitPrimes[ t1 - 1 ] << endl ;
		*/
	}

	return 0 ;
}
