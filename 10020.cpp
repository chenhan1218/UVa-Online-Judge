#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxSegments 100000

bool cmp( double *a, double * b )
{
	if( a[ 0 ] != b[ 0 ] )
	{
		return a[ 0 ] < b[ 0 ] ;
	}
	else
	{
		return a[ 1 ] < b[ 1 ] ;
	}
}

int
main()
{
	int		cases = 0 ;
	int		M = 0 ;
	double*	segment[ MaxSegments + 1 ] ;
	int		setSegments[ MaxSegments + 1 ] ;
	int		numSegment = 0 ;
	double	largestRight = 0 ;
	double	needToCover = 0 ;
	int		numMinimal = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 0 ; i <= MaxSegments ; i++ )
	{
		segment[ i ] = new double[ 2 ] ;
	}

	cin >> cases ;
	for( i = 1 ; i <= cases ; i++ )
	{
		cin >> M ;

		numSegment = 1 ;
		while( cin >> segment[ numSegment ][ 0 ] >> segment[ numSegment ][ 1 ] )
		{
			if( segment[ numSegment ][ 0 ] == 0 && segment[ numSegment ][ 1 ] == 0 )
			{
				numSegment -- ;
				break ;
			}

			numSegment ++ ;
		}

		sort( segment + 1, segment + numSegment + 1, cmp ) ;
		segment[ 0 ][ 0 ] = segment[ 1 ][ 0 ] ;
		segment[ 0 ][ 1 ] = segment[ 1 ][ 1 ] ;

		j = 1 ;
		numMinimal = 0 ;
		for( needToCover = 0  ; needToCover < M ; )
		{
			largestRight = -1 ;
			while( j <= numSegment && segment[ j ][ 0 ] <= needToCover )
			{
				if( segment[ j ][ 1 ] >= needToCover && largestRight < segment[ j ][ 1 ] )
				{
					largestRight = segment[ j ][ 1 ] ;
					setSegments[ numMinimal ] = j ;
				}
				j++ ;
			}

			if( largestRight < 0 )
			{
				break ;
			}
			else
			{
				numMinimal ++ ;
				needToCover = largestRight ;
			}
		}

		//Print a blank line between the outputs for two consecutive test cases.
		if( i > 1 )
		{
			cout << endl ;
		}

		if( needToCover < M )
		{
			cout << 0 << endl ;
		}
		else
		{
			cout << numMinimal << endl ;
			for( j = 0 ; j < numMinimal ; j++ )
			{
				cout 	<< segment[ setSegments[ j ] ][ 0 ] << " " 
						<< segment[ setSegments[ j ] ][ 1 ] << endl ;
			}
		}
	}

	return 0 ;
}
