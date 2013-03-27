#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std ;

bool cmp( const string &a, const string &b )
{
	return (a+b) > (b+a) ;
}

int main()
{
	int		n = 0 ;
	vector<string>	v ;
	int		i = 0 ;
	
	while( cin >> n && n != 0 )
	{
		v.assign( n, "" ) ;
		for( i = 0 ; i < n ; i++ )
		{	
			cin >> v[ i ] ;
		}
		
		sort( v.begin(), v.end(), cmp ) ;
		
		for( i = 0 ; i < n ; i++ )
			cout << v[ i ] ;
		cout << endl ;
	}
	
	return 0 ;
}
