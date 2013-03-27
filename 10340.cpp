#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>

int charAt( char *string, char c )
{
	int lenString = 0 ;
	int i = 0 ; // loop counter

	lenString = strlen( string ) ;
	for( i = 0 ; i < lenString ; i++ )
	{
		if( c == string[ i ] )
		{
			break ;
		}
	}

	if( i == lenString )
	{
		return -1 ;
	}
	else
	{
		return i ;
	}
}

int
main()
{
	char	s[ 1000000 ] ;
	char	t[ 1000000 ] ;
	char*	headT = t ;
	int		lenS = 0 ;
	int		removed = 0 ;
	int		place = 0 ;
	int		i = 0 ; // loop counter

	while( cin >> s >> t )
	{
		lenS = strlen( s ) ;
		removed = 0 ;

		for( i = 0 ; i < lenS ; i++ )
		{
			place = charAt( t + removed, s[ i ] ) ;

			if( place < 0 )
			{
				break ;
			}
			else
			{
				removed += place + 1 ;
			}
		}

		if( i == lenS )
		{
			cout << "Yes" << endl ;
		}
		else
		{
			cout << "No" << endl ;
		}
	}

	return 0 ;
}
