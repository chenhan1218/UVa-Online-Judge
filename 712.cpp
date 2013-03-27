#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;

#define MaxN 7

int main()
{
	int		n = 0 ;
	string	terminal ;
	string	vva ;
	char	buffer ;
	int		order[ MaxN + 1 ] = { 0 } ;
	int		numFunction = 0 ;
	int		position = 0 ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> n && n != 0 )
	{
		cases++ ;

		for( i = 1 ; i <= n ; i++ )
			cin >> buffer >> order[ i ] ;

		cin >> terminal ;

		cin >> numFunction ;

		cout << "S-Tree #" << cases << ":" << endl ;
		for( i = 0 ; i < numFunction ; i++ )
		{
			cin >> vva ;
			position = 0 ;

			for( j = 1 ; j <= n ; j++ )
			{
				position = position * 2 + ( vva[ order[ j ] - 1 ] - '0' ) ;
			}

			cout << terminal[ position ] ;
		}
		cout << endl ;

		cout << endl ; // Output a blank line after each test case.
	}

	return 0 ;
}
