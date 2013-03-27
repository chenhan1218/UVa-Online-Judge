#include <iostream>
using namespace std ;

int main()
{
	int even = 0 ;

	char input ;

	char dealing ;

	while( cin.get( input ) )
	{
		if( input != '\n' )
		{
			if( input == '\"' )
			{
				even = ( even + 1 ) % 2 ;
				if( even == 1 )
				{
					cout << "``" ;
				}
				else
				{
					cout << "\'\'" ;
				}
			}
			else
			{
				cout << input ;
			}
		}
		else
		{
			cout << endl ;
		}
	}

	return 0 ;
}
