#include <iostream>
using namespace std ;

int main()
{
	int **Minesweep = new int *[ 100 ] ;
	Minesweep-- ;
	for( int i = 1 ; i <= 100 ; i++ )
	{
		Minesweep[ i ] = new int [ 100 ] ;
		Minesweep[ i ] -- ;

		for( int k = 1 ; k <= 100 ; k++ )
		{
			Minesweep[ i ][ k ] = 0 ;
		}
	}

	int n , m ;

	char input ;

	for( int i = 1 ; ; i++ )
	{
		cin >> n >> m ;

		if( n == 0 && m == 0 )
		{
			break ;
		}

		for( int j = 1 ; j <= n ; j++ )
		{
			for( int k = 1 ; k <= m ; k++ )
			{
				cin >> input ;

				if( input == '*' )
				{
					Minesweep[ j ][ k ] = -9 ;

					if( j > 1 )
					{
						if( k > 1 )
						{
							Minesweep[ j - 1 ][ k - 1 ] ++ ;
						}

						Minesweep[ j - 1 ][ k ] ++ ;

						if( k < m )
						{
							Minesweep[ j - 1 ][ k + 1 ] ++ ;
						}
					}

					if( k > 1 )
					{
						Minesweep[ j ][ k - 1 ] ++ ;
					}
					if( k < m )
					{
						Minesweep[ j ][ k + 1 ] ++ ;
					}

					if( j < n )
					{
						if( k > 1 )
						{
							Minesweep[ j + 1 ][ k - 1 ] ++ ;
						}

						Minesweep[ j + 1 ][ k ] ++ ;

						if( k < m )
						{
							Minesweep[ j + 1 ][ k + 1 ] ++ ;
						}
					}
				}
			}
		}

		if( i != 1 )
		{
			cout << endl ;
		}

		cout << "Field #" << i << ":" << endl ;
		for( int j = 1 ; j <= n ; j++ )
		{
			for( int k = 1 ; k <= m ; k++ )
			{
				if( Minesweep[ j ][ k ] < 0 )
				{
					cout << "*" ;
				}
				else
				{
					cout << Minesweep[ j ][ k ] ;
				}

				Minesweep[ j ][ k ] = 0 ;
			}

			cout << endl ;
		}
	}

	return 0 ;
}
