#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int C , N , finalgrade ;
	cin >> C ;

	double average , answer ;

	cout.setf( ios::fixed ) ;
	cout.precision( 3 ) ;

	for( int m = 1 ; m <= C ; m++ )
	{
		cin >> N ;

		int number[ 101 ] = { 0 } ;

		average = 0 ;
		answer = 0 ;

		for( int i = 1 ; i <= N ; i++ )
		{
			cin >> finalgrade ;

			average += finalgrade ;
			number[ finalgrade ] ++ ;
		}

		average /= N ;

		for( int i = 100 ; i > average ; i-- )
		{
			answer += number[ i ] ;
		}

		cout << answer / N * 100 << "%" << endl ;
	}

	return 0 ;
}
