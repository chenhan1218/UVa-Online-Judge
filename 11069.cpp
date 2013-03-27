#include <iostream>
using namespace std ;

#define MaxN 76

long long int	subset[ MaxN + 1 ][ 2 ] = { 0 } ;

int main()
{
	int		n = 0 ;
	int		i = 0 ; // loop counter
	
	subset[ 1 ][ 0 ] = 0 ;
	subset[ 1 ][ 1 ] = 1 ;
	subset[ 2 ][ 0 ] = 1 ;
	subset[ 2 ][ 1 ] = 1 ;
	subset[ 3 ][ 0 ] = 1 ;
	subset[ 3 ][ 1 ] = 1 ;
	for( i = 4 ; i <= MaxN ; i++ )
	{
		subset[ i ][ 0 ] = subset[ i - 1 ][ 1 ] ;
		subset[ i ][ 1 ] = subset[ i - 2 ][ 0 ] + subset[ i - 2 ][ 1 ] ;
	}
	
	while( cin >> n )
		cout << subset[ n ][ 0 ] + subset[ n ][ 1 ] << endl ;
	
	return 0 ;
}
