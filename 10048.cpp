#include <iostream>
#include <climits>
#include <algorithm>
using namespace std ;

int main()
{
	int		c = 0 ;
	int		s = 0 ;
	int		q = 0 ;
	const int	MaxC = 100 ;
	int		decibel[ MaxC + 1 ][ MaxC + 1 ] = { 0 } ;
	int		casenum = 0 ;
	
	while( cin >> c >> s >> q )
	{
		casenum++ ;
		if( c == 0 && s == 0 && q == 0 )
			break ;
		
		int		c1 = 0 ;
		int		c2 = 0 ;
		int		d = 0 ;
		
		for( int i = 1 ; i <= c ; i++ )
			fill( decibel[ i ]+1, decibel[ i ]+c+1, INT_MAX ) ;
		
		for( int i = 0 ; i < s ; i++ )
		{
			cin >> c1 >> c2 >> d ;
			decibel[ c1 ][ c2 ] = d ;
			decibel[ c2 ][ c1 ] = d ;
		}
		
		for( int k = 1 ; k <= c ; k++ )
		{
			for( int i = 1 ; i <= c ; i++ )
			{
				for( int j = 1 ; j <= c ; j++ )
				{
					decibel[ i ][ j ] = min( decibel[ i ][ j ], 
					max( decibel[ i ][ k ], decibel[ k ][ j ] ) ) ;
				}
			}
		}
		
		//Print a blank line between two consecutive test cases. 
		if( casenum > 1 )
			cout << endl ;
		cout << "Case #" << casenum << endl ;
		
		for( int i = 0 ; i < q ; i++ )
		{
			cin >> c1 >> c2 ;
			if( decibel[ c1 ][ c2 ] == INT_MAX )
			{
				cout << "no path" << endl ;
			}
			else
			{
				cout << decibel[ c1 ][ c2 ] << endl ;
			}
		}
	}
	
	return 0 ;
}
