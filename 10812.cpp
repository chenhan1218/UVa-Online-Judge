#include <iostream>
using namespace::std ;

int main()
{
	long long int cases ;
	cin >> cases ;

	long long int input_first, input_second ;
	long long int first , second ;

	for( long long int i = 1 ; i <= cases ; i++ )
	{
		cin >> input_first >> input_second ;

		if( input_first >= input_second && ( first = input_first + input_second ) % 2 == 0 )
		{
			first /= 2 ;
			second = ( input_first - input_second ) / 2 ;

			cout << first << " "
				<< second << endl ;
		}
		else
		{
			cout << "impossible" << endl ;
		}
	}

	return 0 ;
}
