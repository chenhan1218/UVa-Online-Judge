#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxHandle 6000
#define Types 11

int
main()
{
	int		dollar = 0 ;
	int		cent = 0 ;
	char	buffer ;
	int		amount = 0 ;
	int		maxAmount = 0 ;
	long long int		ways[ MaxHandle + 1 ][ Types + 1 ] = { 0 } ;
	// Numbers in ways[ i ][ j ] means how many different ways of making changes
	// with j types of coins for i cents.
	int		coins[ Types + 1 ] = { 0 } ;
	coins[ 1 ] = 1 ;
	coins[ 2 ] = 2 ;
	coins[ 3 ] = 4 ;
	coins[ 4 ] = 10 ;
	coins[ 5 ] = 20 ;
	coins[ 6 ] = 40 ;
	coins[ 7 ] = 100 ;
	coins[ 8 ] = 200 ;
	coins[ 9 ] = 400 ;
	coins[ 10 ] = 1000 ;
	coins[ 11 ] = 2000 ;

	//There is one way of making change for zero cent.
	ways[ 0 ][ 1 ] = 1 ;
	ways[ 0 ][ 2 ] = 1 ;
	ways[ 0 ][ 3 ] = 1 ;
	ways[ 0 ][ 4 ] = 1 ;
	ways[ 0 ][ 5 ] = 1 ;
	ways[ 0 ][ 6 ] = 1 ;
	ways[ 0 ][ 7 ] = 1 ;
	ways[ 0 ][ 8 ] = 1 ;
	ways[ 0 ][ 9 ] = 1 ;
	ways[ 0 ][ 10 ] = 1 ;
	ways[ 0 ][ 11 ] = 1 ;

	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> dollar >> buffer >> cent )
	{
		amount = ( dollar * 100 + cent ) / 5 ;

		if( amount == 0 )
		{
			break ;
		}

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

		// different ways of making changes
		// with Types types of coins for a given amount of money.
		cout 	<< setw( 3 ) << setfill(' ') << dollar << "." 
				<< setw( 2 ) << setfill('0') << cent 
				<< setw( 17 ) << setfill(' ') << ways[ amount ][ Types ] << endl ;
	}

	return 0 ;
}
