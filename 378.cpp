#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	double	x[ 5 ] = { 0 } ;
	double	y[ 5 ] = { 0 } ;
	double	xPoint = 0 ;
	double	yPoint = 0 ;
	int		t = 0 ;
	int		i = 0 ;

	cin >> t ;
	
	cout << "INTERSECTING LINES OUTPUT" << endl ;
	while( t > 0 )
	{
		t-- ;
		
		for( i = 1 ; i <= 4 ; i++ )
			cin >> x[ i ] >> y[ i ] ;
		
		if( ( x[ 1 ] - x[ 2 ] ) * ( y[ 3 ] - y[ 4 ] ) !=
				( x[ 3 ] - x[ 4 ] ) * ( y[ 1 ] - y[ 2 ] ) ) // Not parallel.
		{
			xPoint = ( x[ 1 ] - x[ 2 ] ) * ( x[ 3 ] - x[ 4 ] ) * ( y[ 1 ] - y[ 3 ] )
				- x[ 1 ] * ( x[ 3 ] - x[ 4 ] ) * ( y[ 1 ] - y[ 2 ] )
				+ x[ 3 ] * ( x[ 1 ] - x[ 2 ] ) * ( y[ 3 ] - y[ 4 ] ) ;
			xPoint = xPoint / ( ( x[ 1 ] - x[ 2 ] ) * ( y[ 3 ] - y[ 4 ] ) -
				( x[ 3 ] - x[ 4 ] ) * ( y[ 1 ] - y[ 2 ] ) ) ;
			
			yPoint = ( y[ 1 ] - y[ 2 ] ) * ( y[ 3 ] - y[ 4 ] ) * ( x[ 1 ] - x[ 3 ] )
				- y[ 1 ] * ( y[ 3 ] - y[ 4 ] ) * ( x[ 1 ] - x[ 2 ] )
				+ y[ 3 ] * ( y[ 1 ] - y[ 2 ] ) * ( x[ 3 ] - x[ 4 ] ) ;
			yPoint = yPoint / ( ( x[ 1 ] - x[ 2 ] ) * ( y[ 3 ] - y[ 4 ] ) -
				( x[ 3 ] - x[ 4 ] ) * ( y[ 1 ] - y[ 2 ] ) ) ;
			yPoint *= -1 ;
			
			cout << fixed << setprecision( 2 ) ;
			cout << "POINT" << " " << xPoint << " " << yPoint << endl ;
		}
		else
		{
			if( ( x[ 1 ] - x[ 2 ] ) * ( y[ 1 ] - y[ 3 ] ) == 
				( x[ 1 ] - x[ 3 ] ) * ( y[ 1 ] - y[ 2 ] ) )
			{
				cout << "LINE" << endl ;
			}
			else
			{
				cout << "NONE" << endl ;
			}
		}
	}
	
	cout << "END OF OUTPUT" << endl ;
	
	return 0 ;
}
