#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>
#define MaxN 1000

int			square[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;

int
main()
{
	int		n = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ;

	cin.sync_with_stdio( false );
	cout.sync_with_stdio( false );

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}

		for( i = 0 ; i < n ; i++ )
		{
			for( j = 0 ; j < n ; j++ )
			{
				cin >> square[ i ][ j ] ;
			}
		}

		for( i = 0 ; i < n - 1 ; i++ )
		{
			for( j = 0 ; j < n - 1 ; j++ )
			{
				if( square[ i ][ j ] + square[ i + 1 ][ j + 1 ] != 
					square[ i ][ j + 1 ] + square[ i + 1 ][ j ] )
				{
					break ;
				}
			}

			if( j < n - 1 )
			{
				break ;
			}
		}

		if( i < n - 1 )
		{
			cout << "not homogeneous" << endl ;
		}
		else
		{
			cout << "homogeneous" << endl ;
		}
	}

	return 0 ;
}
