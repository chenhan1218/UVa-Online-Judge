#include <iostream>
#include <iomanip>
#include <vector>
using namespace std ;

#define MaxM 5000

int			previous[ MaxM + 1 ] = { 0 } ;
int			next[ MaxM + 1 ] = { 0 } ;

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
	int		m = 0 ;
	int		n = 0 ;
	int		t = 0 ;
	int		prime = 0 ;
	int		power = 0 ;
	int		powOfPrime = 0 ;
	int		numFactor = 0 ;
	vector<int>	possibleM ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter

	cal( MaxM ) ;

	cin >> t ;
	for( cases = 1 ; cases <= t ; cases++ )
	{
		cin >> m >> n ;

		prime = 2 ;
		possibleM.clear() ;
		while( m != 1 )
		{
			if( m % prime == 0 )
			{
				m /= prime ;
				power = 1 ;
				while( m % prime == 0 ) // find power of prime in m
				{
					m /= prime ;
					power++ ;
				}

				powOfPrime = prime ;
				numFactor = 0 ;
				while( powOfPrime <= n ) // find number of prime in n
				{
					numFactor += n / powOfPrime ;
					powOfPrime *= prime ;
				}

				possibleM.push_back( numFactor / power ) ; // set possible value of answer
			}

			prime = next[ prime ] ;
		}

		cout << "Case " << cases << ":" << endl ;
		// if m divides n! or a line "Impossible to divide" (without the quotes).
		if( *min_element( possibleM.begin(), possibleM.end() ) == 0 )
			cout << "Impossible to divide" << endl ;
		else
			cout << *min_element( possibleM.begin(), possibleM.end() ) << endl ;
	}

	return 0 ;
}
