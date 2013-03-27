#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std ;

#include <algorithm>
#include <string>

class puzzle
{
	friend istream &operator>>( istream &is, puzzle &a )
	{
		int		i = 0 ;
		for( i = 0 ; i < frame * frame ; i++ )
		{
			cin >> a.grid[ i ] ;
			if( a.grid[ i ] == 'x' )
			{
				a.grid[ i ] = '0' ;
				a.x = i ;
			}
		}
	}

	public :
		puzzle()
		{
			route = "" ;
		}
		bool solved() {
			int		i = 0 ; // loop counter

			for( i = 0 ; i < frame * frame - 1 ; i++ )
			{
				if( grid[ i ] - '0' != i + 1 )
				{
					return false ;
				}
			}
			return true ;
		}

		void	move( char a )
		{
			switch( a )
			{
				case 'u' :
					swap( grid[ x ], grid[ x - 3 ] ) ;
					x -= 3 ;
					route = 'd' + route ;
					break ;
				case 'd' :
					swap( grid[ x ], grid[ x + 3 ] ) ;
					x += 3 ;
					route = 'u' + route ;
					break ;
				case 'l' :
					swap( grid[ x ], grid[ x - 1 ] ) ;
					x -= 1 ;
					route = 'r' + route ;
					break ;
				case 'r' :
					swap( grid[ x ], grid[ x + 1 ] ) ;
					x += 1 ;
					route = 'l' + route ;
					break ;
			}
		}
		static const int	frame ;
		int		x ;
		char	grid[ 9 ] ;
		string	route ;
};
const int	puzzle::frame = 3 ;

class hash
{
	public :
		hash*	link[ puzzle::frame * puzzle::frame ] ;
		string	route ;

		hash() 
		{
			fill( link, link + puzzle::frame * puzzle::frame, (hash *)NULL ) ;
			route = "" ;
		}

		hash* getNode( const puzzle &a )
		{
			hash*	ptr = this ;
			int		i = 0 ;
			for( i = 0 ; i < puzzle::frame * puzzle::frame ; i++ )
			{
				if( ptr->link[ a.grid[ i ] - '0' ] == NULL )
				{
					ptr->link[ a.grid[ i ] - '0' ] = new hash() ;
				}

				ptr = ptr->link[ a.grid[ i ] - '0' ] ;
			}

			return ptr ;
		}

		hash* search( const puzzle &a )
		{
			hash*	ptr = this ;
			int		i = 0 ;
			for( i = 0 ; i < puzzle::frame * puzzle::frame ; i++ )
			{
				ptr = ptr->link[ a.grid[ i ] - '0' ] ;
				if( ptr == NULL )
				{
					break ;
				}
			}

			return ptr ;
		}
};

queue<puzzle>	visited ;
hash	start ;

void traceOut()
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	puzzle temp ;
	while( visited.empty() == false )
	{
		if( 0 < visited.front().x / 3 )
		{
			temp = visited.front() ;
			temp.move( 'u' ) ;

			if( start.search( temp ) == NULL )
			{
				( start.getNode( temp ) )->route = temp.route ;
				visited.push( temp ) ;
			}
		}
		if( visited.front().x / 3 + 1 < puzzle::frame )
		{
			temp = visited.front() ;
			temp.move( 'd' ) ;

			if( start.search( temp ) == NULL )
			{
				( start.getNode( temp ) )->route = temp.route ;
				visited.push( temp ) ;
			}
		}
		if( 0 < visited.front().x % 3 )
		{
			temp = visited.front() ;
			temp.move( 'l' ) ;

			if( start.search( temp ) == NULL )
			{
				( start.getNode( temp ) )->route = temp.route ;
				visited.push( temp ) ;
			}
		}
		if( visited.front().x % 3 + 1 < puzzle::frame )
		{
			temp = visited.front() ;
			temp.move( 'r' ) ;

			if( start.search( temp ) == NULL )
			{
				( start.getNode( temp ) )->route = temp.route ;
				visited.push( temp ) ;
			}
		}

		visited.pop() ;
	}
}

int
main()
{
	int		N = 0 ;
	int		cases = 0 ;
	puzzle	answer ;
	puzzle	input ;
	hash*	ptr ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 0 ; i < puzzle::frame * puzzle::frame - 1 ; i++ )
	{
		answer.grid[ i ] = '0' + i + 1 ;
	}
	answer.grid[ puzzle::frame * puzzle::frame - 1 ] = '0' ;
	answer.x = puzzle::frame * puzzle::frame - 1 ;

	start.getNode( answer ) ;
	visited.push( answer ) ;

	traceOut() ;

	cin >> N ;
	for( cases = 1 ; cases <= N ; cases++ )
	{
		if( cases > 1 )
		{
			cout << endl ;
		}

		cin >> input ;

		if( start.search( input ) != NULL )
		{
			cout << (start.getNode( input ))->route << endl ;
		}
		else
		{
			cout << "unsolvable" << endl ;
		}
	}

	return 0 ;
}
