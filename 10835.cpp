// The code is so ugly.....orz

#include <iostream>
#include <iomanip>
using namespace std ;

#include <numeric>
#include <string>

#define MaxN 50
#define MaxK 50
#define MaxLen 10

long long int*	numhead = new long long int [ 1024 ] ;
long long int*	recursiveSum = new long long int [ 1024 ] ;
long long int*	subPattern = new long long int [ MaxK + 1 ] ;

void reduced( long long int &a, long long int &b )
{
	long long i = a, j = b, gcd = 0 ;
	if( i < j )
	{
		swap( i, j ) ;
	}
	while( i != 0 && j != 0 )
	{
		i %= j ;
		swap( i, j ) ;
	}
	gcd = i + j ;

	a /= gcd ;
	b /= gcd ;
}

int
main()
{
	int		N = 0 ;
	int		K = 0 ;
	int		len = 0 ;
	long long int	pow2s[ MaxN + 1 ] = { 0 } ;
	long long int	numerator = 0 ;
	long long int	denominator = 0 ;
	int		cases = 0 ;
	string	buffer ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	pow2s[ 0 ] = 1 ;
	for( i = 1 ; i <= MaxN ; i++ )
	{
		pow2s[ i ] = pow2s[ i - 1 ] * 2 ;
	}

	while( cin >> N >> K )
	{
		if( N == 0 && K == 0 )
		{
			break ;
		}
		cases++ ;

		for( i = 1 ; i <= K ; i++ )
		{
			cin >> buffer ;

			subPattern[ i ] = 0 ;
			for( j = 0 ; buffer[ j ] != '\0' ; j++ )
			{
				subPattern[ i ] *= 2 ;
				if( buffer[ j ] == 'H' )
				{
					subPattern[ i ] ++ ;
				}
			}
		}

		if( ( len = buffer.length() ) > N )
		{
			cout << "Case " << cases << ": " << "1/1" << endl ;
		}
		else
		{
			for( j = 0 ; j < pow2s[ len ] ; j++ )
			{
				if( find( subPattern + 1, subPattern + K + 1, j ) == subPattern + K + 1 )
				{
					numhead[ j ] = 1 ;
				}
				else
				{
					numhead[ j ] = 0 ;
				}
			}

			for( i = len + 1 ; i <= N ; i++ )
			{
				for( j = 0 ; j < pow2s[ len ] ; j++ )
				{
					if( find( subPattern + 1, subPattern + K + 1, j ) == subPattern + K + 1 )
					{
						recursiveSum[ j ] = numhead[ j % pow2s[ len - 1 ] * 2 ] + 
											numhead[ j % pow2s[ len - 1 ] * 2 + 1 ] ;
					}
					else
					{
						recursiveSum[ j ] = 0 ;
					}
				}

				swap( numhead, recursiveSum ) ;
			}

			// Here is a trap, we should sent (long long int)0 into accumulate,
			// instead of 0 only.
			numerator = accumulate( numhead, numhead + pow2s[ len ], (long long int )0 ) ;
			denominator = pow2s[ N ] ;
			if( numerator == 0 )
			{
				cout << "Case " << cases << ": " << 0 << endl ;
			}
			else
			{
				reduced( numerator, denominator ) ;
				cout << "Case " << cases << ": " << numerator << "/"
						<< denominator << endl ;
			}
		}
	}

	return 0 ;
}
