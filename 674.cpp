#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxHandle 7489
#define Types 5

int
main()
{
	int		amount = 0 ;
	int		ways[ MaxHandle + 1 ][ Types + 1 ] = { 0 } ;
	// Numbers in ways[ i ][ j ] means how many different ways of making changes
	// with j types of coins for i cents.
	int		coins[ Types + 1 ] = { 0 } ;
	coins[ 1 ] = 1 ;
	coins[ 2 ] = 5 ;
	coins[ 3 ] = 10 ;
	coins[ 4 ] = 25 ;
	coins[ 5 ] = 50 ;

	ways[ 0 ][ 1 ] = 1 ;
	ways[ 0 ][ 2 ] = 1 ;
	ways[ 0 ][ 3 ] = 1 ;
	ways[ 0 ][ 4 ] = 1 ;
	ways[ 0 ][ 5 ] = 1 ;
	//There is one way of making change for zero cent.

	int		maxAmount = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> amount )
	{
		if( amount > maxAmount )
		{
			//Start do calculate different ways of making changes.
			//And store the result in array ways.

			for( i = maxAmount + 1 ; i <= amount ; i++ )
			{
				if( i >= coins[ 1 ] )
				{
					ways[ i ][ 1 ] = ways[ i - coins[ 1 ] ][ 1 ] ;
				}
				else
				{
					ways[ i ][ 1 ] = 0 ;
				}

				for( j = 2 ; j <= Types ; j++ )
				{
					if( i >= coins[ j ] )
					{
						ways[ i ][ j ] = ways[ i - coins[ j ] ][ j ] + ways[ i ][ j - 1 ] ;
					}
					else
					{
						ways[ i ][ j ] = ways[ i ][ j - 1 ] ;
					}
				}
			}

			maxAmount = amount ;
		}

		cout << ways[ amount ][ Types ] << endl ;
		//different ways of making changes
		// with Types types of coins for a given amount of money.
	}

	return 0 ;
}
