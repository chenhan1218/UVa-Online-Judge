#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;

int main()
{
	int		cases = 0 ;
	int		n = 0 ;
	string	number ;
	int 	i = 0 ;
	int 	j = 0 ;
	cin >> cases ;
	for( i = 0 ; i < cases ; i++ )
	{
		cin >> n ;
		if( n == 1 )
		{
			cout << 1 << endl ;
			continue ;
		}

		number = "" ;
		for( j = 9 ; j >= 2 ; j-- )
		{
			while( n % j == 0 )
			{
				number.insert( 0, 1, '0' + j ) ;
				n /= j ;
			}
		}

		if( n == 1 )
		{
			cout << number << endl ;
		}
		else
		{
			cout << -1 << endl ;
		}
	}

	return 0 ;
}
