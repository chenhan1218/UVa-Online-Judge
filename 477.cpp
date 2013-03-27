#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	double rec[ 11 ][ 5 ] = { 0 } ;

	char type ;
	int n = 0 ;

	while( cin >> type )
	{
		if( type == '*' )
		{
			break ;
		}

		n++ ;

		if( type == 'r' )
		{
			rec[ n ][ 0 ] = 1 ;
			cin >> rec[ n ][ 1 ] >> rec[ n ][ 2 ] >> rec[ n ][ 3 ] >> rec[ n ][ 4 ] ;
		}
		else if( type == 'c' )
		{
			rec[ n ][ 0 ] = 2 ;
			cin >> rec[ n ][ 1 ] >> rec[ n ][ 2 ] >> rec[ n ][ 3 ] ;
		}
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
			if( rec[ i ][ 0 ] == 1 )
			{
				if( x > rec[ i ][ 1 ] && x < rec[ i ][ 3 ] && y < rec[ i ][ 2 ] && y > rec[ i ][ 4 ] )
				{
					inside = 1 ;

					cout << "Point " << counter << " is contained in figure " << i << endl ;
				}
			}
			else
			{
				if( ( x - rec[ i ][ 1 ] ) * ( x - rec[ i ][ 1 ] ) + ( y - rec[ i ][ 2 ] ) * ( y - rec[ i ][ 2 ] ) < rec[ i ][ 3 ] * rec[ i ][ 3 ] )
				{
					inside = 1 ;

					cout << "Point " << counter << " is contained in figure " << i << endl ;
				}
			}
		}

		if( inside == 0 )
		{
			cout << "Point " << counter << " is not contained in any figure" << endl ;
		}
	}

	return 0 ;
}
