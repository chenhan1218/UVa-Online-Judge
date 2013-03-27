#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	long long	digit15 = 10000000 ;
		digit15 *= digit15 ;
		digit15 *= 10 ;
	int			number_longint[ 1001 ] = { 0 } ;
	long long	*factorial_number[ 1001 ] ;
	//Here we use large number. 
	//For int n, the factorial number of n is from  factorial_number[ n ][ 1 ] 
	//to factorial_number[ n ][ number_longint[ n ] ] 
	int			n = 0 ;
	int			i = 0 ; // loop counter
	int			j = 0 ; // loop counter

	number_longint[ 0 ] = 1 ;
	factorial_number[ 0 ] = new long long [ number_longint[ 0 ] + 1 ] ;
	factorial_number[ 0 ][ 1 ] = 1 ; // 0! = 1
	number_longint[ 1 ] = 1 ;
	factorial_number[ 1 ] = new long long [ number_longint[ 1 ] + 1 ] ;
	factorial_number[ 1 ][ 1 ] = 1 ;

	for( i = 2 ; i <= 1000 ; i++ )
	{
		//Calculate the long long int numbers we need. 
		if( factorial_number[ i - 1 ][ number_longint[ i - 1 ] ] >= digit15 / 1000 )
		{
			number_longint[ i ] = number_longint[ i - 1 ] + 1 ;
		}
		else
		{
			number_longint[ i ] = number_longint[ i - 1 ] ;
		}
		
		//Allocate the space of factorial_number[ i ]  
		factorial_number[ i ] = new long long [ number_longint[ i ] + 1 ] ;
		factorial_number[ i ][ 0 ] = 0 ;

		// Calculate factorial_number[ i ].
		for( j = 1 ; j <= number_longint[ i - 1 ] ; j++ )
		{
			//Check if there is carry.
			if( factorial_number[ i ][ j - 1 ] >= digit15 )
			{
				factorial_number[ i ][ j ] = factorial_number[ i ][ j - 1 ] / digit15 ;
				factorial_number[ i ][ j - 1 ] = factorial_number[ i ][ j - 1 ] % digit15 ;
			}
			else
			{
				factorial_number[ i ][ j ] = 0 ;
			}
			// Use the recursion formula to calculate factorial number.
			factorial_number[ i ][ j ] += factorial_number[ i - 1 ][ j ] * i ;
		}
		for( j = number_longint[ i - 1 ] + 1 ; j <= number_longint[ i ] ; j++ )
		{
			//Check if there is carry. 
			if( factorial_number[ i ][ j - 1 ] >= digit15 )
			{
				factorial_number[ i ][ j ] = factorial_number[ i ][ j - 1 ] / digit15 ;
				factorial_number[ i ][ j - 1 ] = factorial_number[ i ][ j - 1 ] % digit15 ;
			}
			else
			{
				factorial_number[ i ][ j ] = 0 ;
			}
		}
	}

	while( cin >> n )
	{
		i = number_longint[ n ] ;

		while( factorial_number[ n ][ i ] == 0 )
		{
			i-- ;
		}

		cout << n << "!" << endl ;
		cout << factorial_number[ n ][ i ] ;

		for( i = i - 1 ; i >= 1 ; i-- )
		{
			cout << setw( 15 ) << setfill('0') << factorial_number[ n ][ i ] ;
		}

		cout << endl ;
	}

	return 0 ;
}
