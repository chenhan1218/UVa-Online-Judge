#include <iostream>
#include <vector>
using namespace std ;

#define MaxN 20000

int
main()
{
	int		n = 0 ;
	int		numTrack = 0 ;
	int		track = 0 ;
	vector<int>		accumulate[ MaxN + 1 ] ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> n >> numTrack )
	{
		for( i = 0 ; i <= n ; i++ )
			accumulate[ i ].clear() ;

		for( i = 0 ; i < numTrack ; i++ )
		{
			cin >> track ;

			for( j = n ; j - track > 0 ; j-- )
			{
				if( accumulate[ j - track ].size() > 0 )
				{
					accumulate[ j ] = accumulate[ j - track ] ;
					accumulate[ j ].push_back( track ) ;
				}
			}

			accumulate[ track ].assign( 1, track ) ;
		}

		i = n ;
		while( accumulate[ i ].size() == 0 )
			i-- ;

		for( j = 0 ; j < accumulate[ i ].size() ; j++ )
			cout << accumulate[ i ][ j ] << " " ;
		cout << "sum:" << i << endl ;
	}

	return 0 ;
}
