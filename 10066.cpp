#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxTile 100

int		tower1[ MaxTile + 1 ] = { 0 } ;
int		tower2[ MaxTile + 1 ] = { 0 } ;
int		d[ MaxTile + 1 ][ MaxTile + 1 ] = { 0 } ;

int	findLCS( int *a, int *b, int N1, int N2 )
{
	int	i = 0 ;
	int j = 0 ;

	for( i = 1 ; i <= N1 ; i++ )
	{
		for( j = 1 ; j <= N2 ; j++ )
		{
			if( a[ i - 1 ] == b[ j - 1 ] )
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

	return d[ N1 ][ N2 ] ;
}

int
main()
{
	int		cases = 0 ;
	int		N1 = 0 ;
	int		N2 = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> N1 >> N2 )
	{
		if( N1 == 0 && N2 == 0 )
		{
			break ;
		}
		cases++ ;

		for( i = 0 ; i < N1 ; i++ )
		{
			cin >> tower1[ i ] ;
		}
		for( i = 0 ; i < N2 ; i++ )
		{
			cin >> tower2[ i ] ;
		}

		cout << "Twin Towers #" << cases << endl ;
		cout << "Number of Tiles : " << findLCS( tower1, tower2, N1, N2 ) << endl ;
		//Print a blank line after the output of each data set.
		cout << endl ;
	}

	return 0 ;
}
