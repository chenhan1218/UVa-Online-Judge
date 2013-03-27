#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int ascii_a = static_cast<int>( 'a' ) ;

	bool game_not_over = 1 ;

	int round , correct_letters , strokes ;
	int ascii_word , ascii_guess ;
	char input ;

	while( cin >> round )
	{
		if( round == -1 )
		{
			break ;
		}

		cout << "Round " << round << endl ;

		int letters[ 26 ] = { 0 } ;

		correct_letters = 0 ;

		cin.get() ;
		while( cin.get( input ) )
		{
			if( input == '\n' )
			{
				break ;
			}

			ascii_word = static_cast<int>( input ) - ascii_a ;
			if( letters[ ascii_word ] == 0 )
			{
				letters[ ascii_word ] = 2 ;
				correct_letters++ ;
			}
		}

		game_not_over = 1 ;
		strokes = 0 ;

		while( cin.get( input ) )
		{
			if( input == '\n' )
			{
				break ;
			}

			if( game_not_over )
			{
				ascii_guess = static_cast<int>( input ) - ascii_a ;

				if( letters[ ascii_guess ] == 0 )
				{
					letters[ ascii_guess ] = -1 ;

					strokes++ ;

					if( strokes >= 7 )
					{
						game_not_over = 0 ;
						correct_letters = 0 ;

						cout << "You lose." << endl ;
					}
				}
				else if( letters[ ascii_guess ] == 2 )
				{
					letters[ ascii_guess ] = 1 ;

					correct_letters-- ;

					if( correct_letters == 0 )
					{
						game_not_over = 0 ;

						cout << "You win." << endl ;
					}
				}
			}
		}

		if( correct_letters > 0 )
		{
			cout << "You chickened out." << endl ;
		}
	}

	return 0 ;
}
