#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>

#define MaxWords 100
#define MaxCharacters 30

int		d[ MaxWords + 1 ][ MaxWords + 1 ] = { 0 } ;
char	text1[ MaxWords + 1 ][ MaxCharacters + 1 ] ;
char	text2[ MaxWords + 1 ][ MaxCharacters + 1 ] ;
int		words1 = 0 ;
int		words2 = 0 ;
char*	result[ MaxWords + 1 ] ;

void LCS()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	// dynamic programming technique
	for( i = 1 ; i <= words1 ; i++ )
	{
		for( j = 1 ; j <= words2 ; j++ )
		{
			if( strcmp( text1[ i ], text2[ j ] ) == 0 )
			{
				d[ i ][ j ] = d[ i - 1 ][ j - 1 ] + 1 ;
			}
			else if( d[ i ][ j - 1 ] > d[ i - 1 ][ j ] )
			{
				d[ i ][ j ] = d[ i ][ j - 1 ] ;
			}
			else
			{
				d[ i ][ j ] = d[ i - 1 ][ j ] ;
			}
		}
	}

	// save the subsequence to result
	for( i = words1, j = words2 ; i != 0 && j != 0 ; )
	{
		if( d[ i ][ j ] == d[ i - 1 ][ j ] )
		{
			i-- ;
		}
		else if( d[ i ][ j ] == d[ i ][ j - 1 ] )
		{
			j-- ;
		}
		else
		{
			result[ d[ i ][ j ] ] = text1[ i ] ;
			i-- ;
			j-- ;
		}
	}
}

void print()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 1 ; i <= words1 ; i++ )
	{
		cout << text1[ i ] << "\t" ;
	}
	cout << endl ;
	for( i = 1 ; i <= words2 ; i++ )
	{
		cout << text2[ i ] << "\t" ;
	}
	cout << endl ;
}

int
main()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> text1[ 1 ] )
	{
		if( text1[ 1 ][ 0 ] == '#' )
		{
			words1 = 0 ;
		}
		else
		{
			words1 = 1 ;

			for( i = 2 ; ; i++ )
			{
				cin >> text1[ i ] ;
				if( text1[ i ][ 0 ] != '#' )
				{
					words1++ ;
				}
				else
				{
					break ;
				}
			}
		}

		cin >> text2[ 1 ] ;

		if( text2[ 1 ][ 0 ] == '#' )
		{
			words2 = 0 ;
		}
		else
		{
			words2 = 1 ;

			for( i = 2 ; ; i++ )
			{
				cin >> text2[ i ] ;
				if( text2[ i ][ 0 ] != '#' )
				{
					words2++ ;
				}
				else
				{
					break ;
				}
			}
		}

		LCS() ;

		for( i = 1 ; i <= d[ words1 ][ words2 ] ; i++ )
		{
			if( i > 1 )
			{
				cout << " " ;
			}

			cout << result[ i ] ;
		}

		cout << endl ;
	}

	return 0 ;
}
