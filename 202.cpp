#include <iostream>
#include <iomanip>
using namespace std ;

int		digits[ 6001 ] ;
int		residue[ 3001 ] ;
int		occurrence[ 3001 ] ;

int main()
{
	int		cases = 0 ;
	int		numerator = 0 ;
	int		denominator = 0 ;
	int		cycle = 0 ;
	int		firstOccurrence = 0 ;
	int		i = 0 ; // loop counter
	while( cin >> numerator >> denominator )
	{
		cases++ ;

		for( i = 0 ; i < denominator ; i++ )
		{
			occurrence[ i ] = 0 ;
		}

		digits[ 0 ] = numerator / denominator ;
		residue[ 0 ] = numerator % denominator ;

		for( i = 1 ; ; i++ )
		{
			digits[ i ] = ( residue[ i - 1 ] * 10 ) / denominator ;
			residue[ i ] = ( residue[ i - 1 ] * 10 ) % denominator ;
			if( occurrence[ residue[ i ] ] > 0 && digits[ i ] == digits[ occurrence[ residue[ i ] ] ] )
			{
				firstOccurrence = occurrence[ residue[ i ] ] ;
				cycle = i - firstOccurrence ;
				break ;
			}
			else
			{
				occurrence[ residue[ i ] ] = i ;
			}
		}

		cout 	<< numerator << "/" << denominator << " = " 
					<< digits[ 0 ] << "." ;
		for( i = 1 ; i < firstOccurrence ; i++ )
		{
			cout << digits[ i ] ;
		}

		if( cycle <= 50 )
		{
			cout << "(" ;
			for( i = firstOccurrence ; i < firstOccurrence + cycle ; i++ )
			{
				cout << digits[ i ] ;
			}
			cout << ")" << endl ;
		}
		else
		{
			cout << "(" ;
			for( i = firstOccurrence ; i < firstOccurrence + 50 ; i++ )
			{
				cout << digits[ i ] ;
			}
			cout << "...)" << endl ;
		}
		cout << "   " << cycle << " = number of digits in repeating cycle" << endl << endl ;
	}

	return 0 ;
}
