#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int cubic[ 102 ] ;
	for( int i = 0 ; i <= 101 ; i++ )
	{
		cubic[ i ] = i * i * i ;
	}

	double input , n ;
	int first , last , median , a ;

	cout.setf( ios::fixed ) ;
	cout.precision( 4 ) ;

	while( cin >> input )
	{
		if( input == 0 )
		{
			break ;
		}

		first = 0 ;
		last = 101 ;

		while( last - first > 1 )
		{
			median = ( first + last ) / 2 ;
			if( cubic[ median ] > input )
			{
				last = median ;
			}
			else
			{
				first = median ;
			}
		}

		a = first ;

		n = ( 2 * a + input / a / a ) / 3.0 ;

		cout << n << endl ;
	}

	return 0 ;
}
