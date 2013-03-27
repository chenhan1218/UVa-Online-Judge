#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int n ;
	double k ;

	long long int answer ;

	while( cin >> n >> k )
	{
		answer = static_cast< int >( pow( k , 1.0 / n ) * 2.0 ) ;
		answer = ( answer + 1 ) / 2 ;
		cout << answer << endl ;


/*		cout << pow( k , 1.0 / n ) << endl ;
*/	}

	return 0 ;
}
