#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	long long int input ;

	long long int denominator ;
	long long int numerator ;
	long long int sum ;

	while( cin >> input )
	{
		sum = static_cast< int >( ( pow( 1.0 + 8.0 * input , 0.5 ) - 1 ) / 2.0 ) ;

		if( ( denominator = input - sum * ( sum + 1 ) / 2 ) == 0 )
		{
			cout << "1" << "/" << sum << endl ;
		}
		else
		{
			numerator = sum + 2 - denominator ;
			cout << numerator << "/" << denominator << endl ;
		}
	}

	return 0 ;
}
