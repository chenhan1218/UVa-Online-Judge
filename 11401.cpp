#include <iostream>
using namespace std ;

#define MaxN 1000000

long long int		tri[ MaxN + 1 ] = { 0 } ;

int main()
{
	long long int		n = 0 ;
	long long int		i = 0 ;
	
	for( i = 3 ; i <= MaxN ; i++ )
	{
		if( i % 2 == 0 )
		{
			tri[ i ] = tri[ i - 1 ] + ( i - 2 ) / 2 * ( i - 2 ) / 2 ;
		}
		else
		{
			tri[ i ] = tri[ i - 1 ] + ( i - 1 ) / 2 * ( i - 3 ) / 2 ;
		}
	}
	
	while( cin >> n && n >= 3 )
	{
		cout << tri[ n ] << endl ;
	}
	
	return 0 ;
}
