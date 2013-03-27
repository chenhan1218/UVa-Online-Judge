#include <iostream>
using namespace std ;

const int MaxDimension = 100 ;
int		columnSum[ MaxDimension + 2 ][ MaxDimension + 2 ][ MaxDimension + 2 ] = { 0 } ;

int main()
{
	int		row = 0 ;
	int		column = 0 ;
	char	element ;
	long long int	total = 0 ;
	
	while( cin >> row >> column )
	{
		total = 0 ;
		for( int i = 1 ; i <= row ; i++ )
		{
			for( int j = 1 ; j <= column ; j++ )
			{
				cin >> element ;
				for( int k = 1 ; k <= i ; k++ )
				{
					columnSum[ k ][ i + 1 ][ j ] = columnSum[ k ][ i ][ j ] ;
					if( element == '1' )
					{
						columnSum[ k ][ i + 1 ][ j ] += 1 ;
					}
				}
			}
		}
		
		for( int i = 1 ; i <= row ; i++ )
		{
			for( int j = i + 1 ; j <= row + 1 ; j++ )
			{
				int begin = 0 ;
				for( int k = 1 ; k <= column ; k++ )
				{
					if( columnSum[ i ][ j ][ k ] == j - i )
					{
						total += k - begin ;
					}
					else
					{
						begin = k ;
					}
				}
			}
		}
		
		cout << total << endl ;
	}
	
	return 0 ;
}
