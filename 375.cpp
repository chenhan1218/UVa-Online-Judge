#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

int main()
{
	const double	pi = acos( -1 ) ;
	double	b = 0 ;
	double	h = 0 ;
	double	radius = 0 ;
	double	c = 0 ;
	double	m = 0 ;
	int		casenum ;
	int		i = 0 ;
	
	cout << fixed << setprecision( 6 ) ;
	
	cin >> casenum ;
	
	for( i = 1 ; i <= casenum ; i++ )
	{
		cin >> b >> h ;
		
		radius = b*h / ( sqrt( 4*h*h + b*b ) + b ) ;
		m = 1 - 2*b / ( sqrt( 4*h*h + b*b ) + b ) ;
		c = 0 ;
		while( radius >= 0.000001 )
		{
			c += radius * 2 * pi ;
			radius *= m ;
		}
		
		if( i != 1 )
			cout << endl ;
		cout << setw( 13 ) << right << c << endl ;
	}
	
	return 0 ;
}
