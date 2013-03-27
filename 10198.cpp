#include <iostream>
#include <iomanip>
using namespace std ;

/*
#include <fstream>
using std::ofstream ;
ofstream outfile( "10198.swem" ) ;
*/

int main()
{
	long long digit18 = 1000000000 ;
	digit18 *= digit18 ;

	int number_longint[ 1001 ] = { 0 } ;
	number_longint[ 1 ] = 1 ;
	number_longint[ 2 ] = 1 ;
	number_longint[ 3 ] = 1 ;

	//Here we use large number. 
	//For int n, the Counting number of n is from  Counting[ n ][ 1 ] to Counting[ n ] [ number_longint[ n ] ] 
	long long *Counting[ 1001 ] ;
	Counting[ 1 ] = new long long [ number_longint[ 1 ] + 1 ] ;
	Counting[ 1 ][ 1 ] = 2 ;
	Counting[ 2 ] = new long long [ number_longint[ 2 ] + 1 ] ;
	Counting[ 2 ][ 1 ] = 5 ;
	Counting[ 3 ] = new long long [ number_longint[ 3 ] + 1 ] ;
	Counting[ 3 ][ 1 ] = 13 ;

	for( int i = 4 ; i <= 1000 ; i++ )
	{
		//Calculate the long long int numbers we need. 
		if( Counting[ i - 1 ][ number_longint[ i - 1 ] ] >= digit18 / 4 )
		{
			number_longint[ i ] = number_longint[ i - 1 ] + 1 ;
		}
		else
		{
			number_longint[ i ] = number_longint[ i - 1 ] ;
		}
		
		//Allocate the space of Counting[ i ]  
		Counting[ i ] = new long long [ number_longint[ i ] + 1 ] ;
		Counting[ i ][ 0 ] = 0 ;
		for( int j = 1 ; j <= number_longint[ i - 3 ] ; j++ )
		{
			//Check if there is carry. 
			if( Counting[ i ][ j - 1 ] >= digit18 )
			{
				Counting[ i ][ j ] = Counting[ i ][ j - 1 ] / digit18 ;
				Counting[ i ][ j - 1 ] = Counting[ i ][ j - 1 ] % digit18 ;
			}
			else
			{
				Counting[ i ][ j ] = 0 ;
			}
			// Use the recursion formula to calculate Counting numbers.
			Counting[ i ][ j ] += 2 * Counting[ i - 1 ][ j ] + Counting[ i - 2 ][ j ] + Counting[ i - 3 ][ j ] ;
		}
		for( int j = number_longint[ i - 3 ] + 1 ; j <= number_longint[ i - 2 ] ; j++ )
		{
			//Check if there is carry. 
			if( Counting[ i ][ j - 1 ] >= digit18 )
			{
				Counting[ i ][ j ] = Counting[ i ][ j - 1 ] / digit18 ;
				Counting[ i ][ j - 1 ] = Counting[ i ][ j - 1 ] % digit18 ;
			}
			else
			{
				Counting[ i ][ j ] = 0 ;
			}
			// Use the recursion formula to calculate Counting numbers.
			Counting[ i ][ j ] += 2 * Counting[ i - 1 ][ j ] + Counting[ i - 2 ][ j ] ;
		}
		for( int j = number_longint[ i - 2 ] + 1 ; j <= number_longint[ i - 1 ] ; j++ )
		{
			//Check if there is carry. 
			if( Counting[ i ][ j - 1 ] >= digit18 )
			{
				Counting[ i ][ j ] = Counting[ i ][ j - 1 ] / digit18 ;
				Counting[ i ][ j - 1 ] = Counting[ i ][ j - 1 ] % digit18 ;
			}
			else
			{
				Counting[ i ][ j ] = 0 ;
			}
			// Use the recursion formula to calculate Counting numbers.
			Counting[ i ][ j ] += 2 * Counting[ i - 1 ][ j ] ;
		}
		for( int j = number_longint[ i - 1 ] + 1 ; j <= number_longint[ i ] ; j++ )
		{
			//Check if there is carry. 
			if( Counting[ i ][ j - 1 ] >= digit18 )
			{
				Counting[ i ][ j ] = Counting[ i ][ j - 1 ] / digit18 ;
				Counting[ i ][ j - 1 ] = Counting[ i ][ j - 1 ] % digit18 ;
			}
			else
			{
				Counting[ i ][ j ] = 0 ;
			}
		}
	}

	int input ;

	while( cin >> input )
	{
		int i = number_longint[ input ] ;

		while( Counting[ input ][ i ] == 0 )
		{
			i-- ;
		}

		cout << Counting[ input ][ i ] ;

		for( i = i - 1 ; i >= 1 ; i-- )
		{
			cout << setw( 18 ) << setfill('0') << Counting[ input ][ i ] ;
		}

		cout << endl ;
	}

	return 0 ;
}
