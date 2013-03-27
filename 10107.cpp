#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

void insertionSort( int *series, int i )
{
	while( i > 1 && series[ i ] < series[ i - 1 ] )
	{
		swap( series[ i ] , series[ i - 1 ] ) ;
		i-- ;
	}
}

int main()
{
	int	series[ 10001 ] = { 0 } ;
	int N = 0 ;
	int	i = 0 ; // loop counter

	for( i = 1 ; cin >> series[ i ] ; i++ )
	{
		insertionSort( series, i ) ;

		if( i % 2 == 0 )
		{
			cout << ( series[ i / 2 ] + series[ i / 2 + 1 ] ) / 2 << endl ;
		}
		else
		{
			cout << series[ (i+1) / 2 ] << endl ;
		}
	}

	return 0 ;
}
