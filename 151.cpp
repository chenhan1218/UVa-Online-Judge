#include <iostream>
using namespace std ;

#define MaxN 100

long long int gcd( long long int a, long long int b )
{
	while( b != 0 )
	{
		a %= b ;
		swap( a, b ) ;
	}
	return a ;
}

int main()
{
	bool	visited[ MaxN ] = { 0 } ;
	int		n = 0 ;
	int		m = 0 ;
	int		now = 0 ;
	int		numSelected = 0 ;
	int		i = 0 ;
	
	while( cin >> n && n != 0 )
	{
		for( m = 1 ;  ; m++ )
		{
			fill( visited, visited + n, false ) ;
			now = 0 ;
			visited[ 0 ] = true ;
			for( numSelected = 1 ; numSelected < n ; numSelected++ )
			{
				for( i = 0 ; i < m ; i++ )
				{
					do
					{
						now = ( now + 1 ) % n ;
					} while( visited[ now ] == true ) ;
				}
				
				visited[ now ] = true ;
				
				if( now+1 == 13 )
					break ;
			}
			
			if( numSelected == n - 1 )
				break ;
		}
		
		cout << m << endl ;
	}
	
	return 0 ;
}
