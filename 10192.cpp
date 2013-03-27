#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>

#define MaxCharacters 100

int		d[ MaxCharacters + 1 ][ MaxCharacters + 1 ] = { 0 } ;
char	text1[ MaxCharacters + 1 ] ;
char	text2[ MaxCharacters + 1 ] ;
int		lenText1 = 0 ;
int		lenText2 = 0 ;

void LCS()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	// dynamic programming technique
	for( i = 1 ; i <= lenText1 ; i++ )
	{
		for( j = 1 ; j <= lenText2 ; j++ )
		{
			if( text1[ i - 1 ] == text2[ j - 1 ] )
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
}

int
main()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 1 ; cin.getline( text1, MaxCharacters + 1 ) && text1[ 0 ] != '#' &&
				cin.getline( text2, MaxCharacters + 1 ) ; i++ )
	{
		lenText1 = strlen( text1 ) ;
		lenText2 = strlen( text2 ) ;
		LCS() ;

		cout 	<< "Case #" << i << ": you can visit at most " 
				<< d[ lenText1 ][ lenText2 ] << " cities." << endl ;
	}

	return 0 ;
}
