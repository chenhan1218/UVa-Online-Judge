#include <iostream>
using namespace std ;

int main()
{
	char input ;

	char switch_input ;

	int ascii_2 = static_cast< int >( '2' ) ;
	int ascii_9 = static_cast< int >( '9' ) ;

	while( cin.get( input ) )
	{
		if( input == '\n' || input == ' ' )
		{
			cout << input ;
		}
		else if( input >= ascii_2 && input <= ascii_9 )
		{
			switch_input = input - 1 ;
			cout << switch_input ;
		}
		else
		{
			switch( input )
			{
				case '0' :
					switch_input = '9' ;
					break ;

				case '-' :
					switch_input = '0' ;
					break ;

				case '=' :
					switch_input = '-' ;
					break ;

				case 'W' :
					switch_input = 'Q' ;
					break ;

				case 'E' :
					switch_input = 'W' ;
					break ;

				case 'R' :
					switch_input = 'E' ;
					break ;

				case 'T' :
					switch_input = 'R' ;
					break ;

				case 'Y' :
					switch_input = 'T' ;
					break ;

				case 'U' :
					switch_input = 'Y' ;
					break ;

				case 'I' :
					switch_input = 'U' ;
					break ;

				case 'O' :
					switch_input = 'I' ;
					break ;

				case 'P' :
					switch_input = 'O' ;
					break ;

				case '[' :
					switch_input = 'P' ;
					break ;

				case ']' :
					switch_input = '[' ;
					break ;

				case '\\' :
					switch_input = ']' ;
					break ;

				case 'S' :
					switch_input = 'A' ;
					break ;

				case 'D' :
					switch_input = 'S' ;
					break ;

				case 'F' :
					switch_input = 'D' ;
					break ;

				case 'G' :
					switch_input = 'F' ;
					break ;

				case 'H' :
					switch_input = 'G' ;
					break ;

				case 'J' :
					switch_input = 'H' ;
					break ;

				case 'K' :
					switch_input = 'J' ;
					break ;

				case 'L' :
					switch_input = 'K' ;
					break ;

				case ';' :
					switch_input = 'L' ;
					break ;

				case '\'' :
					switch_input = ';' ;
					break ;

				case 'X' :
					switch_input = 'Z' ;
					break ;

				case 'C' :
					switch_input = 'X' ;
					break ;

				case 'V' :
					switch_input = 'C' ;
					break ;

				case 'B' :
					switch_input = 'V' ;
					break ;

				case 'N' :
					switch_input = 'B' ;
					break ;

				case 'M' :
					switch_input = 'N' ;
					break ;

				case ',' :
					switch_input = 'M' ;
					break ;

				case '.' :
					switch_input = ',' ;
					break ;

				case '/' :
					switch_input = '.' ;
					break ;

			}

			cout << switch_input ;
		}
	}

	return 0 ;
}
