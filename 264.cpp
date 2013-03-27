#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	long long int input ;

	int denominator ;
	int numerator ;
	int sum ;

	while( cin >> input )
	{
		sum = static_cast< int >( ( pow( 1.0 + 8.0 * input , 0.5 ) - 1 ) / 2.0 ) ;

		if( sum % 2 == 0 )
		{
			if( ( denominator = input - sum * ( sum + 1 ) / 2 ) == 0 )
			{
				cout << "TERM " << input << " IS " << sum << "/" << "1" << endl ;
			}
			else
			{
				numerator = sum + 2 - denominator ;
				cout << "TERM " << input << " IS " << numerator << "/" << denominator << endl ;
			}
		}
		else
		{
			if( ( numerator = input - sum * ( sum + 1 ) / 2 ) == 0 )
			{
				cout << "TERM " << input << " IS " << "1" << "/" << sum << endl ;
			}
			else
			{
				denominator = sum + 2 - numerator ;
				cout << "TERM " << input << " IS " << numerator << "/" << denominator << endl ;
			}
		}
	}

	return 0 ;
}
