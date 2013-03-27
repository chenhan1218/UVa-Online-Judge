#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;

string	source ;

void knuthPermutation( string a, int n )
{
	int		i = 0 ;

	if( n == source.size() )
	{
		cout << a << endl ;
	}
	else
	{
		for( i = 0 ; i <= n ; i++ )
		{
			knuthPermutation( a.substr( 0, i ) + source[ n ] + a.substr( i ), n + 1 ) ;
		}
	}
}

int main()
{
	bool	firstCase = true ;
	int		i = 0 ;
	int		j = 0 ;

	while( cin >> source )
	{
		if( firstCase == true )
			firstCase = false ;
		else
			cout << endl ;

		knuthPermutation( "", 0 ) ;
	}

	return 0 ;
}
