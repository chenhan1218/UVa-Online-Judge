#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std ;

int isDominate( const string &a, const string &b )
{
	if( a.length() < b.length() )
		return false ;
	
	for( string::size_type ix = 0 ; ix < b.length() ; ++ix )
	{
		if( ix == 0 || b[ ix - 1 ] != b[ ix ] )
		{
			if( count( a.begin(), a.end(), b[ ix ] ) < 
				count( b.begin(), b.end(), b[ ix ] ) )
			{
				return false ;
			}
		}
	}
	
	return true ;
}

int main()
{
	string		line ;
	map<string,string>	dominate ;
	
	while( cin >> line )
	{
		string	sortedLine = line ;
		sort( sortedLine.begin(), sortedLine.end() ) ;
		
		map<string,string>::iterator	iter ;
		for( iter = dominate.begin() ; iter != dominate.end() ; ++iter )
		{
			if( isDominate( sortedLine, iter->second ) == true )
			{
				dominate.erase( iter ) ;
				iter-- ;
				continue ;
			}
			
			if( isDominate( iter->second, sortedLine ) == true )
			{
				break ;
			}
		}
		
		if( iter == dominate.end() )
			dominate[ line ] = sortedLine ;
	}
	
	for( map<string,string>::iterator iter = dominate.begin() ; iter != dominate.end() ; iter++ )
		cout << iter->first << endl ;
	
	return 0 ;
}
