#include <iostream>
#include <vector>
using namespace std ;

int main()
{
	int		n = 0 ;
	int		m = 0 ;
	int		c = 0 ;
	vector<int>		consumption ;
	vector<bool>	state ;
	int		device = 0 ;
	int		amperes = 0 ;
	int		maxAmperes = 0 ;
	int		sequence = 0 ;
	int		i = 0 ; // loop counter
	
	while( cin >> n >> m >> c )
	{
		if( n == 0 && m == 0 && c == 0 )
			break ;
		
		sequence++ ;
		
		consumption.assign( n+1, 0 ) ;
		state.assign( n+1, false ) ;
		
		for( i = 1 ; i <= n ; i++ )
			cin >> consumption[ i ] ;
		
		maxAmperes = 0 ;
		amperes = 0 ;
		for( i = 1 ; i <= m ; i++ )
		{
			cin >> device ;
			if( state[ device ] == false )
			{
				amperes += consumption[ device ] ;
				state[ device ] = true ;
			}
			else
			{
				amperes -= consumption[ device ] ;
				state[ device ] = false ;
			}

			maxAmperes = max( maxAmperes, amperes ) ;
		}
		
		cout << "Sequence " << sequence << endl ;
		if( maxAmperes > c )
		{
			cout << "Fuse was blown." << endl ;
		}
		else
		{
			cout << "Fuse was not blown." << endl ;
			cout << "Maximal power consumption was " << maxAmperes << " amperes." << endl ;
		}
		cout << endl ; //Output a blank line after each test case. 
	}
	
	return 0 ;
}
