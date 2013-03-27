#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>
#include <algorithm>

#define Max_len 100

char	word[ Max_len + 1 ] ;
int		lenWord ;

int
main()
{
	while( cin >> word )
	{
		if( word[ 0 ] == '#')
		{
			break ;
		}

		lenWord = strlen( word ) ;

		if( next_permutation( word, word + lenWord ) )
		{
			cout << word << endl ;
		}
		else
		{
			cout << "No Successor" << endl ;
		}
	}

	return 0 ;
}
