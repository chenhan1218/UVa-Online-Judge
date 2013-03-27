#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstdlib>
#include <cstring>

#define MaxDigits 1000

int
main()
{
	char	digits[ MaxDigits + 1 ] ;
	int		lenDigits = 0 ;
	long long	remainder = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> digits )
	{
		lenDigits = strlen( digits ) ;

		if( lenDigits == 1 && digits[ 0 ] == '0' )
		{
			break ;
		}

		cout << digits ;

		remainder = 0 ;
		for( i = lenDigits - 6 ; i >= 0 ; i -= 6 )
		{
			remainder += atoi( digits + i ) ;
			digits[ i ] = '\0' ;
		}

		remainder += atoi( digits ) ;

		if( remainder % 11 == 0 )
		{
			cout << " is a multiple of 11." << endl ;
		}
		else
		{
			cout << " is not a multiple of 11." << endl ;
		}
	}

	return 0 ;
}
