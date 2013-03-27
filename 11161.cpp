#include <iostream>
#include <iomanip>
using namespace std ;

#define Max_n 1500

int
main()
{
	// In this problem, the result for n n is (f(n+3)-3) / 2

	long long	digit16 = 100000000 ;
	digit16 *= digit16 ;

	int		number_longint[ Max_n + 1 ] = { 0 } ;

	//Here we use large number. 
	//For int n, the fabonacci number of n is from  answer[ n ][ 1 ] 
	//to answer[ n ][ number_longint[ n ] ] 
	long long*	answer[ Max_n + 1 ] ;
	int			n = 0 ;

	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	// First, we calculate fabonacci numbers.
	// Now anser[ i ] set to fabonacci[ i + 3 ] - 3.
	number_longint[ 1 ] = 1 ;
	answer[ 1 ] = new long long [ number_longint[ 1 ] + 1 ] ;
	answer[ 1 ][ 0 ] = 0 ;
	answer[ 1 ][ 1 ] = 0 ;
	number_longint[ 2 ] = 1 ;
	answer[ 2 ] = new long long [ number_longint[ 2 ] + 1 ] ;
	answer[ 2 ][ 0 ] = 0 ;
	answer[ 2 ][ 1 ] = 2 ;

	for( i = 3 ; i <= Max_n ; i++ )
	{
		//Calculate the long long int numbers we need. 
		if( answer[ i - 1 ][ number_longint[ i - 1 ] ] >= digit16 / 2 )
		{
			number_longint[ i ] = number_longint[ i - 1 ] + 1 ;
		}
		else
		{
			number_longint[ i ] = number_longint[ i - 1 ] ;
		}
		
		//Allocate the space and the value of answer[ i ]  
		answer[ i ] = new long long [ number_longint[ i ] + 1 ] ;
		answer[ i ][ 0 ] = 0 ;

		// Use the recursion formula to calculate fabonacci number.
		// fabonacci[ i ] = fabonacci[ i - 1 ] + fabonacci[ i - 2 ]
		// So, answer[ i ] = answer[ i - 1 ] + answer[ i - 2 ] + 3
		answer[ i ][ 1 ] = answer[ i - 1 ][ 1 ] + answer[ i - 2 ][ 1 ] + 3 ;
		for( j = 2 ; j <= number_longint[ i - 2 ] ; j++ )
		{
			//Check if there is carry.
			if( answer[ i ][ j - 1 ] >= digit16 )
			{
				answer[ i ][ j ] = answer[ i ][ j - 1 ] / digit16 ;
				answer[ i ][ j - 1 ] = answer[ i ][ j - 1 ] % digit16 ;
			}
			else
			{
				answer[ i ][ j ] = 0 ;
			}

			answer[ i ][ j ] += answer[ i - 1 ][ j ] + answer[ i - 2 ][ j ] ;
		}
		for( j = number_longint[ i - 2 ] + 1 ; j <= number_longint[ i - 1 ] ; j++ )
		{
			//Check if there is carry.
			if( answer[ i ][ j - 1 ] >= digit16 )
			{
				answer[ i ][ j ] = answer[ i ][ j - 1 ] / digit16 ;
				answer[ i ][ j - 1 ] = answer[ i ][ j - 1 ] % digit16 ;
			}
			else
			{
				answer[ i ][ j ] = 0 ;
			}

			answer[ i ][ j ] += answer[ i - 1 ][ j ] ;
		}
		for( j = number_longint[ i - 1 ] + 1 ; j <= number_longint[ i ] ; j++ )
		{
			//Check if there is carry. 
			if( answer[ i ][ j - 1 ] >= digit16 )
			{
				answer[ i ][ j ] = answer[ i ][ j - 1 ] / digit16 ;
				answer[ i ][ j - 1 ] = answer[ i ][ j - 1 ] % digit16 ;
			}
			else
			{
				answer[ i ][ j ] = 0 ;
			}
		}
	}

	// Second, divide the number by 2.
	for( i = 1 ; i <= Max_n ; i++ )
	{
		for( j = number_longint[ i ] ; j > 1 ; j-- )
		{
			answer[ i ][ j - 1 ] += ( answer[ i ][ j ] & 0x01 ) * digit16 ;
			answer[ i ][ j ] = answer[ i ][ j ] >> 1 ;
		}
		answer[ i ][ 1 ] = answer[ i ][ 1 ] >> 1 ;
	}

	for( i = 1 ; cin >> n ; i++ )
	{
		if( n == 0 )
		{
			break ;
		}

		cout << "Set " << i << ":" << endl ;

		j = number_longint[ n ] ;
		while( answer[ n ][ j ] == 0 && j > 1 )
		{
			j-- ;
		}

		cout << answer[ n ][ j ] ;

		for( j = j - 1 ; j >= 1 ; j-- )
		{
			cout << setw( 16 ) << setfill('0') << answer[ n ][ j ] ;
		}

		cout << endl ;
	}

	return 0 ;
}
