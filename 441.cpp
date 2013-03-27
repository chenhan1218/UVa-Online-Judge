#include <iostream>
using namespace std ;

int	k = 0 ;
int	setS[ 12 ] = { 0 } ;
int	possibleGames[ 7 ] = { 0 } ;

void recursiveLayer( int layer );

int main()
{
	int	i = 0 ; // loop counter
	int	cases = 0 ;

	while( cin >> k )
	{
		if( k == 0 )
		{
			break ;
		}

		cases++ ;
		if( cases > 1 )
		{
			cout << endl ;
		}

		for( i = 1 ; i <= k ; i++ )
		{
			cin >> setS[ i ] ;
		}

		recursiveLayer( 1 ) ;
	}

	return 0 ;
}
void recursiveLayer( int layer )
{
	if( layer == 1 )
	{
		possibleGames[ 1 ] = 1 ;
		do
		{
			recursiveLayer( layer + 1 ) ; // go to next layer

			possibleGames[ 1 ] += 1 ;
		}while( possibleGames[ 1 ] < possibleGames[ 2 ] );
	}
	else if( layer == 6 )
	{
		possibleGames[ 6 ] = possibleGames[ 5 ] + 1 ;

		do
		{
			cout 	<< setS[ possibleGames[ 1 ] ] << " "
					<< setS[ possibleGames[ 2 ] ] << " "
					<< setS[ possibleGames[ 3 ] ] << " "
					<< setS[ possibleGames[ 4 ] ] << " "
					<< setS[ possibleGames[ 5 ] ] << " "
					<< setS[ possibleGames[ 6 ] ] << endl ;

			possibleGames[ 6 ] += 1 ;
		}while( possibleGames[ 6 ] <= k );
	}
	else
	{
		possibleGames[ layer ] = possibleGames[ layer - 1 ] + 1 ;

		do
		{
			recursiveLayer( layer + 1 ); // go to next layer

			possibleGames[ layer ] += 1 ;
		}while( possibleGames[ layer ] < possibleGames[ layer + 1 ] );
	}

	possibleGames[ layer ] -= 1 ;
	// subtruct 1 from possibleGames[ layer ] to prevent step beyond the boundary.
	// (because the stop condition in the loop will cause number of possibleGame
	// to be overlapped)
}

