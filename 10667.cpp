#include <iostream>
using namespace std ;

const int MaxDimension = 100 ;
bool	isfree[ MaxDimension + 1 ][ MaxDimension + 1 ] = { 0 } ;
int		columnSum[ MaxDimension + 2 ][ MaxDimension + 2 ][ MaxDimension + 2 ] = { 0 } ;

int main()
{
	int		p = 0 ;
	int		s = 0 ;
	int		b = 0 ;
	int		r1 = 0 ;
	int		c1 = 0 ;
	int		r2 = 0 ;
	int		c2 = 0 ;
	int		maxBlock = 0 ;
	
	cin >> p ;
	for( int cases = 1 ; cases <= p ; cases++ )
	{
		cin >> s >> b ;
		for( int i = 1 ; i <= s ; i++ )
			fill( isfree[ i ] + 1, isfree[ i ] + s + 1, true ) ;
		
		for( int block = 1 ; block <= b ; block++ )
		{
			cin >> r1 >> c1 >> r2 >> c2 ;
			for( int i = r1 ; i <= r2 ; i++ )
				fill( isfree[ i ] + c1, isfree[ i ] + c2 + 1, false ) ;
		}
		
		for( int i = 1 ; i <= s ; i++ )
		{
			for( int j = 1 ; j <= s ; j++ )
			{
				for( int k = 1 ; k <= i ; k++ )
				{
					columnSum[ k ][ i + 1 ][ j ] = columnSum[ k ][ i ][ j ] ;
					if( isfree[ i ][ j ] == true )
					{
						columnSum[ k ][ i + 1 ][ j ] += 1 ;
					}
				}
			}
		}
		
		maxBlock = 0 ;
		for( int i = 1 ; i <= s ; i++ )
		{
			for( int j = i + 1 ; j <= s + 1 ; j++ )
			{
				int begin = 0 ;
				for( int k = 1 ; k <= s ; k++ )
				{
					if( columnSum[ i ][ j ][ k ] == j - i )
					{
						maxBlock = max( maxBlock, (j-i)*(k-begin)) ;
					}
					else
					{
						begin = k ;
					}
				}
			}
		}
		
		cout << maxBlock << endl ;
	}
	
	return 0 ;
}
