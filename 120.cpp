#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std ;

int main()
{
	vector<int>	v ;
	vector<int>	sorted ;
	string	buffer ;
	int		index = 0 ;
	int		temp = 0 ;
	int		i = 0 ;
	
	while( getline( cin, buffer ) )
	{
		istringstream s ;
		s.str( buffer ) ;
		v.clear() ;
		while( s >> temp )
		{
			v.push_back( temp ) ;
		}
		sorted = v ;
		sort( sorted.begin(), sorted.end() ) ;
		
		// echo the original stack on one line, 
		for( i = 0 ; i < v.size() ; i++ )
		{
			if( i == 0 )
			{
				cout << v[ 0 ] ;
			}
			else
			{
				cout << " " << v[ i ] ;
			}
		}
		cout << endl ;
		
		for( i = sorted.size() - 1 ; i >= 0 ; i-- )
		{
			index = find( v.begin(), v.end(), sorted[ i ] ) - v.begin() ;
			
			if( index != i ) // need to filp
			{
				if( index != 0 )
				{
					// filp the pancake to the first
					cout << v.size() - index << " " ;
					reverse( v.begin(), v.begin() + index + 1 ) ;
				}
				
				cout << v.size() - i << " " ;
				reverse( v.begin(), v.begin() + i + 1 ) ;
			}
		}
		
		cout << 0 << endl ;
	}
	return 0 ;
}
