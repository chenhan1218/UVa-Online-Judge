#include <iostream>
using namespace std ;

int main()
{
	int multiple_1[ 10 ] = { 1, 0, 9, 8, 7, 6, 5, 4, 3, 2 } ;
	int multiple_3[ 10 ] = { 7, 0, 3, 6, 9, 2, 5, 8, 1, 4 } ;
	int multiple_7[ 10 ] = { 3, 0, 7, 4, 1, 8, 5, 2, 9, 6 } ;
	int multiple_9[ 10 ] = { 9, 0, 1, 2, 3, 4, 5, 6, 7, 8 } ;

	int **multiple = new int *[ 10 ] ;

	multiple[ 1 ] = multiple_1 ;
	multiple[ 3 ] = multiple_3 ;
	multiple[ 7 ] = multiple_7 ;
	multiple[ 9 ] = multiple_9 ;

	long long int n ,dealing_n ;
	int digits ;

	int remainder_n , remainder ;

	while( cin >> n )
	{
		remainder_n = n % 10 ;
		dealing_n = n ;
		digits = 0 ;

		while( dealing_n != 0 )
		{
			remainder = dealing_n % 10 ;
			dealing_n = ( dealing_n + multiple[ remainder_n ][ remainder ] * n ) / 10 ;
			digits++ ;
		}

		cout << digits << endl ;
	}

	return 0 ;
}
