#include <iostream>
using namespace std ;

int main()
{
	double NCOWS , NCARS , NSHOW ;
	double intermediate_multi ;
	double answer ;

	cout.setf( ios::fixed ) ;
	cout.precision( 5 ) ;

	while( cin >> NCOWS >> NCARS >> NSHOW )
	{
		intermediate_multi = NCOWS + NCARS - 1 ;

		answer = NCARS / ( intermediate_multi + 1.0 ) 
			* ( intermediate_multi ) / ( intermediate_multi - NSHOW ) ;

		cout << answer << endl ;
	}

	return 0 ;
}
