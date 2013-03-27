#include <iostream>
using namespace std ;

int main()
{
	long long int input , remainder , answer ;

	while( cin >> input )
	{
		if( input == 0 )
		{
			break ;
		}

		remainder = input % 9 ;

		if( remainder == 0 )
		{
			answer = ( input / 9 ) * 10 - 1 ;
			cout << answer << " " ;
			answer++ ;
			cout << answer << endl ;
		}
		else
		{
			answer = ( input / 9 ) * 10 + remainder ;
			cout << answer << endl ;
		}
	}

	return 0 ;
}
