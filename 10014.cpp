#include <iostream>
using namespace std ;

int main()
{
	int cases , n ;

	long double a_0 , a_nplus1 , c[ 3001 ] ;

	cout.setf( ios::fixed ) ;
	cout.precision( 2 ) ;

	cin >> cases ;

	for( int i = 1 ; i <= cases ; i++ )
	{
		cin >> n >> a_0 >> a_nplus1 ;

		for( int j = 1 ; j <= n ; j++ )
		{
			cin >> c[ j ] ;
		}
		
		c[ 1 ] = c[ 1 ] - a_0 / 2 ;
		c[ n ] = c[ n ] - a_nplus1 / 2 ;
		
		for( int j = 1 ; j <= n - 1 ; j++ )
		{
			c[ j + 1 ] = c[ j + 1 ] + c[ j ] * j / ( j + 1 ) ;
		}
		
		for( int j = n ; j >= 2 ; j-- )
		{
			c[ j - 1 ] = c[ j - 1 ] + c[ j ] * j / ( j + 1 ) ;
		}
		
		if( i != 1 )
		{
			cout << endl ;
		}
		
		cout << (-1) * c[ 1 ] << endl ;
	}

	return 0 ;
}
