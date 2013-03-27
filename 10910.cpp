#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	int cases , N , T , P , m , n ;
	double answer ;

	cin >> cases ;

	for( int i = 1 ; i <= cases ; i++ )
	{
		cin >> N >> T >> P ;

		m = T - P * N + N - 1 ;
		n = N - 1 ;

		if( 2 * n > m )
		{
			n = m - n ;
		}

		if( n == 0 )
		{
			cout << "1" << endl ;
		}
		else
		{
			answer = m ;

			for( int i = 2 ; i <= n ; i++ )
			{
				m-- ;
				answer *= m ;

				answer /= i ;
			}

			cout << static_cast<long long int>( answer + 0.5 ) << endl ;
		}
	}

	return 0 ;
}
