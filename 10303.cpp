// In fact, the number we calculate here is Catalan Number.
// You can find some information about it.
// C(n) = ( 4n-2 ) / ( n + 1 ) * C( n - 1 )

#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	long long digit15 = 10000000 ;
	digit15 *= digit15 ;
	digit15 *= 10 ;

	int number_longint[ 1001 ] = { 0 } ;
	number_longint[ 1 ] = 1 ;

	//Here we use large number. 
	//For int n, the Catalan number of n is from  Catalan_number[ n ][ 1 ] 
	//to Catalan_number[ n ][ number_longint[ n ] ] 
	long long *Catalan_number[ 1001 ] ;
	Catalan_number[ 1 ] = new long long [ number_longint[ 1 ] + 1 ] ;
	Catalan_number[ 1 ][ 1 ] = 1 ;

	for( int i = 2 ; i <= 1000 ; i++ )
	{
		//Calculate the long long int numbers we need. 
		if( Catalan_number[ i - 1 ][ number_longint[ i - 1 ] ] >= digit15 / 4000 )
		{
			number_longint[ i ] = number_longint[ i - 1 ] + 1 ;
		}
		else
		{
			number_longint[ i ] = number_longint[ i - 1 ] ;
		}
		
		//Allocate the space of Catalan_number[ i ]  
		Catalan_number[ i ] = new long long [ number_longint[ i ] + 1 ] ;
		Catalan_number[ i ][ 0 ] = 0 ;

		// First, we calculate (4i-2) * C(i-1)
		for( int j = 1 ; j <= number_longint[ i - 1 ] ; j++ )
		{
			//Check if there is carry.
			if( Catalan_number[ i ][ j - 1 ] >= digit15 )
			{
				Catalan_number[ i ][ j ] = Catalan_number[ i ][ j - 1 ] / digit15 ;
				Catalan_number[ i ][ j - 1 ] = Catalan_number[ i ][ j - 1 ] % digit15 ;
			}
			else
			{
				Catalan_number[ i ][ j ] = 0 ;
			}
			// Use the recursion formula to calculate Catalan number.
			Catalan_number[ i ][ j ] += Catalan_number[ i - 1 ][ j ] * ( 4 * i - 2 ) ;
		}
		for( int j = number_longint[ i - 1 ] + 1 ; j <= number_longint[ i ] ; j++ )
		{
			//Check if there is carry. 
			if( Catalan_number[ i ][ j - 1 ] >= digit15 )
			{
				Catalan_number[ i ][ j ] = Catalan_number[ i ][ j - 1 ] / digit15 ;
				Catalan_number[ i ][ j - 1 ] = Catalan_number[ i ][ j - 1 ] % digit15 ;
			}
			else
			{
				Catalan_number[ i ][ j ] = 0 ;
			}
		}

		// Second, we divide "(4i-2) * C(i-1)" by (i+1)
		for( int j = number_longint[ i ] ; j > 1 ; j-- )
		{
			Catalan_number[ i ][ j - 1 ] += ( Catalan_number[ i ][ j ] % ( i + 1 ) )
											* digit15 ;
			Catalan_number[ i ][ j ] = Catalan_number[ i ][ j ] / ( i + 1 ) ;
		}
		Catalan_number[ i ][ 1 ] = Catalan_number[ i ][ 1 ] / ( i + 1 ) ;
	}

	int input ;

	while( cin >> input )
	{
		int i = number_longint[ input ] ;

		while( Catalan_number[ input ][ i ] == 0 )
		{
			i-- ;
		}

		cout << Catalan_number[ input ][ i ] ;

		for( i = i - 1 ; i >= 1 ; i-- )
		{
			cout << setw( 15 ) << setfill('0') << Catalan_number[ input ][ i ] ;
		}

		cout << endl ;
	}

	return 0 ;
}
