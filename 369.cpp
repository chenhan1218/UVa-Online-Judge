#include <iostream>
using namespace std ;

int main()
{
	int N , M , dealing_N ;
	long double answer ;

	cout.setf( ios::fixed ) ;
	cout.precision( 0 ) ;

	while( cin >> N >> M )
	{
		if( N == 0 && M == 0 )
		{
			break ;
		}

		answer = N ;
		dealing_N = N ;

		for( int i = 2 ; i <= M ; i++ )
		{
			answer /= i ;
			dealing_N-- ;
			answer *= dealing_N ;
		}

		cout << N << " things taken " << M << " at a time is " << answer << " exactly." << endl ;
	}

	return 0 ;
}
