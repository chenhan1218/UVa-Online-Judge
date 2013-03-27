#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	long long int S , D ;
	long long int answer ;

	while( cin >> S >> D )
	{
		D = 2 * D + S * ( S - 1 ) ;

		answer = static_cast<int>( ceil( ( pow( 1.0 + 4.0 * D , 0.5 ) - 1 ) / 2.0 ) ) ;

		cout << answer << endl ;
	}

	return 0 ;
}
