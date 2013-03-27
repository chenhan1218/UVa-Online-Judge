#include <iostream>
using namespace std ;

#define MaxN 10

int main()
{
	long long int	grid[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;
	long long int	sum[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;
	int		n = 0 ;
	int		space = 0 ;
	int		caseNum = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	while( cin >> n && n != 0 )
	{
		caseNum++ ;
		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
			{
				cin >> grid[ i ][ j ] ;
				sum[ i ][ j ] = sum[ i - 1 ][ j ] + sum[ i ][ j - 1 ] - sum[ i - 1 ][ j - 1 ] + grid[ i ][ j ] ;
			}
		}
		
		cout << "Case " << caseNum << ":" ;
		for( space = 0 ; space * 2 + 1 < n ; space++ )
		{
			cout << " " << sum[ n - space ][ n - space ] - 
						sum[ space ][ n - space ] - 
						sum[ n - space ][ space ] + 
						sum[ space ][ space ] - 
						( sum[ n - space - 1 ][ n - space - 1 ] - 
						sum[ space + 1 ][ n - space - 1 ] - 
						sum[ n - space - 1 ][ space + 1 ] + 
						sum[ space + 1 ][ space + 1 ] );
		}
		if( space * 2 + 1 == n )
		{
			cout << " " << grid[ (n+1)/2 ][ (n+1)/2 ] ;
		}
		cout << endl ;
	}
	
	return 0 ; 
}
