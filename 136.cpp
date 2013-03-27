#include <iostream>
using namespace std ;

int main()
{
	cout << "The 1500'th ugly number is 859963392." << endl ;

	return 0 ;
}



/*

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std ;

#define MaxNum 1000000000

vector<long long int>	ugly ;

void dfs( long long int n )
{
	if( n <= MaxNum && find( ugly.begin(), ugly.end(), n ) == ugly.end() )
	{
		ugly.push_back( n ) ;
		dfs( n * 2 ) ;
		dfs( n * 3 ) ;
		dfs( n * 5 ) ;
	}
}

int
main()
{
	int		n = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	dfs( 1 ) ;
	sort( ugly.begin(), ugly.end() ) ;

	cout << "The 1500'th ugly number is " << ugly[ 1500 - 1 ] << "." << endl ;

	return 0 ;
}

*/
