#include <iostream>
using namespace std ;

int main()
{
	char input ;

	int answer = 0 , input_digit , addition_digits = 0 ;

	while( cin.get( input ) )
	{
		if( input == '\n')
		{
			cout << answer << endl ;
			answer = 0 ;
			addition_digits = 0 ;

			cin.get( input ) ;

			switch( input )
			{
				case '0' :
					input_digit = 0 ;
					break ;
				case '1' :
					input_digit = 1 ;
					break ;
				case '2' :
					input_digit = 2 ;
					break ;
			}

			if( input_digit == 0 )
			{
				break ;
			}
			else
			{
				addition_digits = input_digit ;
				answer = input_digit ;
			}
		}
		else
		{
			switch( input )
			{
				case '0' :
					input_digit = 0 ;
					break ;
				case '1' :
					input_digit = 1 ;
					break ;
				case '2' :
					input_digit = 2 ;
					break ;
			}

			addition_digits += input_digit ;
			answer = 2 * answer + addition_digits ;
		}
	}

	return 0 ;
}
