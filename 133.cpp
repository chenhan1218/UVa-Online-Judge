#include <iostream>
#include <iomanip>

using namespace std ;

int
moving( int *status, int N, int starting, int direction )
{
	if( direction > 0 )
	{
		while( 1 )
		{
			starting++ ;

			if( starting > N )
			{
				starting = 1 ;
			}

			if( status[ starting ] > 0 )
			{
				break ;
			}
		}
	}
	else
	{
		while( 1 )
		{
			starting-- ;

			if( starting < 1 )
			{
				starting = N ;
			}

			if( status[ starting ] > 0 )
			{
				break ;
			}
		}
	}

	return starting ;
}

int main()
{
	int	N = 0 ;
	int	k = 0 ;
	int	m = 0 ;
	int	status[ 20 ] = { 0 } ;
	int	i = 0 ; // loop counter
	int CCofficial = 0 ; //counter-clockwise official
	int	Cofficial = 0 ; //clockwise official
	int remain = 0 ;

	while( cin >> N >> k >> m )
	{
		if( N == 0 && k == 0 && m == 0 )
		{
			break ;
		}
		else
		{
			for( i = 1 ; i <= N ; i++ )
			{
				status[ i ] = 1 ;
			}
			remain = N ;

			CCofficial = N ;	// We don't start from 1.
								// Instead, we backforward one step to N.
			Cofficial = 1 ;		// We don't start from N.
								// Instead, we backforward one step to 1.

			while( remain > 0 )
			{
				for( i = 1 ; i <= k ; i++ )
				{
					CCofficial = moving( status, N, CCofficial, 1 ) ;
					// moving counter-clockwise ;
				}

				for( i = 1 ; i <= m ; i++ )
				{
					Cofficial = moving( status, N, Cofficial, -1 ) ;
					// moving clockwise ;
				}

				status[ CCofficial ] = 0 ;
				status[ Cofficial ] = 0 ;

				if( remain != N )
				// If this is not the first victim, there should have a comma.
				{
					cout << "," ;
				}
				cout << setw( 3 ) << CCofficial ;
				status[ CCofficial ] = 0 ;
				remain-- ;

				if( Cofficial != CCofficial )
				// If Cofficial is not the same as CCofficial, print it.
				{
					cout << setw( 3 ) << Cofficial ;
					status[ Cofficial ] = 0 ;
					remain-- ;
				}
			}

			cout << endl ;
		}
	}

	return 0 ;
}
