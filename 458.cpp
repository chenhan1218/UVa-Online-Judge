#include <iostream>
using namespace std ;

int main()
{
	char c;

	while( cin.get( c ) )
	{
		if( c != '\n' )
		{
			c -= 7 ;
			cout << c ;
		}
		else
		{
			cout << endl ;
		}
	}

	return 0 ;
}
