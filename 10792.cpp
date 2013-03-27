#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int N ;
	long double r , d , h1 , answer ;
	cin >> N ;

	cout.setf( ios::fixed ) ;
	cout.precision( 4 ) ;

	for( int cases = 1 ; cases <= N ; cases++ )
	{
		cin >> r >> d >> h1 ;

		answer = acos( ( r - d ) / r ) - acos( ( r - h1 ) / r ) ;
		answer = r - ( r - d ) * cos( answer ) ;

		answer = 2 * answer - h1 ;

		cout << "Case " << cases << ": " << answer << endl ;
	}

	return 0 ;
}
