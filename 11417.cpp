#include <iostream>
using namespace std ;

#define MaxN 500

long long int gcd( long long int a, long long int b )
{
	while( b != 0 )
	{
		a %= b ;
		swap( a, b ) ;
	}
	return a ;
}

int main()
{
	int		n = 0 ;
	int		g[ MaxN + 1 ] = { 0 } ;
	int		t = 0 ;
	int		i = 0 ;
	int		j = 0 ;

	g[ 0 ] = 0 ;
	for( i = 1 ; i <= MaxN ; i++ )
	{
		g[ i ] = g[ i - 1 ] ;
		for( j = 1 ; j < i ; j++ )
		{
			g[ i ] += gcd( i, j ) ;
		}
	}
	
	while( cin >> n && n != 0 )
	{
		cout << g[ n ] << endl ;
	}
	
	return 0 ;
}
