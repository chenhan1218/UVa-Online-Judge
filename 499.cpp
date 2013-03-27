#include <iostream>
using namespace std ;

#include <cctype>

int main()
{
	int ascii_order[ 256 ] = { 0 } ;

	char input ;
	int order_input , max = 0 ;

	while( cin.get( input ) )
	{
		if( input == '\n' )
		{
			for( int i = 0 ; i < 256 ; i++ )
			{
				if( ascii_order[ i ] == max )
				{
					cout << static_cast<char>( i - 128 ) ;
				}

				ascii_order[ i ] = 0 ;
			}

			cout << " " << max << endl ;
			max = 0 ;
		}
		else
		{
			if( isalpha( input ) )
			{
				order_input = static_cast<int>( input ) + 128 ;
				ascii_order[ order_input ] ++ ;
				if( ascii_order[ order_input ] > max )
				{
					max = ascii_order[ order_input ] ;
				}
			}
		}
	}

	return 0 ;
}
