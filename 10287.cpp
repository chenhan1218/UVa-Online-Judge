#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	long double s ;

	long double root3 = pow( 3.0 , 0.5 ) ;
	long double root7 = pow( 7.0 , 0.5 ) ;

	long double a = root3 / 2.0 ;
	long double b = ( 2.0 * root3 - 3.0 ) ;
	long double c = a / 2.0 ;
	long double d = ( 6.0 * root7 - 7 * root3 ) / 10.0 ;

	cout.setf( ios::fixed ) ;
	cout.precision( 10 ) ;

	while( cin >> s )
	{
		cout << a * s << " "
			<< b * s << " "
			<< c * s << " "
			<< d * s << endl ;
	}

	return 0 ;
}
