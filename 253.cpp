#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std ;

map<string,bool> m ;

void transfer( char &a, char &b, char &c, char &d )
{
	char	temp ;
	temp = a ;
	a = b ;
	b = c ;
	c = d ;
	d = temp ;
}

void dfs( string a )
{
	if( m.find( a ) == m.end() ) // Not found in map
	{
		string	temp ;
		m[ a ] = true ;

		temp = a ;
		transfer( temp[ 2 ], temp[ 3 ], temp[ 5 ], temp[ 4 ] ) ;
		dfs( temp ) ;

		temp = a ;
		transfer( temp[ 2 ], temp[ 6 ], temp[ 5 ], temp[ 1 ] ) ;
		dfs( temp ) ;

		temp = a ;
		transfer( temp[ 1 ], temp[ 4 ], temp[ 6 ], temp[ 3 ] ) ;
		dfs( temp ) ;
	}
}

int main()
{
	string	source ;
	int		i = 0 ; // loop counter

	while( cin >> source )
	{
		m.clear() ;
		dfs( ' ' + source.substr( 0, 6 ) ) ;

		// Not found in front cube's permutation
		if( m.find( ' ' + source.substr( 6 ) ) == m.end() )
			cout << "FALSE" << endl ;
		else
			cout << "TRUE" << endl ;
	}

	return 0 ;
}
