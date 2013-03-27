#include <iostream>
using namespace std ;

#define MaxStep 46340
int		maxLen[ MaxStep + 1 ] = { 0 } ;

int main()
{
	int		x = 0 ;
	int		y = 0 ;
	int		t = 0 ;
	int		i = 0 ;

	maxLen[ 0 ] = 0 ;
	maxLen[ 1 ] = 1 ;
	for( i = 2 ; i <= MaxStep ; i++ )
		maxLen[ i ] = maxLen[ i - 2 ] + i ;
	
	cin >> t ;
	for( i = 0 ; i < t ; i++ )
	{
		cin >> x >> y ;
		cout << lower_bound( maxLen, maxLen + MaxStep + 1, y - x ) - maxLen << endl ;
	}
}
