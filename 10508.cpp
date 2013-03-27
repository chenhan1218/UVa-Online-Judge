#include <iostream>
#include <string>
#include <vector>
using namespace std ;

int diff( const string &a, const string &b )
{
	int		ret = 0 ;
	for( string::size_type i = 0 ; i < min( a.length(), b.length() ) ; i++ )
		if( a[ i ] != b[ i ] )
			ret ++ ;
	
	return ret ;
}

int main()
{
	int		numWords = 0 ;
	int		letters = 0 ;
	vector<string>	v ;
	string	word ;
	
	while( cin >> numWords >> letters )
	{
		v.resize( numWords ) ;
		cin >> v[ 0 ] >> v[ numWords - 1 ] ;
		for( int i = 1 ; i <= numWords - 2 ; i++ )
		{
			cin >> word ;
			v[ diff( word, v[ 0 ] ) ] = word ;
		}
		
		for( vector<string>::size_type i = 0 ; i < v.size() ; i++ )
			cout << v[ i ] << endl ;
	}
	
	return 0 ;
}
