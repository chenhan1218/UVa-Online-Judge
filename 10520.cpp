#include <iostream>
using namespace std ;

int main()
{
	long long int	grid[ 20 ][ 20 ] = { 0 } ;
	int		n = 0 ;
	
	while( cin >> n )
	{
		cin >> grid[ n ][ 1 ] ;
		for( int row = n ; row >= 1 ; row-- )
		{
			for( int column = 0 ; column <= n ; column++ )
			{
				if( row == n && column == 1 )
					continue ;
				
				if( row >= column )
				{
					long long int first = 0 ;
					long long int second = 0 ;
					for( int k = row+1 ; k <= n ; k++ )
						first = max( first, grid[ k ][ 1 ] + grid[ k ][ column ] ) ;
					for( int k = 1 ; k < column ; k++ )
						second = max( second, grid[ row ][ k ] + grid[ n ][ k ] ) ;
					
					grid[ row ][ column ] = first + second ;
				}
				else
				{
					long long int first = 0 ;
					for( int k = row ; k < column ; k++ )
						first = max( first, grid[ row ][ k ] + grid[ k+1 ][ column ] ) ;
					
					grid[ row ][ column ] = first ;
				}
			}
		}
		
		cout << grid[ 1 ][ n ] << endl ;
	}
	
	return 0 ;
}
