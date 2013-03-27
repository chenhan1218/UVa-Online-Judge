#include <iostream>
#include <cmath>
using namespace std ;

long double cross( long double x1, long double y1, long double x2, long double y2 )
{
	return x1 * y2 - x2 * y1 ;
}

int main()
{
	long double	x[ 3 ] = { 0 } ;
	long double	y[ 3 ] = { 0 } ;
	long double	area = 0 ;
	int		casenum = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	cin >> casenum ;
	for( i = 0 ; i < casenum ; i++ )
	{
		for( j = 0 ; j < 3 ; j++ )
		{
			cin >> x[ j ] >> y[ j ] ;
		}
		
		// calculate area of ABC
		area = fabs( cross( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ] ) + 
				cross( x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ] ) + 
				cross( x[ 2 ], y[ 2 ], x[ 0 ], y[ 0 ] ) ) / 2 ;
		
		// calculate area of PQR by divide the area of ABC by 7
		area /= 7 ;
		
		cout << (long long int)round( area ) << endl ;
	}
	
	return 0 ;
}
