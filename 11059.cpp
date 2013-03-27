#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxN 18

// product[ i ][ j ] means product from s[ i ] to s[ j ].
long long	product[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;

/*
long long max( long long *start, long long *end )
{
	if( start == end )
	{
		return 0 ;
	}

	long long maximum = *start ;
	for( start += 1, start < end ; start++ )
	{
		if( *start > maximum )
		{
			maximum = *start ;
		}
	}

	return maximum ;
}
*/

int
main()
{
	int		N = 0 ;
	long long	P = 0 ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> N )
	{
		cases++ ;

		for( i = 1 ; i <= N ; i++ )
		{
			cin >> product[ i ][ i ] ;
		}

		P = 0 ;
		for( i = 1 ; i <= N ; i++ )
		{
			P = max( P, product[ i ][ i ] ) ;
		}

		for( i = 2 ; i <= N ; i++ )
		{
			for( j = 1 ; j <= N - i + 1 ; j++ )
			{
				product[ j ][ j + i - 1 ] = product[ j + 1 ][ j + i - 1 ] * 
					product[ j ][ j ] ;

				P = max( P, product[ j ][ j + i - 1 ] ) ;
			}
		}

		cout << "Case #" << cases << ": The maximum product is " << P << "." << endl ;
		// After each test case you must print a blank line.
		cout << endl ;
	}

	return 0 ;
}
