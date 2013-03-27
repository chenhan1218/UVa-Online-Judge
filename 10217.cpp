#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	cout.setf( ios::fixed ) ;
	cout.precision( 2 ) ;
	
	double N ;
	double best_floating_point_position ;
	int best_integer_position ;

	while( cin >> N )
	{
		best_floating_point_position = ( pow( 4 * N + 1 , 0.5 ) - 1 ) / 2.0 ;
		best_integer_position = (int)( floor( best_floating_point_position ) ) + 1 ;

		cout << best_floating_point_position << " " << best_integer_position << endl ;
	}

	return 0 ;
}
