#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	//produce a array
	//a[ i ] is the sum of i-1 numbers from 2 to i.

	int		a[ 46 ] = { 0 } ;
	int		M = 0 ; // datasets
	int		N = 0 ;
	int		i = 0 ; // loop counter 
	int		j = 0 ; // loop counter
	int		group = 0 ;
	int		removedNumber = 0 ;
	int		firstNumber = 0 ;

	a[ 2 ] = 2 ;
	for( i = 3 ; i < 46 ; i++ )
	{
		a[ i ] = a[ i - 1 ] + i ;
	}

	cin >> M ;
	for( i = 1 ; i <= M ; i++ ) // for each dataset.
	{
		if( i > 1 )
		{
			cout << endl ;
		}

		cin >> N ;

		for( group = 3 ; ; group++ )
		{
			if( N <= a[ group ] )
			{
				break ;
			}
		}

		// Now we have check out the group of N.
		// We will use the number group to do something.

		if( N == a[ group ] - 1 )
		{
			removedNumber = group ;
			firstNumber = 0 ;

			for( j = 3 ; j <= group + 1 ; j++ )
			{
				if( j != removedNumber )
				{
					if( firstNumber == 0 )
					{
						cout << j ;
						firstNumber = 1 ;
					}
					else
					{
						cout << " " << j ;
					}
				}
			}

			cout << endl ;
		}
		else
		{
			removedNumber = a[ group ] - N ;
			firstNumber = 0 ;

			for( j = 2 ; j <= group ; j++ )
			{
				if( j != removedNumber )
				{
					if( firstNumber == 0 )
					{
						cout << j ;
						firstNumber = 1 ;
					}
					else
					{
						cout << " " << j ;
					}
				}
			}

			cout << endl ;
		}
	}

	return 0 ;
}

