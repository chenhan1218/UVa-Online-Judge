#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	double a , b , c ;

	long double p , answer ;

	cout.setf( ios::fixed );
	cout.precision( 3 ) ;

	while( cin >> a >> b >> c )
	{
		if( a <= 0 || b <= 0 || c <= 0 )
		{
			cout << "The radius of the round table is: 0.000" << endl ;
		}
		else
		{
			p = ( a + b + c ) / 2.0 ;
			answer = ( p - a ) / p * ( p - b ) * ( p - c ) ;

			answer = pow( answer , 0.5 ) ;

			cout << "The radius of the round table is: " << answer << endl ;
		}
	}

	return 0 ;
}
