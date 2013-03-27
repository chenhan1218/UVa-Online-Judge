/* Old version
#include <iostream>
using namespace std ;

#define MaxB 1000

int main()
{
	int		a = 0 ;
	int		b = 0 ;
	int		visited[ MaxB ] = { 0 } ;
	int		digits = 0 ;
	int		i = 0 ;

	while( cin >> a >> b && a != 0 && b != 0 )
	{
		fill( visited, visited + MaxB, 0 ) ;

		cout << "." ;
		digits = 0 ;
		while( visited[ a ] == 0 && a != 0 )
		{
			digits++ ;
			visited[ a ] = digits ;

			cout << a * 10 / b ;
			a = ( a * 10 ) % b ;

			if( digits % 50 == 49 )
				cout << endl ;
		}

		if( digits % 50 != 49 )
			cout << endl ;

		if( a != 0 )
		{
			cout << "The last " << digits - visited[ a ] + 1 
				<< " digits repeat forever." << endl ;
		}
		else
		{
			cout << "This expansion terminates." << endl ;
		}

		cout << endl ; //Output for each input instance (including the last input instance) should be followed by a blank line.
	}

	return 0 ;
}
*/

#include <iostream>
#include <string>
using namespace std ;

#define MaxB 1000

int main()
{
	int		a = 0 ;
	int		b = 0 ;
	int		visited[ MaxB ] = { 0 } ;
	int		digits = 0 ;
	string	output ;
	int		i = 0 ;

	while( cin >> a >> b && a != 0 && b != 0 )
	{
		fill( visited, visited + MaxB, 0 ) ;

		output = "." ;
		digits = 0 ;
		while( visited[ a ] == 0 && a != 0 )
		{
			digits++ ;
			visited[ a ] = digits ;

			output += '0' + ( a * 10 / b ) ;
			a = ( a * 10 ) % b ;
		}

		while( output != "" )
		{
			cout << output.substr( 0, 50 ) << endl ;

			if( output.size() >= 50 )
				output = output.substr( 50 ) ;
			else
				output = "" ;
		}

		if( a != 0 )
		{
			cout << "The last " << digits - visited[ a ] + 1 
				<< " digits repeat forever." << endl ;
		}
		else
		{
			cout << "This expansion terminates." << endl ;
		}

		cout << endl ; //Output for each input instance (including the last input instance) should be followed by a blank line.
	}

	return 0 ;
}
