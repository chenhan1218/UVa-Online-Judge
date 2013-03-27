#include <iostream>
#include <iomanip>
#include <vector>
using namespace std ;

long long int	n = 0 ;
long long int	counter = 0 ;
vector<int>		disk[ 3 ] ;

void printState()
{
	int		i = 0 ; // loop counter
		cout << endl ;
		cout << "A=>" ;
		for( i = 0 ; i < disk[ 0 ].size() ; i++ )
		{
			if( i == 0 )
				cout << "   " << disk[ 0 ][ i ] ;
			else
				cout << " " << disk[ 0 ][ i ] ;
		}
		cout << endl ;
		cout << "B=>" ;
		for( i = 0 ; i < disk[ 1 ].size() ; i++ )
		{
			if( i == 0 )
				cout << "   " << disk[ 1 ][ i ] ;
			else
				cout << " " << disk[ 1 ][ i ] ;
		}
		cout << endl ;
		cout << "C=>" ;
		for( i = 0 ; i < disk[ 2 ].size() ; i++ )
		{
			if( i == 0 )
				cout << "   " << disk[ 2 ][ i ] ;
			else
				cout << " " << disk[ 2 ][ i ] ;
		}
		cout << endl ;
}

void hanoi( int movingPeg, int from, int to )
{
	int		i = 0 ; // loop counter

	if( movingPeg > 1 )
	{
		hanoi( movingPeg - 1, from, 3 - from - to ) ;
	}

	if( counter < n )
	{
		counter++ ;
		disk[ to ].push_back( disk[ from ].back() ) ;
		disk[ from ].pop_back() ;
		printState() ;
	}
	else
	{
		return ;
	}

	if( movingPeg > 1 )
	{
		hanoi( movingPeg - 1, 3 - from - to, to ) ;
	}
}

int main()
{
	int		m = 0 ;
	int		problemSet = 0 ;
	int		i = 0 ; // loop counter

	while( cin >> m >> n )
	{
		if( m == 0 && n == 0 )
			break ;

		problemSet++ ;
		disk[ 0 ].resize( m, 0 ) ;
		for( i = 0 ; i < m ; i++ )
			disk[ 0 ][ i ] = m - i ;
		disk[ 1 ].clear() ;
		disk[ 2 ].clear() ;

		cout << "Problem #" << problemSet << endl ;

		counter = 0 ;
		printState() ;
		hanoi( m, 0, 2 ) ;

		cout << endl ; // Print a blank line after every problem. 
	}

	return 0 ;
}

