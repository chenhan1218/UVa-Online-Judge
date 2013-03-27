#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
	long long int numerator , denominator , temp ;

	while( cin >> numerator >> denominator )
	{
		cout << "[" << numerator / denominator ;

		temp = numerator % denominator ;

		if( temp != 0 )
		{
			numerator = denominator ;
			denominator = temp ;

			cout << ";" << numerator / denominator ;

			temp = numerator % denominator ;

			while( temp != 0 )
			{
				numerator = denominator ;
				denominator = temp ;

				cout << "," << numerator / denominator ;

				temp = numerator % denominator ;
			}
		}

		cout << "]" << endl ;
	}

	return 0 ;
}
