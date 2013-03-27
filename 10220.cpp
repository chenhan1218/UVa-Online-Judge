#include <iostream>
#include <iomanip>
using namespace std ;

int sum_of_the_digits( long long  input )
{
	int sum = 0 ;
	while( input != 0 )
	{
		sum += input % 10 ;
		input /= 10 ;
	}
	
	return sum ;
}

int main()
{
	long long digit14 = 10000000 ;
	digit14 *= digit14 ;

	int number_longint[ 1001 ] = { 0 } ;
	number_longint[ 1 ] = 1 ;

	//Here we use large number. 
	//For int n, the Factorial of n is from  Factorial[ n ][ 1 ] to Factorial[ n ] [ number_longint[ n ]  ] 
	long long *Factorial[ 1001 ] ;
	Factorial[ 1 ] = new long long [ number_longint[ 1 ] + 1 ] ;
	Factorial[ 1 ][ 1 ] = 1 ;
	
	int required_number[ 1001 ] = { 0 } ;
	required_number[ 0 ] = 1 ;
	required_number[ 1 ] = 1 ;

	for( int i = 2 ; i <= 1000 ; i++ )
	{
		//Calculate the long long int numbers we need. 
		if( Factorial[ i - 1 ][ number_longint[ i - 1 ] ] >= digit14 / 1000 )
		{
			number_longint[ i ] = number_longint[ i - 1 ] + 1 ;
		}
		else
		{
			number_longint[ i ] = number_longint[ i - 1 ] ;
		}
		
		//Allocate the space of Counting[ i ]  
		Factorial[ i ] = new long long [ number_longint[ i ] + 1 ] ;
		Factorial[ i ][ 0 ] = 0 ;
		for( int j = 1 ; j <= number_longint[ i - 1 ] ; j++ )
		{
			//Check if there is carry. 
			if( Factorial[ i ][ j - 1 ] >= digit14 )
			{
				Factorial[ i ][ j ] = Factorial[ i ][ j - 1 ] / digit14 ;
				Factorial[ i ][ j - 1 ] = Factorial[ i ][ j - 1 ] % digit14 ;
			}
			else
			{
				Factorial[ i ][ j ] = 0 ;
			}
			// Now we can sure the exact number of Factorial[ i ][ j - 1 ].
			// So we add the sum of the digit into required number.
			required_number[ i ] += sum_of_the_digits( Factorial[ i ][ j - 1 ] ) ;

			// Use the recursion formula to calculate Factorial numbers.
			Factorial[ i ][ j ] += Factorial[ i - 1 ][ j ] * i ;
		}
		if( number_longint[ i ] > number_longint[ i - 1 ] )
		{
			//Check if there is carry. 
			if( Factorial[ i ][ number_longint[ i ] - 1 ] >= digit14 )
			{
				Factorial[ i ][ number_longint[ i ] ] = Factorial[ i ][ number_longint[ i ] - 1 ] / digit14 ;
				Factorial[ i ][ number_longint[ i ] - 1 ] = Factorial[ i ][ number_longint[ i ] - 1 ] % digit14 ;
			}
			else
			{
				Factorial[ i ][ number_longint[ i ] ] = 0 ;
			}
			// Now we can sure the exact number of Factorial[ i ][ number_longint[ i ] - 1 ].
			// So we add the sum of the digit into required number.
			required_number[ i ] += sum_of_the_digits( Factorial[ i ][ number_longint[ i ] - 1 ] ) ;
		}
		// Finally, the last element of factorial have been calculated.
		// We add the sum of the digit to the required number.
		required_number[ i ] += sum_of_the_digits( Factorial[ i ][ number_longint[ i ] ] ) ;
	}
	// Now we have calucated all the Factorial numbers.
	
	int input ;

	while( cin >> input )
	{
		cout << required_number[ input ] << endl ;
	}

	return 0 ;
}
