#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>
#include <sstream>
#include <queue>
using std::istringstream ;

#define MaxN 1000

int		cross[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;
vector<int>	unsafe[ MaxN + 1 ] ;

int
main()
{
	int		t = 0 ;
	int		w = 0 ;
	int		n = 0 ;
	string	buffer ;
	int		street = 0 ;
	int		temp ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	cross[ 1 ][ 0 ] = 1 ;

	cin >> t ;
	for( i = 1 ; i <= t ; i++ )
	{
		cin >> w >> n ;
		getline( cin, buffer ) ;	// absorb the previous empty line.

		for( j = 1 ; j <= w ; j++ )
		{
			getline( cin, buffer ) ;
			istringstream stream( buffer ) ;
			stream >> street ;
			while( stream >> temp )
			{
				unsafe[ street ].push_back( temp ) ;
			}
			sort( unsafe[ street ].begin(), unsafe[ street ].end() ) ;
		}

		for( j = 1 ; j <= w ; j++ )
		{
			for( k = 1 ; k <= n ; k++ )
			{
				if( unsafe[ j ].size() != 0 && k == unsafe[ j ].front() )
				{
					cross[ j ][ k ] = 0 ;
					unsafe[ j ].erase( unsafe[ j ].begin() ) ;
				}
				else
				{
					cross[ j ][ k ] = cross[ j - 1 ][ k ] + cross[ j ][ k - 1 ] ;
				}
			}
		}

		// The outputs of two consecutive cases will be separated by a blank line.
		if( i > 1 )
		{
			cout << endl ;
		}
		cout << cross[ w ][ n ] << endl ;
	}

	return 0 ;
}
