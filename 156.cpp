#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>
#include <algorithm>

#define True 1
#define False 0
#define MaxWordLen 20
#define MaxWords 1000

class word
{
	public :
		word( char *buffer, char *sortedBuffer ) ;
		static bool	cmp( word* a, word* b ) ;
		char	origin[ MaxWordLen + 1 ] ;
		char	sorted[ MaxWordLen + 1 ] ;
		bool	ananagram ;
};

word::word( char *buffer, char *sortedBuffer )
{
	strcpy( origin, buffer ) ;
	strcpy( sorted, sortedBuffer ) ;
	ananagram = True ;
}

bool word::cmp( word* a, word* b )
{
	return ( strcmp( a->origin, b->origin ) < 0 ) ;
}

char	buffer[ MaxWordLen + 1 ] ;
char	sortedBuffer[ MaxWordLen + 1 ] ;
word*	node[ MaxWords + 1 ] ;
int		numWords = 0 ;

void tolowerAndSort( char *sortedBuffer, char *buffer )
{
	int		i = 0 ; // loop counter
	for( i = 0 ; buffer[ i ] != '\0' ; i++ )
	{
		sortedBuffer[ i ] = tolower( buffer[ i ] ) ;
	}
	sortedBuffer[ i ] = '\0' ;

	sort( sortedBuffer, sortedBuffer + i ) ;
}

void print()
{
	int		i = 0 ; // loop counter

	for( i = 1 ; i <= numWords ; i++ )
	{
		if( node[ i ]->ananagram == True )
		{
			cout << node[ i ]->origin << endl ;
		}
	}
}

int
main()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	// first we establish first word.
	cin >> buffer ;
	tolowerAndSort( sortedBuffer, buffer ) ;
	node[ 1 ] = new word( buffer, sortedBuffer ) ;
	numWords = 1 ;

	while( cin >> buffer )
	{
		if( buffer[ 0 ] == '#' )
		{
			break ;
		}

		tolowerAndSort( sortedBuffer, buffer ) ;

		for( i = 1 ; i <= numWords ; i++ )
		{
			if( strcmp( sortedBuffer, node[ i ]->sorted ) == 0 )
			{
				node[ i ]->ananagram = False ;
				break ;
			}
		}

		// If the new word is not the same as those previous, store it.
		if( i > numWords )
		{
			numWords++ ;
			node[ numWords ] = new word( buffer, sortedBuffer ) ;
		}
	}

	sort( &node[ 1 ], &node[ 1 ] + numWords , word::cmp ) ;
	print() ;

	return 0 ;
}
