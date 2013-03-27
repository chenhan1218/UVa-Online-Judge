// i have an equation 1/sqrt(x^2-w^2)+1/sqrt(y^2-w^2)=1/c
// but have not good way to solve it.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
using namespace std ;

int main()
{
	double		x = 0 ;
	double		y = 0 ;
	double		c = 0 ;
	double		small = 0 ;
	double		large = 0 ;
	double		mid = 0 ;
	
	while( cin >> x >> y >> c )
	{
		small = 0 ;
		large = min( x, y ) ;
		
		do
		{
			ostringstream	smallStream ;
			smallStream << fixed << setprecision( 3 ) << small ;
			ostringstream	largeStream ;
			largeStream << fixed << setprecision( 3 ) << large ;
			if( smallStream.str() == largeStream.str() )
				break ;
			
			mid = ( small + large ) / 2 ;
			if( 1/sqrt( x*x-mid*mid ) + 1/sqrt( y*y-mid*mid ) <= 1/c )
			{
				small = mid ;
			}
			else
			{
				large = mid ;
			}
			
		} while( 1 ) ;
		
		cout << fixed << setprecision( 3 ) << small << endl ;
	}
	
	return 0 ;
}
