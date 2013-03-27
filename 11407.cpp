#include <iostream>
using namespace std ;

#define MaxN 10000

int main()
{
	int		n = 0 ;
	int		smallest[ MaxN + 1 ] = { 0 } ;
	int		root = 0 ;
	int		t = 0 ;
	int		i = 0 ;
	int		j = 0 ;

	smallest[ 0 ] = 0 ;
	root = 0 ;
	for( i = 1 ; i <= MaxN ; i++ )
	{
		if( ( root + 1 ) * ( root + 1 ) == i )
			root++ ;
			
		smallest[ i ] = i ;
		for( j = 1 ; j <= root ; j++ )
		{
			smallest[ i ] = min( smallest[ i ], smallest[ i - j * j ] + 1 ) ;
		}
	}
	
	cin >> t ;
	while( t > 0 )
	{
		t-- ;
		cin >> n ;
		cout << smallest[ n ] << endl ;
	}
	
	return 0 ;
}
