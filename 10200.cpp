#include <iostream>
#include <iomanip>
using namespace std ;

#include <cmath>

#define Max_b 10000
#define allowAllocate 1230

class Prime
{
	public :
		Prime() ;
		long long int	value ;
		long long int	square ;
};

Prime::Prime()
{
	value = 0 ;
	square = 0 ;
}

Prime		*prime ;
int			numPrimes = 0 ;

void calculatePrime( long int upperLimit )
{
	int			numAllocate = 0 ;
	int			i = 0 ; // loop counter
	long long int j = 0 ; // loop counter
	int			k = 0 ; // loop counter

	numAllocate = allowAllocate ;
	prime = new Prime[ numAllocate + 1 ] ;

	prime[ 1 ].value = 2 ;
	prime[ 1 ].square = 4 ;
	prime[ 2 ].value = 3 ;
	prime[ 2 ].square = 9 ;
	numPrimes = 2 ;

	for( i = 3 ; prime[ i - 1 ].value < upperLimit && i <= numAllocate ; i++ )
	{
		// find next prime.
		for( j = prime[ i - 1 ].value + 2 ; j <= upperLimit ; j += 2 )
		{
			for( k = 1 ; prime[ k ].square < j ; k++ )
			{
				if( j % prime[ k ].value == 0 )
				{
					break ;
				}
			}

			if( prime[ k ].square > j )
			{
				numPrimes++ ;
				prime[ i ].value = j ;
				prime[ i ].square = j * j ;

				break ;
			}
		}

		if( j > upperLimit )
		{
			break ;
		}
	}
}

int main()
{
	int			a = 0 ;
	int			b = 0 ;
	long long	formula = 0 ;
	double		primeProduced[ Max_b + 1 ] = { 0 } ;
	int			i = 0 ;
	int			j = 0 ;

	calculatePrime( 10010 ) ;

	cout.setf( ios::fixed ) ;
	cout.precision( 2 ) ;

	formula = 41 ;
	primeProduced[ 0 ] = 1 ;
	for( i = 1 ; i <= Max_b ; i++ )
	{
		formula += i * 2 ;
		for( j = 1 ; prime[ j ].square < formula ; j++ )
		{
			if( formula % prime[ j ].value == 0 )
			{
				break ;
			}
		}

		if( prime[ j ].square > formula )
		{
			primeProduced[ i ] = primeProduced[ i - 1 ] + 1 ;
		}
		else
		{
			primeProduced[ i ] = primeProduced[ i - 1 ] ;
		}
	}

	while( cin >> a >> b )
	{
		if( a == 0 )
		{
			cout << primeProduced[ b ] * 100.0 / ( b - a + 1 ) + 0.001 << endl ;
		}
		else
		{
			cout << ( primeProduced[ b ] - primeProduced[ a - 1 ] ) * 100.0 
				/ ( b - a + 1 ) + 1.e-9 << endl ;
		}
	}

	return 0 ;
}
