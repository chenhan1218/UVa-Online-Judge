#include <iostream>
#include <bitset>
#include <algorithm>
#include <numeric>
using namespace std ;

#define MaxVoting 1000
#define MaxP 20 

int main()
{
	int		major[ MaxVoting + 1 ] = { 0 } ;
	int		votes[ MaxP ] = { 0 } ;
	int		sum = 0 ;
	int		p = 0 ;
	int		cases = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	int		m = 0 ;
	
	cin >> cases ;
	for( i = 0 ; i < cases ; i++ )
	{
		cin >> p ;
		for( j = 0 ; j < p ; j++ )
		{
			cin >> votes[ j ] ;
		}
		sum = accumulate( votes, votes + p, 0 ) ;
		
		for( j = 0 ; j < p ; j++ )
		{
			fill( major, major + sum + 1, 0 ) ;
			major[ 0 ] = 1 ;
			
			for( k = 0 ; k < p ; k++ )
			{
				if( k != j )
				{
					for( m = sum - votes[ k ] ; m >= 0 ; m-- )
					{
						major[ m + votes[ k ] ] += major[ m ] ;
					}
				}
			}
			
			cout << "party " << j+1 << " has power index " << accumulate( major + (sum+1)/2 - votes[ j ], major + (sum+1)/2, 0 ) << endl ;
		}
		
		cout << endl ; // followed by one empty line.
	}
	
	return 0 ;
}
