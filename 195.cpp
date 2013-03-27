#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>
#include <algorithm>
#include <cctype>

#define Max_len 1024

char	word[ Max_len + 1 ] ;
int		lenWord ;

bool cmp( char a, char b )
{
	if( ( tolower(a) - tolower(b) ) != 0 )
	{
		return tolower(a) < tolower(b) ;
	}
	else
	{
		return a < b ;
	}
}

int
main()
{
	int		numWords = 0 ;
	int		i = 0 ; // loop counter

	cin >> numWords ;

	for( i = 1 ; i <= numWords ; i++ )
	{
		cin >> word ;
		lenWord = strlen( word ) ;

		sort( word, word + lenWord, cmp ) ;

		do
		{
			cout << word << endl ;
		}while( next_permutation( word, word + lenWord, cmp ) );
	}

	return 0 ;
}
