#include <iostream>
#include <iomanip>
using namespace std ;

#include <cmath>

#define PI 3.14159265

int
main()
{
	double D, V ;

	cout.setf( ios::fixed ) ;
	cout.precision( 3 ) ;

	while( cin >> D >> V )
	{
		if( D == 0 && V == 0 )
		{
			break ;
		}

		cout << pow( D * D * D - 6 / PI * V, 1.0/3.0 ) << endl ;
	}

	return 0 ;
}
