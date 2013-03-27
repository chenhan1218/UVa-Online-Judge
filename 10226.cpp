#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std ;

int main()
{
	int		n = 0 ;
	double	total = 0 ;
	map<string,int>	m ;
	string	buffer ;
	int		i = 0 ;
	
	cin.sync_with_stdio( false ) ;
	cout.sync_with_stdio( false ) ;
	
	cin >> n ;
	getline( cin, buffer ) ; // absorb end of line
	getline( cin, buffer ) ; // absorb end of line

	for( i = 1 ; i <= n ; i++ )
	{
		m.clear() ;
		total = 0 ;
		while( getline( cin, buffer ) && buffer != "" )
		{
			m[ buffer ] ++ ;
			total ++ ;
		}
		
		if( i != 1 )
		{
			cout << endl ;
		}
		for( map<string,int>::iterator iter = m.begin() ; iter != m.end() ; iter++ )
		{
			cout << iter->first << " " 
			<< fixed << setprecision( 4 ) << iter->second / total * 100 << endl ;
		}
	}
	
	return 0 ;
}
