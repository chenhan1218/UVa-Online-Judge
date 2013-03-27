#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
using namespace std ;

#define MaxCharacters 20

int		d[ MaxCharacters + 1 ][ MaxCharacters + 1 ] = { 0 } ;
string	ins[ MaxCharacters + 1 ][ MaxCharacters + 1 ] ;

string minimalInstruction( const string a, const string b )
{
	char	buffer[ 10 ] ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 1 ; i <= a.size() ; i++ )
	{
		d[ i ][ 0 ] = i ;
		sprintf( buffer, "D%c%02d", a[ i - 1 ], 1 ) ;
		ins[ i ][ 0 ] = ins[ i - 1 ][ 0 ] + buffer ;
	}

	for( j = 1 ; j <= b.size() ; j++ )
	{
		d[ 0 ][ j ] = j ;
		sprintf( buffer, "I%c%02d", b[ j - 1 ], j ) ;
		ins[ 0 ][ j ] = ins[ 0 ][ j - 1 ] + buffer ;
	}

	for( i = 1 ; i <= a.size() ; i++ )
	{
		for( j = 1 ; j <= b.size() ; j++ )
		{
			if( a[ i - 1 ] == b[ j - 1 ] )
			{
				d[ i ][ j ] = d[ i - 1 ][ j - 1 ] ;
				ins[ i ][ j ] = ins[ i - 1 ][ j - 1 ] ;
			}
			else
			{
				d[ i ][ j ] = min( min( d[ i - 1 ][ j - 1 ] + 1, d[ i - 1 ][ j ] + 1 ), 
								d[ i ][ j - 1 ] + 1 ) ;

				if( d[ i ][ j ] == d[ i - 1 ][ j - 1 ] + 1 )
				{
					sprintf( buffer, "C%c%02d", b[ j - 1 ], j ) ;
					ins[ i ][ j ] = ins[ i - 1 ][ j - 1 ] + buffer ;
				}
				else if( d[ i ][ j ] == d[ i - 1 ][ j ] + 1 )
				{
					sprintf( buffer, "D%c%02d", a[ i - 1 ], j + 1 ) ;
					ins[ i ][ j ] = ins[ i - 1 ][ j ] + buffer ;
				}
				else
				{
					sprintf( buffer, "I%c%02d", b[ j - 1 ], j ) ;
					ins[ i ][ j ] = ins[ i ][ j - 1 ] + buffer ;
				}
			}
		}
	}

	return ins[ a.size() ][ b.size() ] + "E" ;
}


int
main()
{
	string	a ;
	string	b ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> a >> b )
	{
		cout << minimalInstruction( a, b ) << endl ;
	}

	return 0 ;
}
