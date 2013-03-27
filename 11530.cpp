#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std ;

int main()
{
	string	str ;
	int		casenum = 0 ;
	map<char,int>	press ;
	
	press[ 'a' ] = 1 ;
	press[ 'b' ] = 2 ;
	press[ 'c' ] = 3 ;
	press[ 'd' ] = 1 ;
	press[ 'e' ] = 2 ;
	press[ 'f' ] = 3 ;
	press[ 'g' ] = 1 ;
	press[ 'h' ] = 2 ;
	press[ 'i' ] = 3 ;
	press[ 'j' ] = 1 ;
	press[ 'k' ] = 2 ;
	press[ 'l' ] = 3 ;
	press[ 'm' ] = 1 ;
	press[ 'n' ] = 2 ;
	press[ 'o' ] = 3 ;
	press[ 'p' ] = 1 ;
	press[ 'q' ] = 2 ;
	press[ 'r' ] = 3 ;
	press[ 's' ] = 4 ;
	press[ 't' ] = 1 ;
	press[ 'u' ] = 2 ;
	press[ 'v' ] = 3 ;
	press[ 'w' ] = 1 ;
	press[ 'x' ] = 2 ;
	press[ 'y' ] = 3 ;
	press[ 'z' ] = 4 ;
	
	cin >> casenum ;
	getline( cin, str ) ; // absorb the end of line
	for( int runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		getline( cin, str ) ;
		
		int		num = 0 ;
		for( string::const_iterator iter = str.begin() ; iter != str.end() ; ++iter )
		{
			if( isalpha( *iter ) )
			{
				num += press[ *iter ] ;
			}
			else
			{
				num += 1 ;
			}
		}
		
		cout << "Case #" << runningCase << ": " << num << endl ;
	}
	
	return 0 ;
}
