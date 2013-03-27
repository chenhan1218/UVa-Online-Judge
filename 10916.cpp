#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std ;

#define MaxY 2160
#define MaxN 254016

int		bit[ MaxY + 1 ] = { 0 } ;
long double	logFactorial[ MaxN + 1 ] = { 0 } ;

int main()
{
	int		i = 0 ;
	int		y = 0 ;
	
	bit[ 1960 ] = 4 ;
	for( i = 1961 ; i <= MaxY ; i++ )
	{
		if( i % 10 == 0 )
		{
			bit[ i ] = bit[ i - 1 ] << 1 ;
		}
		else
		{
			bit[ i ] = bit[ i - 1 ] ;
		}
	}
	
	for( i = 1 ; i <= MaxN ; i++ )
	{
		logFactorial[ i ] = logFactorial[ i - 1 ] + log( i ) / log( 2 ) ;
	}
	
	while( cin >> y && y != 0 )
	{
		cout << upper_bound( logFactorial, logFactorial + MaxN + 1, bit[ y ] ) - logFactorial - 1 << endl ;
	}
	
	return 0 ;
}
