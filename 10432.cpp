#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	long double r , pi_2 = 4 * acos( 0 ) ;
	long double answer ;
	long double n ;

	cout.setf( ios::fixed ) ;
	cout.precision( 3 ) ;

	while( cin >> r >> n )
	{
		answer = n / 2.0 * sin( pi_2 / n ) * r * r ;
		cout << answer << endl ;
	}

	return 0 ;
}
