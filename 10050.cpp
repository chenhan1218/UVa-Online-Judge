#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define True 1
#define False 0
#define MaxP 100
#define MaxN 3650

int
main()
{
	int		T = 0 ;
	int		N = 0 ;
	int		P = 0 ;
	int		h[ MaxP + 1 ] = { 0 } ;
	bool	hartal[ MaxN + 1 ] = { 0 } ;
	int		loseWorkingDay = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	// The first line of the input consists of a single integer T giving the 
	// number of test cases to follow.
	cin >> T ;

	for( i = 1 ; i <= T ; i++ )
	{
		// The first line of each test case contains an integer N giving the 
		// number of days over which the simulation must be run.
		cin >> N ;

		for( j = 1 ; j <= N ; j++ )
		{
			hartal[ j ] = False ;
		}

		// The next line contains another integer P representing the number of 
		// political parties in this case.
		cin >> P ;

		// The i­th of the next P lines contains a positive integer hi 
		// (which will never be a multiple of 7) giving the hartal parameter 
		// for party i.
		for( j = 1 ; j <= P ; j++ )
		{
			cin >> h[ j ] ;
		}

		for( j = 1 ; j <= P ; j++ )
		{
			for( k = 1 ; h[ j ] * k <= N ; k++ )
			{
				hartal[ h[ j ] * k ] = True ;
			}
		}

		loseWorkingDay = 0 ;
		for( j = 1 ; j <= N ; j++ )
		{
			if( j % 7 == 6 || j % 7 == 0 )
			{
				continue ;
			}

			if( hartal[ j ] == True )
			{
				loseWorkingDay++ ;
			}
		}

		cout << loseWorkingDay << endl ;
	}

	return 0 ;
}
