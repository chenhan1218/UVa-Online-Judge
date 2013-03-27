#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int S , N , I ;
	long double p , inverse_p , answer ;

	cin >> S ;

	cout.setf( ios::fixed ) ;
	cout.precision( 4 ) ;

	for( int i = 1 ; i <= S ; i++ )
	{
		cin >> N >> p >> I ;

		if( p == 0 )
		{
			cout << "0.0000" << endl ;
		}
/*		else if( p == 1 )
		{
			if( I == 1 )
			{
				cout << "1.0000" << endl ;
			}
			else
			{
				cout << "0.0000" << endl ;
			}
		}
*/		else
		{
			inverse_p = 1 - p ;

			answer = p * pow( inverse_p , I - 1 ) / ( 1.0 - pow( inverse_p , N ) ) ;

			cout << answer << endl ;
		}
	}

	return 0 ;
}
