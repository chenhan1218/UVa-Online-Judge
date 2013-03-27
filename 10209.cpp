#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	double c , d , e ;
	double root_3 = pow( 3.0 , 0.5 ) ;
	double pi_divide3 = acos( 0.5 ) ;

	c = 1 - root_3 + pi_divide3 ;

	e = c + 3.0 - pi_divide3 * 3.0 ;

	d = 1 - c - e ;

	double a ;

	cout.setf( ios::fixed ) ;
	cout.precision( 3 ) ;

	while( cin >> a )
	{
		a = a * a ;
		cout << c * a << " " << d * a << " " << e * a << endl ;
	}

	return 0 ;
}
