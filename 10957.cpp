#include <iostream>
#include <iomanip>
#include <vector>
using namespace std ;

class sudoku
{
	public:
		int		n ;
		vector<int>	grid ;
		bool	solved ;
		bool	ambiguous ;
		bool	input()
		{
			int		i = 0 ; // loop counter
			int		j = 0 ; // loop counter
			int		temp ;
			grid.clear() ;
			solved = false ;
			ambiguous = false ;
			for( i = 0 ; i < n*n ; i++ )
			{
				for( j = 0 ; j < n*n ; j++ )
				{
					cin >> temp ;
					grid.push_back( temp ) ;
				}
			}

			if( cin.fail() == true )
				return false ;
			else
				return true ;
		}

		void	output()
		{
			int		i = 0 ; // loop counter
			int		j = 0 ; // loop counter
			if( solved == true )
			{
				for( i = 0 ; i < n*n ; i++ )
				{
					for( j = 0 ; j < n*n ; j++ )
					{
						if( j > 0 )
						{
							cout << " " ;
						}
						cout << grid[ i * n*n + j ] ;
					}
					cout << endl ;
				}
			}
			else
			{
				cout << "NO SOLUTION" << endl ;
			}
		}

		bool	valid()
		{
			int		i = 0 ; // loop counter
			int		j = 0 ; // loop counter
			for( i = 0 ; i < n*n ; i++ )
			{
				for( j = 0 ; j < n*n ; j++ )
				{
					if( grid[ i * n*n + j ] != 0 )
						if( check( i, j ) == false )
							return false ;
				}
			}

			return true ;
		}

		bool	check( const int row, const int column )
		{
			int		i = 0 ; // loop counter
			int		j = 0 ; // loop counter
			for( i = 0 ; i < n*n ; i++ )
			{
				if( i == column )
					continue ;
				if( grid[ row * n*n + i ] == grid[ row * n*n + column ] )
					return false ;
			}
			for( i = 0 ; i < n*n ; i++ )
			{
				if( i == row )
					continue ;
				if( grid[ i * n*n + column ] == grid[ row * n*n + column ] )
					return false ;
			}

			for( i = row - (row%n) ; i < row - (row%n) + n ; i++ )
			{
				for( j = column - (column%n) ; j < column - (column%n) + n ; j++ )
				{
					if( i == row && j == column )
						continue ;
					if( grid[ i * n*n + j ] == grid[ row * n*n + column ] )
						return false ;
				}
			}

			return true ;
		}

		int		solve( const int row, const int column )
		{
			int		i = 0 ; // loop counter

			if( row == n*n )
			{
				if( solved == false )
				{
					solved = true ;
				}
				else if( ambiguous == false )
				{
					ambiguous = true ;
				}
			}

			if( grid[ row * n*n + column ] == 0 )
			{
				for( i = 1 ; i <= n*n && ambiguous == false ; i++ )
				{
					grid[ row * n*n + column ] = i ;
					if( check( row, column ) == false )
						continue ;

					if( column == n*n - 1 )
					{
						solve( row + 1, 0 ) ;
					}
					else
					{
						solve( row , column + 1 ) ;
					}
				}

				if( ambiguous == false )
				{
					grid[ row * n*n + column ] = 0 ;
				}
			}
			else
			{
				if( column == n*n - 1 )
				{
					solve( row + 1, 0 ) ;
				}
				else
				{
					solve( row , column + 1 ) ;
				}
			}
		}
};

int
main()
{
	sudoku	s ;
	int		casenumber = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	s.n = 3 ;

	while( s.input() )
	{
		casenumber++ ;

		if( s.valid() == false )
		{
			cout << "Case " << casenumber << ": Illegal." << endl ;
		}
		else
		{
			s.solve( 0, 0 ) ;
			if( s.solved == false )
			{
				cout << "Case " << casenumber << ": Impossible." << endl ;
			}
			else if( s.ambiguous == false )
			{
				cout << "Case " << casenumber << ": Unique." << endl ;
			}
			else
			{
				cout << "Case " << casenumber << ": Ambiguous." << endl ;
			}
		}
	}

	return 0 ;
}
