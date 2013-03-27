#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>
#define MaxN 20

int		d[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;

int	findLCS( int **a, int **b, int lenA, int lenB )
{
	int	i = 0 ;
	int j = 0 ;

	for( i = 1 ; i <= lenA ; i++ )
	{
		for( j = 1 ; j <= lenB ; j++ )
		{
			if( a[ i - 1 ][ 1 ] == b[ j - 1 ][ 1 ] )
			{
				d[ i ][ j ] = d[ i - 1 ][ j - 1 ] + 1 ;
			}
			else if( d[ i - 1 ][ j ] >= d[ i ][ j - 1 ] )
			{
				d[ i ][ j ] = d[ i - 1 ][ j ] ;
			}
			else
			{
				d[ i ][ j ] = d[ i ][ j - 1 ] ;
			}
		}
	}

	return d[ lenA ][ lenB ] ;
}

bool cmp( int *a, int *b )
{
	return a[ 0 ] < b[ 0 ] ;
}

int
main()
{
	int		n = 0 ;
	int*	correct[ MaxN + 1 ] ;
	int*	student[ MaxN + 1 ] ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 0 ; i < MaxN ; i++ )
	{
		correct[ i ] = new int[ 2 ] ;
		student[ i ] = new int[ 2 ] ;
	}

	cin >> n ;
	for( i = 0 ; i < n ; i++ )
	{
		cin >> correct[ i ][ 0 ] ;
		correct[ i ][ 1 ] = i ;
	}

	sort( correct, correct + n, cmp ) ;

	while( cin >> student[ 0 ][ 0 ] )
	{
		student[ 0 ][ 1 ] = 0 ;
		for( i = 1 ; i < n ; i++ )
		{
			cin >> student[ i ][ 0 ] ;
			student[ i ][ 1 ] = i ;
		}

		sort( student, student + n, cmp ) ;

		cout << findLCS( correct, student, n, n ) << endl ;
	}

	return 0 ;
}
