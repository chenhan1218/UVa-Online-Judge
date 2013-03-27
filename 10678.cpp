#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	double pi_divide4 = acos( 0 ) / 2.0 ;

	int N , D , L ;
	double answer ;

	cin >> N ;

	cout.setf( ios::fixed ) ;
	cout.precision( 3 ) ;

	for( int i = 1 ; i <= N ; i++ )
	{
		cin >> D >> L ;

		answer = pi_divide4 * L * pow( ( L + D ) * ( L - D ) , 0.5 ) ;

		cout << answer << endl ;
	}

	return 0 ;
}
