#include <iostream>
#include <vector>
using namespace std ;

int main()
{
	vector<int>	factor ;
	int		n = 0 ;
	int		c = 0 ;
	int		r = 0 ;
	int		q = 0 ;
	int		t = 0 ;
	int		cases = 0 ;
	int		i = 0 ;
	
	cin >> t ;
	for( cases = 1 ; cases <= t ; cases++ )
	{
		cin >> c >> r ;
		cout << "Case #" << cases << ":" ;
		
		if( c == r )
		{
			cout << " " << 0 << endl ;
		}
		else
		{
			factor.clear() ;
			for( q = 1 ; q * q < c - r ; q++ )
			{
				if( (c-r) % q == 0 )
				{
					factor.push_back( q ) ;
					factor.push_back( (c-r) / q ) ;
				}
			}
			
			if( q * q == c - r )
				factor.push_back( q ) ;
			
			sort( factor.begin(), factor.end() ) ;
			
			for( i = 0 ; i < factor.size() ; i++ )
			{
				if( factor[ i ] > r )
					cout << " " << factor[ i ] ;
			}
			cout << endl ;
		}
	}
	
	return 0 ;
}
