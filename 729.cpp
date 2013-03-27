#include <iostream>
#include <string>
#include <algorithm>
using namespace std ;

int main()
{
	int		n = 0 ;
	int		h = 0 ;
	int		casenum = 0 ;
	string	str ;
	int		i = 0 ;
	
	cin >> casenum ;
	for( i = 0 ; i < casenum ; i++ )
	{
		cin >> n >> h ;
		if( i != 0 )
		{
			cout << endl ;
		}

		str = string( n-h, '0') + string( h, '1' ) ;
		do
		{
			cout << str << endl ;
		} while( next_permutation( str.begin(), str.end() ) == true ) ;
	}
	
	return 0 ;
}
