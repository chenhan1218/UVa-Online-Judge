#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

#define MaxN 200

int main()
{
	double	d[ MaxN ][ MaxN ] = { 0 } ;
	double	grid[ MaxN ][ 2 ] = { 0 } ;
	int		scenario = 0 ;
	int		n = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	while( cin >> n && n != 0 )
	{
		scenario++ ;
		
		for( i = 0 ; i < n ; i++ )
		{
			cin >> grid[ i ][ 0 ] >> grid[ i ][ 1 ] ;
		}
		
		for( i = 0 ; i < n ; i++ )
		{
			for( j = 0 ; j < n ; j++ )
			{
				d[ i ][ j ] = sqrt( ( grid[ i ][ 0 ] - grid[ j ][ 0 ] ) * ( grid[ i ][ 0 ] - grid[ j ][ 0 ] ) + 
									( grid[ i ][ 1 ] - grid[ j ][ 1 ] ) * ( grid[ i ][ 1 ] - grid[ j ][ 1 ] ) ) ;
			}
		}
		
		for( k = 0 ; k < n ; k++ )
		{
			for( i = 0 ; i < n ; i++ )
			{
				for( j = 0 ; j < n ; j++ )
				{
					d[ i ][ j ] = min( d[ i ][ j ], max( d[ i ][ k ], d[ k ][ j ] ) ) ;
				}
			}
		}
		
		// caution: Stone #1 is Freddy's stone, stone #2 is Fiona's stone
		cout << "Scenario #" << scenario << endl ;
		cout << "Frog Distance = " << fixed << setprecision( 3 ) << d[ 0 ][ 1 ] << endl ;
		cout << endl ;
	}
	
	return 0 ;
}
