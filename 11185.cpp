#include <iostream>
#include <string>
using namespace std ;

int main()
{
	int		n = 0 ;
	string	str ;
	int		i = 0 ;
	int		j = 0 ;

	while( cin >> n )
	{
		if( n < 0 )
			break ;

		str.clear() ;

		str += '0' + ( n % 3 ) ;
		n /= 3 ;

		while( n > 0 )
		{
			str = (char)( '0' + ( n % 3 ) ) + str ;
			n /= 3 ;
		}

		cout << str << endl ;
	}

	return 0 ;
}

