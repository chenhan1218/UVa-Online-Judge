#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int L , f ;
	double v , volume ;

	cout.setf( ios::fixed ) ;
	cout.precision( 8 ) ;

	while( cin >> L >> f )
	{
		if( L == 0 && f == 0 )
		{
			break ;
		}

		v = pow( 2.0 * L * f , 0.5 ) ;
		volume = 1800.0 * v / L ;

		cout << v << " " << volume << endl ;
	}

	return 0 ;
}
