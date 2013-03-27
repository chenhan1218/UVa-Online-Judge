#include <iostream>
#include <iomanip>
using namespace std ;

#define N 8

bool checkOk( int *position, int column, int row )
{
	int		i = 0 ;

	if( column > 0 )
	{
		for( i = 0 ; i < column ; i++ )
			if( abs( position[ i ] - row ) == column - i || position[ i ] == row )
				return false ;

		return true ;
	}
	else
	{
		return true ;
	}
}

void queen( int *position, int n, int &solutionNum )
{
	int		i = 0 ;
	int		j = 0 ;

	if( n == N )
	{
		solutionNum++ ;

		cout << setw(2) << solutionNum << "     " ;
		for( i = 0 ; i < N ; i++ )
			cout << " " << position[ i ] + 1 ;
		cout << endl ;
	}
	else
	{
		if( position[ n ] == -1 )
		{
			for( i = 0 ; i < N ; i++ )
			{
				if( checkOk( position, n, i ) == true )
				{
					position[ n ] = i ;
					queen( position, n + 1, solutionNum ) ;
					position[ n ] = -1 ;
				}
			}
		}
		else
		{
			if( checkOk( position, n, position[ n ] ) == true )
			{
				queen( position, n + 1, solutionNum ) ;
			}
		}
	}
}

int main()
{
	int		t = 0 ;
	int		position[ N ] = { 0 } ;
	int		row = 0 ;
	int		column = 0 ;
	int		solutionNum = 0 ;
	bool	firstCase = true ;
	int		i = 0 ;
	int		j = 0 ;

	cin >> t ;
	while( t > 0 )
	{
		t-- ;

		cin >> row >> column ;

		solutionNum = 0 ;
		fill( position, position + N, -1 ) ;
		position[ column - 1 ] = row - 1 ;

		if( firstCase == true )
			firstCase = false ;
		else
			cout << endl ;
		cout << "SOLN       COLUMN" << endl ;
		cout << " #      1 2 3 4 5 6 7 8" << endl ;
		cout << endl ;
		queen( position, 0, solutionNum ) ;
	}

	return 0 ;
}


