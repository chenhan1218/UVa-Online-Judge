#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>
#define MaxRoute 601
#define MaxDays 301

int		K ;
int		N ;
int		dist[ MaxRoute + 2 ] = { 0 } ;
// sum[ i ][ j ] mean sum i numbers from dist[ j ].
int		sum[ MaxRoute + 2 ][ MaxRoute + 2 ] = { 0 } ;
// maxSingle[ i ][ j ] mean i days walking j dist.
int		maxSingle[ MaxDays + 2 ][ MaxRoute + 2 ] = { 0 } ;

int
main()
{
	int		routes = 0 ;
	int		days = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	while( cin >> K >> N )
	{
		routes = K + 1 ;
		days = N + 1 ;
		for( i = 1 ; i <= routes ; i++ )
		{
			cin >> dist[ i ] ;
			sum[ 1 ][ i ] = dist[ i ] ;
			maxSingle[ 1 ][ i ] = maxSingle[ 1 ][ i - 1 ] + dist[ i ] ;
		}

		for( i = 2 ; i <= routes ; i++ )
		{
			for( j = 1 ; j <= routes - i + 1 ; j++ )
			{
				sum[ i ][ j ] = sum[ i - 1 ][ j ] + dist[ j + i - 1 ] ;
			}
		}

		for( i = 2 ; i <= days ; i++ )
		{
			maxSingle[ i ][ i ] = *(max_element( &sum[ 1 ][ 1 ], &sum[ 1 ][ 1 ] + i )) ;
			for( j = i + 1 ; j <= routes - ( days - i ) ; j++ )
			{
				maxSingle[ i ][ j ] = max( maxSingle[ i - 1 ][ j - 1 ], sum[ 1 ][ j ] ) ;
				for( k = 2 ; k <= j - i + 1 ; k++ )
				{
					maxSingle[ i ][ j ] = min( maxSingle[ i ][ j ], 
						max( maxSingle[ i - 1 ][ j - k ], sum[ k ][ j - k + 1 ] ) ) ;
				}
			}
		}

		cout << maxSingle[ days ][ routes ] << endl ;
	}

	return 0 ;
}
