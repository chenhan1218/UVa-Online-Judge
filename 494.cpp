#include <iostream>
using namespace std ;

#include <string>

int main()
{
	char c ;

	int word = 0 , dealingword = 0 ;

	int ascii_a = static_cast<int>('a') , ascii_A = static_cast<int>('A') ;

	while( cin.get( c ) )
	{
		if( c != '\n' )
		{
			if( 
( static_cast<int>( c ) - ascii_a < 26 && static_cast<int>( c ) - ascii_a >= 0 )
||
( static_cast<int>( c ) - ascii_A < 26 && static_cast<int>( c ) - ascii_A >= 0 )
				)
			{
				if( dealingword  == 0 )
				{
					dealingword = 1 ;
					word++ ;
				}
			}
			else
			{
				dealingword = 0 ;
			}

			
		}
		else
		{
			cout << word << endl ;
			word = 0 ;
			dealingword = 0 ;
		}
	}

	return 0 ;
}
