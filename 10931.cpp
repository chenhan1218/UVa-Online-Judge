#include <iostream>
using namespace std ;

int main()
{
	int binary_representation[ 32 ] = { 0 } ;
	int I , binary_length , p ;

	while( cin >> I )
	{
		if( I == 0 )
		{
			break ;
		}

		binary_length = 0 ;
		while( I > 0 )
		{
			binary_representation[ binary_length ] = I % 2 ;

			I /= 2 ;
			binary_length++ ;
		}

		cout << "The parity of " ;

		binary_length-- ;
		p = 0 ;
		while( binary_length >= 0 )
		{
			cout << binary_representation[ binary_length ] ;
			p += binary_representation[ binary_length ] ;

			binary_length-- ;
		}

		cout << " is " << p << " (mod 2)." << endl ;
	}

	return 0 ;
}
