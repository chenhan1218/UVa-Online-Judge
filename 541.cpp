#include <iostream>
#include <iomanip>
using namespace std ;

#define TRUE 1
#define FALSE 0
#define Max_n 100

bool	property ;
bool	matrix[ Max_n + 1 ][ Max_n + 1 ] ;
bool	column[ Max_n + 1 ] ;
bool	row[ Max_n + 1 ] ;
int		changeRow ;
int		changeColumn ;

void readInMatrix( int n )
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 1 ; i <= n ; i++ )
	{
		for( j = 1 ; j <= n ; j++ )
		{
			cin >> matrix[ i ][ j ] ;
		}
	}
}

//
// This function is no use in this problem, but it can help debug.
//
void printMatrix( int n )
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 1 ; i <= n ; i++ )
	{
		for( j = 1 ; j <= n ; j++ )
		{
			cout << matrix[ i ][ j ] << "\t" ;
		}

		cout << endl ;
	}
}

void checkParity( int n )
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	property = TRUE ;
	changeColumn = 0 ;
	changeRow = 0 ;

	// calculate number of 1's of every column
	for( i = 1 ; i <= n ; i++ )
	{
		column[ i ] = 0 ;
		for( j = 1 ; j <= n ; j++ )
		{
			column[ i ] ^= matrix[ j ][ i ] ;
		}

		if( column[ i ] == 1 )
		{
			if( changeColumn == 0 )
			{
				changeColumn = i ;
			}
			else
			{
				property = FALSE ;
				return ;
			}
		}
	}

	// calculate number of 1's of every row
	for( i = 1 ; i <= n ; i++ )
	{
		row[ i ] = 0 ;
		for( j = 1 ; j <= n ; j++ )
		{
			row[ i ] ^= matrix[ i ][ j ] ;
		}

		if( row[ i ] == 1 )
		{
			if( changeRow == 0 )
			{
				changeRow = i ;
			}
			else
			{
				property = FALSE ;
				return ;
			}
		}
	}
}

int
main()
{
	int		n = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> n )
	{
		if( n == 0 ) // Input will be terminated by a value of 0 for n.
		{
			break ;
		}

		readInMatrix( n ) ;
		checkParity( n ) ;

		if( property == TRUE )
		{
			if( changeRow != 0 )
			{
				cout << "Change bit (" << changeRow << "," << changeColumn << ")" << endl ;
			}
			else
			{
				cout << "OK" << endl ;
			}
		}
		else
		{
			cout << "Corrupt" << endl ;
		}
	}

	return 0 ;
}
