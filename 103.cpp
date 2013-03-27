#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxBox 30
#define MaxDim 10

int		k, n ;
int**	boxes ;
int*	best ;
int*	boxNumbered ;
int*	previous ;
int*	longestNesting ;
int		lenLongestNesting ;
int		largestBoxInLis ;

void allocate()
{
	int		i = 0 ; // loop counter

	boxes = new int* [ MaxBox + 1 ] ;
	for( i = 1 ; i <= MaxBox ; i++ )
	{
		boxes[ i ] = new int [ MaxDim + 1 ] ;
	}

	best = new int [ MaxBox + 1 ] ;
	boxNumbered = new int [ MaxBox + 1 ] ;
	previous = new int [ MaxBox + 1 ] ;
	longestNesting = new int [ MaxBox + 1 ] ;
}

void readData()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	for( i = 1 ; i <= k ; i++ )
	{
		boxNumbered[ i ] = i ;
		previous[ i ] = 0 ;

		for( j = 1 ; j <= n ; j++ )
		{
			cin >> boxes[ i ][ j ] ;
		}
	}
}

void sortDimension()
{
	int		i = 0 ; // loop counter
	for( i = 1 ; i <= k ; i++ )
	{
		sort( &boxes[ i ][ 1 ], &boxes[ i ][ 1 ] + n ) ;
	}
}

void printData()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	for( i = 1 ; i <= k ; i++ )
	{
		cout << boxNumbered[ i ] << "\t\t" ;
		for( j = 1 ; j <= n ; j++ )
		{
			cout << boxes[ i ][ j ] << "\t" ;
		}

		cout << endl ;
	}
}

int order( int *boxA, int *boxB )
{
	int		i = 0 ; // loop counter

	for( i = 1 ; i <= n ; i++ )
	{
		if( boxA[ i ] < boxB[ i ] )
		{
			return -1 ;
		}
		else if( boxA[ i ] > boxB[ i ] )
		{
			return 1 ;
		}
	}

	return 0 ;
}

int nestIn( int *boxA, int *boxB )
{
	int		i = 0 ; // loop counter

	if( boxA[ 1 ] == boxB[ 1 ] )
	{
		return 0 ;
	}
	else if( boxA[ 1 ] > boxB[ 1 ] )
	// Under this condition, we test if boxB nest in boxA.
	{
		for( i = 2 ; i <= n ; i++ )
		{
			if( boxA[ i ] <= boxB[ i ] )
			{
				return 0 ;
			}
		}

		return -1 ;
	}
	else
	// Under this condition, we test if boxA nest in boxB.
	{
		for( i = 2 ; i <= n ; i++ )
		{
			if( boxA[ i ] >= boxB[ i ] )
			{
				return 0 ;
			}
		}

		return 1 ;
	}
}

//
// We use insertion sort to sort the data.
// We sort data so that all nesting string is increasing in the array.
//
void sortData()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 1 ; i <= k ; i++ )
	{
		for( j = i ; j >= 2 ; j-- )
		{
			switch( order( boxes[ j ], boxes[ j - 1 ] ) )
			{
				case -1: 	// If the order of boxes[ j ] is smaller than 
							//order of boxes[ j - 1 ].
					swap( boxes[ j ], boxes[ j - 1 ] ) ;
					swap( boxNumbered[ j ], boxNumbered[ j - 1 ] ) ;
					break ;
				default : 	// Other cases.
					j = 1 ; 	//Because the box don't need to move backward,
								//we don't have to chech more about j.
								//so we set j to 1 to end the loop.
					break ;
			}
		}
	}
}

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
void lis()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	lenLongestNesting = 0 ;

	for( i = 1 ; i <= k ; i++ )
	{
		best[ i ] = 1 ;

		for( j = 1 ; j < i ; j++ )
		{
			if( nestIn( boxes[ j ], boxes[ i ] ) > 0 )
			// If boxes[ j ] nest in boxes[ i ]
			{
				if( best[ j ] + 1 > best[ i ] )
				{
					best[ i ] = best[ j ] + 1 ;
					previous[ i ] = j ;
				}
			}
		}

		if( best[ i ] > lenLongestNesting )
		{
			lenLongestNesting = best[ i ] ;
			largestBoxInLis = i ;
		}
	}
}

//
// List the longest nesting string into the array named longestNesting.
// Use the information in the array named previous which record previous 
// nesting box of every box.
// Now, the largest box in the longest nesting string is stored in 
// LongestNesting[ lenLongestNesting ], we need to fill in the elements of 
// the array from LongestNesting[ 1 ] to LongestNesting[ lenLongestNesting - 1 ].
//
void listLis()
{
	int		i = 0 ; // loop counter

	// list the longest nesting string in the array.
	// Data stored in the array are the order of boxes.(Not the number.)
	longestNesting[ lenLongestNesting ] = largestBoxInLis ;
	for( i = lenLongestNesting - 1 ; i >= 1 ; i-- )
	{
		longestNesting[ i ] = previous[ longestNesting[ i + 1 ] ] ;
	}

	// Convert them into box numbers.
	for( i = lenLongestNesting ; i >= 1 ; i-- )
	{
		longestNesting[ i ] = boxNumbered[ longestNesting[ i ] ] ;
	}
}

int 
main()
{
	int		i = 0 ; // loop counter

	allocate() ;

	while( cin >> k >> n )
	{
		readData() ;
		sortDimension() ;

		//Now we have to implement Longest Increasing Subsequence algorithm.
		sortData() ;
		lis() ;

		// Take out the list from the array best.
		listLis() ;

		cout << lenLongestNesting << endl ;
		for( i = 1 ; i < lenLongestNesting ; i++ )
		{
			cout << longestNesting[ i ] << " " ;
		}
		cout << longestNesting[ lenLongestNesting ] << endl ;
	}

	return 0 ;
}

