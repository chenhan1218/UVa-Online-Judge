#include <iostream>
#include <vector>
#include <string>
using namespace std ;

#define MaxN 25

int		sum[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;

int main()
{
	int		n = 0 ;
	vector<string>	grid ;
	string	buffer ;
	int		maxArea = 0 ;
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		p = 0 ;
	int		q = 0 ;
	
	cin >> casenum ;
	for( runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		cin >> buffer ;
		n = buffer.length() ;
		grid.assign( n , "" ) ;
		grid[ 0 ] = buffer ;
		for( i = 1 ; i < n ; i++ )
		{
			cin >> buffer ;
			grid[ i ] = buffer ;
		}
		
		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
			{
				sum[ i ][ j ] = sum[ i - 1 ][ j ] + sum[ i ][ j - 1 ] - sum[ i - 1 ][ j - 1 ] ;
				if( grid[ i - 1 ][ j - 1 ] == '1' )
				{
					sum[ i ][ j ] ++ ;
				}
			}
		}
		
		maxArea = 0 ;
		for( i = 0 ; i < n ; i++ )
		{
			for( j = 0 ; j < n ; j++ )
			{
				for( p = i+1 ; p <= n ; p++ )
				{
					for( q = j+1 ; q <= n ; q++ )
					{
						if( sum[ p ][ q ] - sum[ p ][ j ] - sum[ i ][ q ] + sum[ i ][ j ] == ( p - i )*( q - j ) )
							maxArea = max( maxArea, ( p - i )*( q - j ) ) ;
					}
				}
			}
		}
		
		if( runningCase > 1 )
			cout << endl ;
		cout << maxArea << endl ;
	}
	
	return 0 ;
}
