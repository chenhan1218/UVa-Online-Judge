#include <iostream>
#include <sstream>
#include <string>
using namespace std ;

int main()
{
	int		cases = 0 ;
	string	str ;
	
	cin >> cases ;
	getline( cin, str ) ; // absorb the end of line
	for( int currentCase = 1 ; currentCase <= cases ; currentCase++ )
	{
		getline( cin, str ) ;
		
		char	c ;
		int		num = 0 ;
		istringstream	is( str ) ;
		string		output ;
		while( is >> c >> num )
		{
			output.insert( output.end(), num, c ) ;
		}
		
		cout << "Case " << currentCase << ": " << output << endl ;
	}
}
