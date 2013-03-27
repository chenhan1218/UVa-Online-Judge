#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int cases ;
	double d , v , n , answer ;

	cout.setf( ios::fixed ) ;
	cout.precision( 3 ) ;

	cin >> cases ;

	for( int i = 1 ; i <= cases ; i++ )
	{
		cin >> d >> v >> n ;

		if( n <= 0 || v <= 0 || n <= v )
		{
			cout << "Case " << i << ": " << "can't determine" << endl ;
		}
		else
		{
			answer = d / pow( n * n - v * v , 0.5 ) - d / n ;

			cout << "Case " << i << ": " << answer << endl ;
		}
	}

	return 0 ;
}
