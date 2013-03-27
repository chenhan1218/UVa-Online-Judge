#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>
#define MaxN 1000 

bool cmp( int *a, int *b )
{
	return a[ 0 ] * b[ 1 ] < a[ 1 ] * b[ 0 ] ;
}

int
main()
{
	int		t = 0 ;
	int		n = 0 ;
	int*	job[ MaxN + 1 ] ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 0 ; i <= MaxN ; i++ )
	{
		job[ i ] = new int[ 3 ] ;
	}

	cin >> t ;
	for( i = 1 ; i <= t ; i++ )
	{
		cin >> n ;

		for( j = 0 ; j < n ; j++ )
		{
			cin >> job[ j ][ 0 ] >> job[ j ][ 1 ] ;
			job[ j ][ 2 ] = j + 1 ;
		}

		stable_sort( job, job + n, cmp ) ;

		// The outputs of two consecutive cases will be separated by a blank line.
		if( i > 1 )
		{
			cout << endl ;
		}
		cout << job[ 0 ][ 2 ] ;
		for( j = 1 ; j < n ; j++ )
		{
			cout << " " << job[ j ][ 2 ] ;
		}
		cout << endl ;
	}

	return 0 ;
}
