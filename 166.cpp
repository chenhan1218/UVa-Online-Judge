#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxCents 100000
#define unit 5 // per unit is 5 cents.
#define Types 6

void print( int maxPay, int numCoins[][ Types + 1 ], int minNumCoins[ Types + 1 ] )
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 0 ; i <= maxPay ; i += unit )
	{
		cout << i << "\t"  ;
		for( j = 1 ; j <= Types ; j++ )
		{
			cout << numCoins[ i ][ j ] << "\t" ;
		}
		cout << minNumCoins[ i ] << endl ;
	}
}

int
main()
{
	int		coins[ Types + 1 ] = { 0 } ;
	coins[ 1 ] = 5 ;
	coins[ 2 ] = 10 ;
	coins[ 3 ] = 20 ;
	coins[ 4 ] = 50 ;
	coins[ 5 ] = 100 ;
	coins[ 6 ] = 200 ;

	// numCoins[ i ][ j ] means number of every Coins for i unit
	int		numCoins[ MaxCents + 1 ][ Types + 1 ] = { 0 } ;
	int		minNumCoins[ MaxCents + 1 ] = { 0 } ;

	int		minNumCoinsReturn[ MaxCents + 1 ] = { 0 } ;

	int		coinsAvail[ Types + 1 ] = { 0 } ;
	double	money = 0 ;
	int		cents = 0 ;
	int		maxPay = 0 ;
	int		currentNumCoins = 0 ;
	int		addCoinType = 0 ;
	int		changeHands = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	for( i = unit ; i <= MaxCents ; i += unit )
	{
		minNumCoinsReturn[ i ] = i / coins[ 1 ] ;
		for( j = 2 ; j <= Types ; j++ )
		{
			if( i >= coins[ j ] )
			{
				minNumCoinsReturn[ i ] = min( minNumCoinsReturn[ i ], 
						minNumCoinsReturn[ i - coins[ j ] ] + 1 ) ;
			}
		}
	}

	while( 1 )
	{
		for( i = 1 ; i <= Types ; i++ )
		{
			cin >> coinsAvail[ i ] ;
		}

		for( i = 1 ; i <= Types ; i++ )
		{
			if( coinsAvail[ i ] != 0 )
			{
				break ;
			}
		}

		//The file will be terminated by six zeroes (0 0 0 0 0 0).
		if( i > Types )
		{
			break ;
		}

		// read in the money we should pay.
		cin >> money ;
		cents = (int)( money * 100 + 0.5 ) ;

		maxPay = 0 ;
		for( j = 1 ; j <= Types ; j++ )
		{
			maxPay += coinsAvail[ j ] * coins[ j ] ;
		}

		if( MaxCents < maxPay )
		{
			maxPay = MaxCents ;
		}

		for( i = unit ; i <= maxPay ; i += unit )
		{
			currentNumCoins = 1000 ; 	// There is no possible that number of coins
										// exceed 1000.
										// Note: make it large enough.
			addCoinType = 0 ;

			for( j = 1 ; j <= Types ; j++ )
			{
				// if colletion of money i - coins[ j ] is possible.
				if( i >= coins[ j ] && minNumCoins[ i - coins[ j ] ] != -1 )
				{
					if( numCoins[ i - coins[ j ] ][ j ] < coinsAvail[ j ] && 
						minNumCoins[ i - coins[ j ] ] + 1 <= currentNumCoins )
					{
						addCoinType = j ;
						currentNumCoins = minNumCoins[ i - coins[ j ] ] + 1 ;
					}
				}
			}

			if( addCoinType > 0 )
			{
				for( k = 1 ; k <= Types ; k++ )
				{
					numCoins[ i ][ k ] = numCoins[ i - coins[ addCoinType ] ][ k ] ;
				}
				numCoins[ i ][ addCoinType ] += 1 ;
				minNumCoins[ i ] = currentNumCoins ;
			}
			else
			{
				for( k = 1 ; k <= Types ; k++ )
				{
					numCoins[ i ][ k ] = -1 ;
				}
				minNumCoins[ i ] = -1 ;
			}
		}

		// Now we have calculate every possible pay for coins available.
		// Start to search the minimum number of coins that change hands.
		// i is the money we pay, so i - cents is the money return.

		// changeHands will not exceed 100, so we set changeHands at 100.
		changeHands = 100 ;
		for( i = cents ; i <= maxPay ; i += unit )
		{
//cout << i << "\t" << minNumCoins[ i ] << "\t" << minNumCoins[ i - cents ] 
//<< "\t" << changeHands << endl ;
			if( minNumCoins[ i ] + minNumCoinsReturn[ i - cents ] < changeHands && 
				minNumCoins[ i ] >= 0 )
			{
				changeHands = min( changeHands, 
							minNumCoins[ i ] + minNumCoinsReturn[ i - cents ] ) ;
			}
		}

		cout << setw( 3 ) << changeHands << endl ;
//print( maxPay, numCoins, minNumCoins ) ;
	}

	return 0 ;
}
