#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstdlib>
#include <cstring>

#define MaxNewspaper 12
#define MaxCharacters 30

int		a = 0 ;
int		b = 0 ;
int		n = 0 ;
char	names[ MaxNewspaper + 1 ][ MaxCharacters + 1 ] ;
int		numNewspaper = 0 ;
char	subset[ MaxCharacters + 1 ] ;
char	buffer[ MaxCharacters + 1 ] ;
int		possibleSubset[ MaxNewspaper + 1 ] = { 0 } ;

bool next_subset( int* first, int* last, int n )
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int*	ptr = NULL ;

	for( ptr = last - 1, i = 1 ; ptr >= first && i <= n ; ptr--, i++ )
	{
		if( *ptr <= n - i )
		{
			*ptr += 1 ;

			while( ptr < last )
			{
				ptr++ ;
				*ptr = *( ptr - 1 ) + 1 ;
			}

			return 1 ;
		}
	}

	return 0 ;
}



int print( int size )
{
	int		i = 0 ; // loop counter

	if( size > numNewspaper )
	{
		return -1 ;
	}
	else
	{
		cout << "Size " << size << endl ;

		for( i = 1 ; i <= size ; i++ )
		{
			possibleSubset[ i ] = i ;
		}

		do
		{
			cout << names[ possibleSubset[ 1 ] ] ;
			for( i = 2 ; i <= size ; i++ )
			{
				cout << ", " << names[ possibleSubset[ i ] ] ;
			}
			cout << endl ;
		}while( next_subset( &possibleSubset[ 1 ], &possibleSubset[ 1 ] + size, numNewspaper ) ) ;
		return size ;
	}
}

int main()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		cases = 0 ;

	cin.getline( buffer, MaxCharacters + 1 ) ;
	cases = atoi( buffer ) ;
	cin.getline( buffer, MaxCharacters + 1 ) ; // absorb the blank line.

	for( i = 1 ; i <= cases ; i++ )
	{
		if( i > 1 )
		{
			cout << endl ;
		}

		numNewspaper = 0 ;
		// Read in the sizes of subsets to be output
		cin.getline( subset, MaxCharacters + 1 ) ;
		// Read int the the names of the newspapers, one per line.
		for( j = 1 ; ; j++ )
		{
			cin.getline( buffer, MaxCharacters + 1 ) ;
			if( buffer[ 0 ] == '\0' )
			{
				break ;
			}
			else
			{
				numNewspaper++ ;
				strcpy( names[ numNewspaper ], buffer ) ;
			}
		}

		if( subset[ 0 ] == '*' )
		{
			// means show all subset sizes from 1 to the number of newspapers 
			// in the list
			for( j = 1 ; j <= numNewspaper ; j++ )
			{
				print( j ) ;
				cout << endl ;
			}
		}
		else if( sscanf( subset, "%d%d", &a, &b ) == 2 )
		{
			// show all subset sizes from a to b, inclusive.
			for( j = a ; j <= b ; j++ )
			{
				print( j ) ;
				cout << endl ;
			}
		}
		else if( sscanf( subset, "%d", &n ) == 1 )
		{
			// show only subsets of size n.
			print( n ) ;
			cout << endl ;
		}
	}

	return 0 ;
}

