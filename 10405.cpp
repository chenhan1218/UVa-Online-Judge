#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>

#define MaxCharacters 1000

int		d[ MaxCharacters + 1 ][ MaxCharacters + 1 ] = { 0 } ;
char	text1[ MaxCharacters + 1 ] ;
char	text2[ MaxCharacters + 1 ] ;

int	findLCS( char *a, char *b )
{
	int	lenA = strlen( a );
	int	lenB = strlen( b );
	int	i = 0 ;
	int j = 0 ;

	for( i = 1 ; i <= lenA ; i++ )
	{
		for( j = 1 ; j <= lenB ; j++ )
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

	return d[ lenA ][ lenB ] ;
}

int
main()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin.getline( text1, MaxCharacters + 1 ) && cin.getline( text2, MaxCharacters + 1) )
	{
		cout << findLCS( text1, text2 ) << endl ;
	}

	return 0 ;
}
