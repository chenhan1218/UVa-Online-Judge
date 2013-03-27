#include <iostream>
#include <algorithm>
using namespace std ;

int main()
{
	long long int	len[ 3 ] = { 0 } ;
	int		t = 0 ;
	
	cin >> t ;
	for( int i = 1 ; i <= t ; i++ )
	{
		cin >> len[ 0 ] >> len[ 1 ] >> len[ 2 ] ;
		sort( len, len+3 ) ;
		
		cout << "Case " << i << ": " ;
		if( len[ 0 ] > 0 && len[ 0 ] + len[ 1 ] > len[ 2 ] )
		{
			if( len[ 0 ] == len[ 1 ] )
			{
				if( len[ 1 ] == len[ 2 ] )
				{
					cout << "Equilateral" ;
				}
				else
				{
					cout << "Isosceles" ;
				}
			}
			else
			{
				if( len[ 1 ] == len[ 2 ] )
				{
					cout << "Isosceles" ;
				}
				else
				{
					cout << "Scalene" ;
				}
			}
		}
		else
		{
			cout << "Invalid" ;
		}
		
		cout << endl ;
	}
	
	return 0 ;
}
