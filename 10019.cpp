#include <iostream>
using namespace std ;

int main()
{
	int hexadecimal_1s[ 10 ] = { 0 , 1 , 1 , 2 , 1 , 2 , 2 , 3 , 1 , 2 } ;

	int N , M , dealing_M , b1 , b2 ;

	cin >> N ;

	for( int i = 1 ; i <= N ; i++ )
	{
		cin >> M ;

		dealing_M = M ;
		b1 = 0 ;

		while( dealing_M != 0 )
		{
			b1 += dealing_M & 0x01 ;
			dealing_M >>= 1 ;
		}

		dealing_M = M ;
		b2 = 0 ;

		while( dealing_M != 0 )
		{
			b2 += hexadecimal_1s[ dealing_M % 10 ] ;
			dealing_M /= 10 ;
		}

		cout << b1 << " " << b2 << endl ;
	}

	return 0 ;
}
