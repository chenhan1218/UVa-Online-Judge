#include <iostream>
#include <iomanip>
using namespace std ;

#define MaxN 100
#define MaxK 100

int
main()
{
	int		n = 0 ;
	int		k = 0 ;
	long long int ans[ MaxN + 1 ][ MaxK + 1 ] = { 0 } ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		m = 0 ;

	for( i = 0 ; i <= MaxK ; i++ )
		ans[ 0 ][ i ] = 1 ;

	for( i = 1 ; i <= MaxN ; i++ )
	{
		ans[ i ][ 1 ] = 1 ;
		for( j = 2 ; j <= MaxK ; j++ )
		{
			ans[ i ][ j ] = ans[ i ][ j - 1 ] + ans[ i - 1 ][ j ] ;

			ans[ i ][ j ] %= 1000000 ;
		}
	}

	while( cin >> n >> k )
	{
		if( n == 0 && k == 0 )
			break ;

		cout << ans[ n ][ k ] << endl ;
	}

	return 0 ;
}
