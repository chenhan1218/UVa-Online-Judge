#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

const int MaxPrime = 50000 ;

int			previous[ MaxPrime + 1 ] = { 0 } ;
int			next[ MaxPrime + 1 ] = { 0 } ;
bool		sieveBuffer[ 1000000 + 1 ] = { 0 } ;
bool		*sieve = 0 ;
long long int	l = 0 ;
long long int	u = 0 ;

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
	cal( MaxPrime ) ;
	
	while( cin >> l >> u )
	{
		vector<int>		v ;
		sieve = sieveBuffer - l ;
		fill( sieve+l, sieve+u+1, true ) ;
		if( l <= 1 )
			sieve[ 1 ] = false ;
		
		for( long long int prime = 2 ; prime*prime <= u ; prime = next[ prime ] )
		{
			for( long long int loop = max( prime*2, ((l+prime-1)/prime)*prime ) ; loop <= u ; loop+=prime )
			{
				sieve[ loop ] = false ;
			}
		}
		
		for( long long int loop = l ; loop <= u ; loop++ )
			if( sieve[ loop ] == true )
				v.push_back( loop ) ;
		
		if( v.size() < 2 )
		{
			cout << "There are no adjacent primes." << endl ;
		}
		else
		{
			long long int	c1 = v[ 0 ] ;
			long long int	c2 = v[ 1 ] ;
			long long int	d1 = v[ 0 ] ;
			long long int	d2 = v[ 1 ] ;
			
			for( long long int i = 1 ; i+1 < v.size() ; i++ )
			{
				if( v[ i + 1 ] - v[ i ] < c2 - c1 )
				{
					c1 = v[ i ] ;
					c2 = v[ i + 1 ] ;
				}
				if( v[ i + 1 ] - v[ i ] > d2 - d1 )
				{
					d1 = v[ i ] ;
					d2 = v[ i + 1 ] ;
				}
			}
			
			cout 	<< c1 << "," << c2 << " are closest, " 
					<< d1 << "," << d2 << " are most distant." << endl ;
		}
	}

	return 0 ;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

const int MaxPrime = 50000 ;

int			previous[ MaxPrime + 1 ] = { 0 } ;
int			next[ MaxPrime + 1 ] = { 0 } ;
bool		sieveBuffer[ 1000000 + 1 ] = { 0 } ;
bool		*sieve = 0 ;
long long int	l = 0 ;
long long int	u = 0 ;

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

void dfs( long long int value, long long int p )
{
	if( value <= u )
	{
		cout << value << endl ;
		if( value >= l && !(value <= MaxPrime && next[ value ] != 0) )
			sieve[ value ] = false ;
		
		for( long long int prime = p ; prime <= u/value && prime <= MaxPrime ; prime = next[ prime ] )
		{
			dfs( value * prime, prime ) ;
		}
	}
}

int main( int argc, char *argv[] )
{
	long long int	prime = 0 ;
	vector<int>		v ;
	vector<int>::iterator	iter ;
	long long int	c1 = 0 ;
	long long int	c2 = 0 ;
	long long int	d1 = 0 ;
	long long int	d2 = 0 ;
	long long int	i = 0 ; // loop counter

	cal( MaxPrime ) ;
	
	while( cin >> l >> u )
	{
		sieve = sieveBuffer - l ;
		fill( sieve + l, sieve + u + 1, true ) ; // set sieve[ l ] to sieve[ u ] to true ;
		
		dfs( 1, 2 ) ;
		
		v.clear() ;
		for( long long int loop = l ; loop <= u ; loop++ )
			if( sieve[ loop ] == true )
				v.push_back( loop ) ;
		
		if( v.size() < 2 )
		{
			cout << "There are no adjacent primes." << endl ;
		}
		else
		{
			c1 = v[ 0 ] ;
			c2 = v[ 1 ] ;
			d1 = v[ 0 ] ;
			d2 = v[ 1 ] ;
			
			for( i = 1 ; i+1 < v.size() ; i++ )
			{
				if( v[ i + 1 ] - v[ i ] < c2 - c1 )
				{
					c1 = v[ i ] ;
					c2 = v[ i + 1 ] ;
				}
				if( v[ i + 1 ] - v[ i ] > d2 - d1 )
				{
					d1 = v[ i ] ;
					d2 = v[ i + 1 ] ;
				}
			}
			
			cout 	<< c1 << "," << c2 << " are closest, " 
					<< d1 << "," << d2 << " are most distant." << endl ;
		}
	}

	return 0 ;
}
*/

/* TLE version
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

const int MaxPrime = 1000000 ;
const int MaxU = 2147483647 ;

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
	long long int	l = 0 ;
	long long int	u = 0 ;
	long long int	prime = 0 ;
	vector<int>		v ;
	vector<int>::iterator	iter ;
	long long int	c1 = 0 ;
	long long int	c2 = 0 ;
	long long int	d1 = 0 ;
	long long int	d2 = 0 ;
	long long int	i = 0 ; // loop counter

	cal( MaxPrime ) ;

	for( prime = 2 ; prime <= MaxPrime ; prime = next[ prime ] )
	{
		v.push_back( prime ) ;
	}
	
	for( i = MaxPrime + 1 ; i <= MaxU ; i++ )
	{
		// test if i is a prime number 
		for( prime = 2 ; prime * prime <= i ; prime = next[ prime ] )
		{
			if( i % prime == 0 )
				break ;
		}
		
		if( prime * prime > i ) // i is a prime number
		{
			v.push_back( i ) ;
		}
	}
	
	while( cin >> l >> u )
	{
		iter = lower_bound( v.begin(), v.end(), l ) ;
		if( v.end() - iter < 2 || *(iter+1) > u )
		{
			cout << "There are no adjacent primes." << endl ;
		}
		else
		{
			c1 = *iter ;
			c2 = *(iter+1) ;
			d1 = *iter ;
			d2 = *(iter+1) ;
			
			for( iter++ ; v.end() - iter >= 2 && *(iter+1) <= u ; iter++ )
			{
				if( *(iter+1) - *iter < c2 - c1 )
				{
					c1 = *iter ;
					c2 = *(iter+1) ;
				}
				if( *(iter+1) - *iter > d2 - d1 )
				{
					d1 = *iter ;
					d2 = *(iter+1) ;
				}
			}
			
			cout 	<< c1 << "," << c2 << " are closest, " 
					<< d1 << "," << d2 << " are most distant." << endl ;
		}
	}

	return 0 ;
}
*/
