#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std ;

int main()
{
	vector<double>		poly ;
	int		numPoly = 0 ;
	int		deg = 0 ;
	double	root ;
	
	cin.sync_with_stdio( false ) ;
	cout.sync_with_stdio( false ) ;
	cout << fixed << setprecision( 1 ) ;
	
	cin >> numPoly ;
	while( numPoly > 0 )
	{
		numPoly-- ;
		
		cin >> deg ;
		poly.assign( deg + 1, 0 ) ;
		for( int i = 0 ; i <= deg ; i++ )
			cin >> poly[ i ] ;
		
		for( int i = 1 ; i <= deg - 2 ; i++ )
		{
			cin >> root ;
			for( int j = 0 ; j < deg - i ; j++ )
			{
				poly[ j + 1 ] += poly[ j ] * root ;
			}
		}
		
		double	a = poly[ 0 ] ;
		double	b = poly[ 1 ] ;
		double	c = poly[ 2 ] ;
		double	tmp = sqrt( b*b-4*a*c ) ;
		
		cout << ( -b + tmp ) / 2 / a << endl ;
		cout << ( -b - tmp ) / 2 / a << endl ;
	}
	
	return 0 ;
}
