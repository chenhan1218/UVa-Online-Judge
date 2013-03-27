#include <iostream>
using namespace std ;

#include <cctype>

class word
{
	public:
		word() ;
		char characters[ 52 ] ;
		word *next ;
		word *previous ;
};

word::word()
{
	next = NULL ;
	previous = NULL ;
}

void put_to_front( word *head, word *selected_word )
{
	if( selected_word->next != NULL )
	{
		(selected_word->previous)->next = selected_word->next ;
		(selected_word->next)->previous = selected_word->previous ;
	}

	if( head->next != NULL )
	{
		selected_word->next = head->next ;
		(selected_word->next)->previous = selected_word ;
	}
	
	head->next = selected_word ;
	selected_word->previous = head ;
}

int main()
{
	int position = 0, i = 0 ;
	char temp ;
	word *selected_word , *head ;
	head = new word() ;
	word *reading_word = NULL ;
	int length_reading_word = 0 ;
	
	while( 1 )
	{
		cin.get( temp ) ;
		if( isdigit( temp ) )
		{
			// Deal the storing word because the word has finished.
			if( length_reading_word != 0 )
			{
				reading_word->characters[ length_reading_word ] = '\0' ;
				put_to_front( head, reading_word ) ;
					
				reading_word = NULL ;
				length_reading_word = 0 ;
			}

			if( temp == '0' && position == 0 )
			{
				break ;
			}
			else
			{
				position *= 10 ;
				position += (int)temp - (int)('0') ;
			}
		}
		else // Now the character temp is not a digit.
		{
			// Deal the position. If there is a word hasn't been printed.
			if( position != 0 )
			{
				selected_word = head ;
				for( i = 1 ; i <= position ; i++ )
				{
					selected_word = selected_word->next ;
				}
				
				cout << selected_word->characters ;
				
				// Now take the word to the frontest_word.
				put_to_front( head, selected_word ) ;
				
				// Now set the position to the initial value.
				position = 0 ;
			}

			if( isalpha( temp ) )
			{
				if( length_reading_word == 0 )
				{
					reading_word = new word() ;
				}
				
				// Start of storing the character.
				reading_word->characters[ length_reading_word ] = temp ;
				length_reading_word++ ;
			}
			else
			{
				// Deal the storing word because the word has finished.
				if( length_reading_word != 0 )
				{
					reading_word->characters[ length_reading_word ] = '\0' ;
					put_to_front( head, reading_word ) ;
					
					reading_word = NULL ;
					length_reading_word = 0 ;
				}
			}
			cout << temp ;
		}
	}
	
	return 0 ;
}
