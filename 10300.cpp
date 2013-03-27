#include <iostream>
using namespace::std ;

int main()
{
	int n ;
	cin >> n ;

	int f ;

	long int farmyard , animals , envir ;

	long long int answer ;

	for( int i = 1 ; i <= n ; i++ )
	{
		answer = 0 ;

		cin >> f ;

		for( int j = 1 ; j <= f ; j++ )
		{
			cin >> farmyard >> animals >> envir ;

			answer += farmyard * envir ;
		}
		cout << answer << endl ;
	}

	return 0 ;
}
