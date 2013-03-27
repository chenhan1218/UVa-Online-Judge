#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std ;

#define MaxN 50

int main()
{
	int		l = 0 ;
	int		n = 0 ;
	int		c[ MaxN + 2 ] = { 0 } ;
	int		optimal[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;

	while( cin >> l && l != 0 )
	{
		cin >> n ;
		c[ 0 ] = 0 ;
		for( i = 1 ; i <= n ; i++ )
			cin >> c[ i ] ;
		c[ n + 1 ] = l ;
		
		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n - i + 1 ; j++ )
			{
				optimal[ j ][ j + i - 1 ] = optimal[ j ][ j + i - 2 ] ;
				for( k = j ; k < j + i - 1 ; k++ )
				{
					optimal[ j ][ j + i - 1 ] = min( optimal[ j ][ j + i - 1 ], 
						optimal[ j ][ k - 1 ] + optimal[ k + 1 ][ j + i - 1 ] ) ;
				}
				
				optimal[ j ][ j + i - 1 ] += c[ j + i ] - c[ j - 1 ] ;
			}
		}
		
		cout << "The minimum cutting is " << optimal[ 1 ][ n ] << "." << endl ;
	}

	return 0 ;
}
