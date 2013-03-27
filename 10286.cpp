#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	double F ;
	double pi_divide_180 = acos( 0 ) / 90.0 ;
	double rate = sin( 108.0 * pi_divide_180 ) / sin( 63.0 * pi_divide_180 ) ;

	cout.setf( ios::fixed ) ;
	cout.precision( 10 ) ;

	while( cin >> F )
	{
		cout << F * rate << endl ;
	}

	return 0 ;
}
