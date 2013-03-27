#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxMissiles 1000000

int		numMissiles = 0 ;
int		missiles[ MaxMissiles + 1 ] = { 0 } ;
int		best[ MaxMissiles + 1 ] = { 0 } ;
int		lenLongestIncreasing = 0 ;
int		previous[ MaxMissiles + 1 ] = { 0 } ;
int		subsequence[ MaxMissiles + 1 ] = { 0 } ;

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
int lis()
{
	int		lenLongestIncreasing = 0 ;
	int		lastPlace = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 1 ; i <= numMissiles ; i++ )
	{
		best[ i ] = 1 ;
		previous[ i ] = 0 ;

		for( j = 1 ; j < i ; j++ )
		{
			// If missiles[ j ] is less than missiles[ i ]. (that is, increasing.)
			if( missiles[ i ] >= missiles[ j ] )
			{
				if( best[ j ] + 1 > best[ i ] )
				{
					best[ i ] = best[ j ] + 1 ;
					previous[ i ] = j ;
				}
			}
		}

		if( best[ i ] > lenLongestIncreasing )
		{
			lenLongestIncreasing = best[ i ] ;
			lastPlace = i ;
		}
	}

	for( i = lenLongestIncreasing ; i >= 1 ; i-- )
	{
		subsequence[ i ] = missiles[ lastPlace ] ;
		lastPlace = previous[ lastPlace ] ;
	}

	return lenLongestIncreasing ;
}

int 
main()
{
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	char	buffer[ 20 ] ;

	cin.getline( buffer, 20 ) ;
	cases = atoi( buffer ) ;
	cin.getline( buffer, 20 ) ;	// absorb the blank line.

	for( i = 1 ; i <= cases ; i++ )
	{
		numMissiles = 0 ;
		while( cin.getline( buffer, 20 ) )
		{
			if( buffer[ 0 ] == '\0' )
			{
				break ;
			}
			else
			{
				numMissiles++ ;
				missiles[ numMissiles ] = atoi( buffer ) ;
			}
		}

		//Now we have to implement Longest Increasing Subsequence algorithm.
		lenLongestIncreasing = lis() ;

		// For each test case, the output must follow the description below. 
		//The outputs of two consecutive cases will be separated by a blank line.
		if( i > 1 )
		{
			cout << endl ;
		}

		cout << "Max hits: " << lenLongestIncreasing << endl ;
		for( j = 1 ; j <= lenLongestIncreasing ; j++ )
		{
			cout << subsequence[ j ] << endl ;
		}
	}

	return 0 ;
}

