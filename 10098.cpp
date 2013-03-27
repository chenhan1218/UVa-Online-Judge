#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>
#include <algorithm>

#define Max_len 10

char	word[ Max_len + 1 ] ;
int		lenWord ;

int
main()
{
	int		n = 0 ;
	int		i = 0 ; // loop counter

	cin >> n ;

	for( i = 1 ; i <= n ; i++ )
	{
		cin >> word ;
		lenWord = strlen( word ) ;

		sort( word, word + lenWord ) ;

		do
		{
			cout << word << endl ;
		}while( next_permutation( word, word + lenWord ) );

		cout << endl ; //A blank line should follow each output set.
	}

	return 0 ;
}
