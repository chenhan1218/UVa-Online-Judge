#include <iostream>
using namespace std ;

#include <cctype>

int main()
{
	char input ;

	int times = 0 ;

	while( ( input =cin.get() ) != EOF )
	{
		if( isdigit( input ) )
		{
			times += input - '0' ;
		}
		else if( input == '\n' || input == '!' )
		{
			cout << endl ;
		}
		else
		{
			if( input == 'b' )
			{
				while( times > 0 )
				{
					cout << " " ;
					times-- ;
				}
			}
			else
			{
				while( times > 0 )
				{
					cout << input ;
					times-- ;
				}
			}
		}
	}

	return 0 ;
}
