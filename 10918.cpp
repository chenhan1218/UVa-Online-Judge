#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
	long long	possibleTilings[ 31 ] = { 0 } ;
	int			n = 0 ;
	int			i = 0 ; // loop counter
	int			j = 0 ; // loop counter

	possibleTilings[ 2 ] = 3 ;

	for( i = 4 ; i <= 30 ; i += 2 )
	{
		possibleTilings[ i ] = 2 ;
		possibleTilings[ i ] += 3 * possibleTilings[ i - 2 ] ;

		for( j = 2 ; j <= i - 4 ; j += 2 )
		{
			possibleTilings[ i ] += 2 * possibleTilings[ j ] ;
		}
	}

	while( cin >> n )
	{
		if( n == -1 )
		{
			break ;
		}

		cout << possibleTilings[ n ] << endl ;
	}

	return 0 ;
}
