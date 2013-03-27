#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std ;

#define MaxN 5842
#define MaxNum 2000000000

vector<long long int>	humble ;

void dfs( long long int n )
{
	if( n <= MaxNum && find( humble.begin(), humble.end(), n ) == humble.end() )
	{
		humble.push_back( n ) ;
		dfs( n * 2 ) ;
		dfs( n * 3 ) ;
		dfs( n * 5 ) ;
		dfs( n * 7 ) ;
	}
}

int
main()
{
	int		n = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	dfs( 1 ) ;
	sort( humble.begin(), humble.end() ) ;

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}

		if( n % 10 == 1 && n % 100 != 11 )
		{
			cout << "The " << n << "st humble number is " << humble[ n - 1 ] << "." << endl ;
		}
		else if( n % 10 == 2 && n % 100 != 12 )
		{
			cout << "The " << n << "nd humble number is " << humble[ n - 1 ] << "." << endl ;
		}
		else if( n % 10 == 3 && n % 100 != 13 )
		{
			cout << "The " << n << "rd humble number is " << humble[ n - 1 ] << "." << endl ;
		}
		else
		{
			cout << "The " << n << "th humble number is " << humble[ n - 1 ] << "." << endl ;
		}
	}

	return 0 ;
}
