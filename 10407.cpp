#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std ;

int gcd( long long int a, long long int b )
{
	if( a < 0 )
		a = -1 * a ;
	if( b < 0 )
		b = -1 * b ;

	while( b != 0 )
	{
		a %= b ;
		swap( a, b ) ;
	}

	return a ;
}

int
main()
{
	vector<int>	v ;
	long long int		n = 0 ;
	long long int		maxd = 0 ;
	long long int		d = 0 ;
	long long int		r = 0 ;
	long long int		i = 0 ; // loop counter
	long long int		j = 0 ; // loop counter

	while( cin >> n && n != 0 )
	{
		v.clear() ;
		v.push_back( n ) ;

		while( cin >> n && n != 0 )
		{
			if( find( v.begin(), v.end(), n ) == v.end() )
			{
				v.push_back( n ) ;
			}
		}

		maxd = abs( v[ 1 ] - v[ 0 ] ) ;
		for( i = 2 ; i < v.size() ; i++ )
		{
			maxd = gcd( maxd, v[ i ] - v[ i - 1 ] ) ;
		}

		for( i = 1 ; i <= maxd ; i++ )
		{
			if( maxd % i == 0 )
			{
				d = maxd / i ;

				r = v[ 0 ] % d ;
				if( r < 0 )
					r += d ;

				for( j = 1 ; j < v.size() ; j++ )
				{
					if( ( v[ j ] - r ) % d != 0 )
						break ;
				}

				if( j < v.size() ) // remainder is not the same
					continue ;
				else
					break ;
			}
		}

		cout << d << endl ;
	}

	return 0 ;
}
