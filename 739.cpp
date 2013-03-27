#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxCharacters 20

int
main()
{
	int		digit = 0 ;
	int		soundex[ 256 ] = { 0 } ;
	char	name[ MaxCharacters + 1 ] ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	soundex[ (int)('B') ] = 1 ;
	soundex[ (int)('P') ] = 1 ;
	soundex[ (int)('F') ] = 1 ;
	soundex[ (int)('V') ] = 1 ;

	soundex[ (int)('C') ] = 2 ;
	soundex[ (int)('S') ] = 2 ;
	soundex[ (int)('K') ] = 2 ;
	soundex[ (int)('G') ] = 2 ;
	soundex[ (int)('J') ] = 2 ;
	soundex[ (int)('Q') ] = 2 ;
	soundex[ (int)('X') ] = 2 ;
	soundex[ (int)('Z') ] = 2 ;

	soundex[ (int)('D') ] = 3 ;
	soundex[ (int)('T') ] = 3 ;

	soundex[ (int)('L') ] = 4 ;

	soundex[ (int)('M') ] = 5 ;
	soundex[ (int)('N') ] = 5 ;

	soundex[ (int)('R') ] = 6 ;

	cout << "         NAME                     SOUNDEX CODE" << endl ;

	while( cin >> name )
	{
		cout << "         " << setw( 25 ) << left << name ;

		// The first letter of a name appears as the first and only letter 
		// in the soundex code.
		cout << name[ 0 ] ;

		digit = 0 ;
		// All other letters are encoded EXCEPT when they immediately 
		// follow a letter (including the first letter) that would be 
		// encoded with the same code digit.
		for( i = 1 ; digit < 3 && i < strlen( name ) ; i++ )
		{
			if( soundex[ (int)name[ i ] ] != 0 && 
				soundex[ (int)name[ i - 1 ] ] != soundex[ (int)name[ i ] ] )
			{
				digit++ ;
				cout << soundex[ (int)name[ i ] ] ;
			}
		}

		for( ; digit < 3 ; digit++ )
		{
			cout << 0 ;
		}

		cout << endl ;
	}

	cout << "                   END OF OUTPUT" << endl ;

	return 0 ;
}
