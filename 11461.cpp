#include <iostream>
#include <vector>
using namespace std ;

int main()
{
	vector<int>	square ;
	int		a = 0 ;
	int		b = 0 ;
	for( int i = 0 ; i*i <= 100000 ; i++ )
	{
		square.push_back( i*i ) ;
	}
	
	while( cin >> a >> b )
	{
		if( a == 0 && b == 0 )
			break ;
		
		cout << lower_bound( square.begin(), square.end(), b+1 ) - 
				lower_bound( square.begin(), square.end(), a ) << endl ;
	}
	
	return 0 ;
}
