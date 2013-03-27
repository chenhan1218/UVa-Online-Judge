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
		void	input()
		{
			int		i = 0 ; // loop counter
			int		j = 0 ; // loop counter
			int		temp ;
			grid.clear() ;
			solved = false ;
			for( i = 0 ; i < n*n ; i++ )
			{
				for( j = 0 ; j < n*n ; j++ )
				{
					cin >> temp ;
					grid.push_back( temp ) ;
				}
			}
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

		void	solve( const int row, const int column )
		{
			int		i = 0 ; // loop counter

			if( row == n*n )
				solved = true ;

			if( grid[ row * n*n + column ] == 0 )
			{
				for( i = 1 ; i <= n*n && solved == false ; i++ )
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

				if( solved == false )
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
	bool	firstcase = true ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> s.n )
	{
		s.input() ;

		s.solve( 0, 0 ) ;

		if( firstcase == true )
		{
			firstcase = false ;
		}
		else
		{
			cout << endl ;
		}
		s.output() ;
	}

	return 0 ;
}
