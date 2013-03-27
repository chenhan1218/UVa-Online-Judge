#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std ;

#define g 34943

int main()
{
	string	input ;
	long long int	value = 0 ;
	long long int	crc = 0 ;
	int		i = 0 ; // loop counter

	while( getline( cin, input ) )
	{
		if( input.size() > 0 && input[ 0 ] == '#' )
			break ;

		ostringstream	s ;
		value = 0 ;
		for( i = 0 ; i < input.size() ; i++ )
			value = ( ( value << 8 ) + (int)input[ i ] ) % g ;

		value = ( value << 16 ) % g ;
		if( value == 0 )
			crc = 0 ;
		else
			crc = g - value ;

		s << setw( 4 ) << setfill('0') << hex << uppercase << crc ;
		cout << s.str().substr( 0, 2 ) << ' ' << s.str().substr( 2 ) << endl ;
	}

	return 0 ;
}
