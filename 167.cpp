#include <iostream>
#include <iomanip>
using namespace std ;

#define N 8

int		num[ N ][ N ] = { 0 } ;
int		sum = 0 ;

bool checkOk( int *position, int row, int column )
{
	int		i = 0 ;

	if( row > 0 )
	{
		for( i = 0 ; i < row ; i++ )
			if( abs( position[ i ] - column ) == row - i || position[ i ] == column )
				return false ;

		return true ;
	}
	else
	{
		return true ;
	}
}

void queen( int *position, int n, int &maxSum )
{
	int		i = 0 ;
	int		j = 0 ;

	if( n == N )
	{
		int		sum = 0 ;
		for( i = 0 ; i < N ; i++ )
			sum += num[ i ][ position[ i ] ] ;
		maxSum = max( maxSum, sum ) ;
	}
	else
	{
		for( i = 0 ; i < N ; i++ )
		{
			if( checkOk( position, n, i ) == true )
			{
				position[ n ] = i ;
				queen( position, n + 1, maxSum ) ;
			}
		}
	}
}

int main()
{
	int		t = 0 ;
	int		maxSum = 0 ;
	int		position[ N ] = { 0 } ;
	int		i = 0 ;
	int		j = 0 ;


	cin >> t ;
	while( t > 0 )
	{
		t-- ;

		for( i = 0 ; i < N ; i++ )
			for( j = 0 ; j < N ; j++ )
				cin >> num[ i ][ j ] ;

		maxSum = 0 ;
		queen( position, 0, maxSum ) ;

		cout << setw( 5 ) << right << maxSum << endl ;
	}

	return 0 ;
}

