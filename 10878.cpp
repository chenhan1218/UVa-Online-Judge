#include <iostream>
using namespace std ;

int main()
{
	char input[ 20 ] ;
	int ascii_char ;

	int exponent_2[ 7 ] = { 1 , 2 , 4 , 8 , 16 , 32 , 64 } ;

	cin.getline( input , 20 ) ;

	while( cin.getline( input , 20 ) )
	{
		if( input[ 0 ] == '_' )
		{
			break ;
		}

		ascii_char = 0 ;
		for( int i = 0 ; i <= 2 ; i++ )
		{
			if( input[ 9 - i ] == 'o' )
			{
				ascii_char += exponent_2[ i ] ;
			}
		}
		for( int i = 3 ; i <= 6 ; i++ )
		{
			if( input[ 8 - i ] == 'o' )
			{
				ascii_char += exponent_2[ i ] ;
			}
		}

		cout << static_cast<char>( ascii_char ) ;
	}

	return 0 ;
}
