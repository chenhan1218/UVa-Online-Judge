#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	double rec[ 11 ][ 4 ] ;

	char type ;
	int n = 0 ;

	while( cin >> type )
	{
		if( type == '*' )
		{
			break ;
		}

		n++ ;
		cin >> rec[ n ][ 0 ] >> rec[ n ][ 1 ] >> rec[ n ][ 2 ] >> rec[ n ][ 3 ] ;
	}

	double x , y ;
	int inside ;
	int counter = 0 ;

	while( cin >> x >> y )
	{
		if( x == 9999.9 && y == 9999.9 )
		{
			break ;
		}

		counter++ ;
		inside = 0 ;
		for( int i = 1 ; i <= n ; i++ )
		{
			if( x > rec[ i ][ 0 ] && x < rec[ i ][ 2 ] && y < rec[ i ][ 1 ] && y > rec[ i ][ 3 ] )
			{
				inside = 1 ;

				cout << "Point " << counter << " is contained in figure " << i << endl ;
			}
		}

		if( inside == 0 )
		{
			cout << "Point " << counter << " is not contained in any figure" << endl ;
		}
	}

	return 0 ;
}
