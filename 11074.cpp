#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
	int	S = 0 ;
	int T = 0 ;
	int N = 0 ;
	int	cases = 0 ;
	int	i = 0, j = 0, k = 0, l = 0 ; // loop counter ;

	while( cin >> S >> T >> N )
	{
		if( S == 0 && T == 0 && N == 0 )
		{
			break ;
		}

		cases++ ;

		cout << "Case " << cases << ":" << endl ;

		for( i = 1 ; i <= T ; i++ )
		{
			for( j = 1 ; j <= T + ( T + S ) * N ; j++ )
			{
				cout << "*" ;
			}
			cout << endl ;
		}

		for( i = 1 ; i <= N ; i++ )
		{
			for( j = 1 ; j <= S ; j++ ) // Draw S lines of grid.
			{
				for( k = 1 ; k <= T ; k++ )
				{
					cout << "*" ;
				}

				for( k = 1 ; k <= N ; k++ )
				{
					for( l = 1 ; l <= S ; l++ )
					{
						cout << "." ;
					}

					for( l = 1 ; l <= T ; l++ )
					{
						cout << "*" ;
					}
				}

				cout << endl ;
			}

			for( j = 1 ; j <= T ; j++ ) // Print several drawing line.
			{
				for( k = 1 ; k <= T + ( T + S ) * N ; k++ )
				{
					cout << "*" ;
				}

				cout << endl ;
			}
		}

		cout << endl ;
	}

	return 0 ;
}
