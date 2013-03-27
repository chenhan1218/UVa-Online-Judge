#include <iostream>
#include <iomanip>
#include <vector>
using namespace std ;

int
main()
{
	vector<int>	v ;
	int		n = 0 ;
	int		k = 0 ;
	int		buryer = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> n >> k )
	{
		if( n == 0 && k == 0 )
			break ;

		v.clear() ;

		for( i = 1 ; i <= n ; i++ )
		{
			v.push_back( i ) ;
		}

		i = n - 1 ;
		while( v.size() > 1 )
		{
			i = ( i + k ) % v.size() ;

			if( k % ( v.size() - 1 ) == 0 )
			{
				buryer = ( i + v.size() - 1 ) % v.size() ;
			}
			else
			{
				buryer = ( i + ( k % (v.size()-1) ) ) % v.size() ;
			}

			v[ i ] = v[ buryer ] ;
			if( buryer < i )
			{
				i-- ;
			}

			v.erase( v.begin() + buryer ) ;
		}

		cout << 1 + ( n + 1 - v[ 0 ]) % n << endl ;
	}

	return 0 ;
}
