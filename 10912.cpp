#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

#define MaxL 26
#define MaxS 351

int main()
{
	int		num[ MaxL + 1 ][ MaxS + 1 ][ 27 ] = { 0 } ;
	int		l = 0 ;
	int		s = 0 ;
	int		casenum = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	num[ 0 ][ 0 ][ 0 ] = 1 ;
		
	for( i = 1 ; i <= MaxL ; i++ )
	{
		for( j = 1 ; j <= MaxS ; j++ )
		{
			for( k = 1 ; k <= min( j, 26 ) ; k++ )
			{
				num[ i ][ j ][ k ] = accumulate( num[ i - 1 ][ j - k ], num[ i - 1 ][ j - k ] + k, 0 ) ;
			}
		}
	}
	
	while( cin >> l >> s && l != 0 && s != 0 )
	{
		casenum++ ;
		
		if( l > MaxL || s > MaxS )
		{
			cout << "Case " << casenum << ": " << 0 << endl ;
		}
		else
		{
			cout << "Case " << casenum << ": " << accumulate( num[ l ][ s ] + 1, num[ l ][ s ] + 27, 0 ) << endl ;
		}
	}
	
	return 0 ;
}

/* AC and elegant but low rank version
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

#define MaxL 150
#define MaxS 10000

int		num[ MaxL + 1 ][ MaxS + 1 ] = { 0 } ;

void dfs( int d, int counter, int sum )
{
	int		i = 0 ;
	
	if( sum > MaxS )
		return ;
	
	num[ d ][ sum ] += 1 ;
	for( i = counter ; i <= 26 ; i++ )
	{
		dfs( d + 1, i + 1, sum + i ) ;
	}
}

int main()
{
	int		l = 0 ;
	int		s = 0 ;
	int		casenum = 0 ;
	int		i = 0 ;
	
	dfs( 0, 1, 0 ) ;
	
	while( cin >> l >> s && l != 0 && s != 0 )
	{
		casenum++ ;
		
		if( l <= MaxL )
		{
			cout << "Case " << casenum << ": " << num[ l ][ s ] << endl ;
		}
		else
		{
			cout << "Case " << casenum << ": " << 0 << endl ;
		}
	}
	
	return 0 ;
}
*/

/* too slow
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

#define MaxS 10000

int main()
{
	int		**num = new int *[ MaxS + 1 ] ;
	int		**temp = new int *[ MaxS + 1 ] ;
	int		l = 0 ;
	int		s = 0 ;
	int		casenum = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	for( i = 0 ; i <= MaxS ; i++ )
	{
		num[ i ] = new int[ 27 ] ;
		temp[ i ] = new int[ 27 ] ;
	}
	
	while( cin >> l >> s && l != 0 && s != 0 )
	{
		casenum++ ;
		
		for( i = 0 ; i <= MaxS ; i++ )
		{
			fill( num[ i ], num[ i ] + 27, 0 ) ;
			
			if( i >= 1 && i <= 26 )
			{
				num[ i ][ i ] = 1 ;
			}
		}
		
		for( i = 2 ; i <= l ; i++ )
		{
			for( j = 0 ; j <= s ; j++ )
			{
				fill( temp[ j ], temp[ j ] + 27, 0 ) ;
				for( k = 1 ; k <= min( j, 26 ) ; k++ )
				{
					temp[ j ][ k ] = accumulate( num[ j - k ] + 1, num[ j - k ] + k, 0 ) ;
				}
			}
			
			swap( temp, num ) ;
		}
		
		cout << "Case " << casenum << ": " << accumulate( num[ s ] + 1, num[ s ] + 27, 0 ) << endl ;
	}
	
	return 0 ;
}
*/
