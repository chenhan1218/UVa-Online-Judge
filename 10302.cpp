#include <iostream>
using namespace::std ;

int main()
{
	long long int input ;

	while( cin >> input )
	{
		input = input * ( input + 1) / 2 ;
		input *= input ;
		cout << input << endl ;
	}

	return 0 ;
}
