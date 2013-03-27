#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std ;
#define MaxN 100

int		subColumn[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;

int maxConInSeries( int *begin, int *end )
{
	int		maxSum = 0 ;
	int		sum = 0 ;
	int*	ptr ;

	maxSum = *(max_element( begin, end )) ;\
	for( ptr = begin ; ptr < end ; ptr++ )
	{
		if( *ptr >= 0 )
		{
			if( sum < 0 )
			{
				sum = *ptr ;
			}
			else
			{
				sum += *ptr ;
			}
		}
		else
		{
			sum += *ptr ;
		}

		maxSum = max( maxSum, sum ) ;
	}

	return maxSum ;
}

int
main()
{
	int		n = 0 ;
	int		maxSum = 0 ;
	int		row = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	while( cin >> n )
	{
		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
			{
				cin >> subColumn[ i ][ j ] ;
			}

			if( i == 1 )
			{
				maxSum = *(max_element( &subColumn[ i ][ 1 ], &subColumn[ i ][ 1 ] + n )) ;
			}
			else
			{
				maxSum = max( maxSum, 
				*(max_element( &subColumn[ i ][ 1 ], &subColumn[ i ][ 1 ] + n )) ) ;
			}
		}

		for( i = 1 ; i <= n ; i++ )
		{
			for( j = i + 1 ; j <= n ; j++ )
			{
				for( k = 1 ; k <= n ; k++ )
				{
					subColumn[ i ][ k ] += subColumn[ j ][ k ] ;
				}

				maxSum = max( maxSum, 
			maxConInSeries( &subColumn[ i ][ 1 ], &subColumn[ i ][ 1 ] + n ) ) ;
			}
		}

		cout << maxSum << endl ;
	}

	return  0 ;
}

