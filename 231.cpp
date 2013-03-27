#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std ;

//Now we implement is longest decrease subsequence, but we still call the 
//function lis()
//
//http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence
//
//The pseudo-code is show below:
//
//func lis( a )
//   initialize best to an array of 0's.
//   for ( i from 1 to n )
//      best[i] = 1
//      for ( j from 1 to i - 1 )
//         if ( a[i] > a[j] )
//            best[i] = max( best[i], best[j] + 1 )
//   return max( best )
//
int lis( const vector<int> &missiles )
{
	vector<int> best( missiles.size() ) ;

	for( vector<int>::size_type i = 0 ; i < missiles.size() ; i++ )
	{
		best[ i ] = 1 ;

		for( vector<int>::size_type j = 0 ; j < i ; j++ )
		{
			// If missiles[ j ] is larger than missiles[ i ]. (that is, decreasing.)
			if( missiles[ i ] <= missiles[ j ] )
			{
				best[ i ] = max( best[ i ], best[ j ] + 1 ) ;
			}
		}
	}

	return *max_element( best.begin(), best.end() ) ;
}

int 
main()
{
	int		test = 0 ;
	int		i = 0 ; // loop counter

	for( test = 1 ; ; test++ )
	{
		vector<int>	missiles ;
		int		lenLongestDecreasing = 0 ;
		int		buffer = 0 ;
		while( cin >> buffer )
		{
			if( buffer == -1 )
			{
				break ;
			}
			else
			{
				missiles.push_back( buffer ) ;
			}
		}

		if( missiles.size() == 0 )
		{
			break ;
		}

		//Now we have to implement Longest Increasing Subsequence algorithm.
		lenLongestDecreasing = lis( missiles ) ;

		if( test > 1 )
		{
			cout << endl ;
		}
		cout << "Test #" << test << ":" << endl ;
		cout << "  maximum possible interceptions: " << lenLongestDecreasing << endl ;
	}

	return 0 ;
}
