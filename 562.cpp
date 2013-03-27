#include <iostream>
#include <bitset>
using namespace std ;

#define MaxCent 50000

int main()
{
	bitset<MaxCent + 1>	b ;
	int		cases = 0 ;
	int		m = 0 ;
	int		cent = 0 ;
	int		sum = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	cin >> cases ;
	for( i = 0 ; i < cases ; i++ )
	{
		cin >> m ;
		
		b.reset() ;
		b[ 0 ] = 1 ;
		sum = 0 ;
		for( j = 0 ; j < m ; j++ )
		{
			cin >> cent ;
			sum += cent ;
			b |= ( b << cent ) ;
		}
		
		for( j = sum/2 ; ; j-- )
		{
			if( b[ j ] == 1 )
				break ;
		}
		
		cout << ( sum - j ) - j << endl ;
	}
	
	return 0 ;
}
