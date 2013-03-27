#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std ;

int main()
{
	int		p = 0 ;
	int		t = 0 ;
	string	buffer ;
	int		opinions = 0 ;
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	cin.sync_with_stdio( false ) ;
	cout.sync_with_stdio( false ) ;
	
	getline( cin, buffer ) ;
	sscanf( buffer.c_str(), "%d", &casenum ) ;
	getline( cin, buffer ) ; // absorb the blank line

	for( runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		getline( cin, buffer ) ;
		sscanf( buffer.c_str(), "%d%d", &p, &t ) ;
		vector< set<int> >	listen( p + 1 ) ;
		
		while( getline( cin, buffer ) && buffer != "" )
		{
			sscanf( buffer.c_str(), "%d%d", &i, &j ) ;
			listen[ i ].insert( j ) ;
		}
		
		sort( listen.begin() + 1, listen.end() ) ;
		opinions = 1 ;
		for( i = 2 ; i <= p ; i++ ) // use a loop to count the opinions
		{
			if( listen[ i ] != listen[ i - 1 ] )
				opinions++ ;
		}
		
		if( runningCase > 1 ) // not the first case
		{
			cout << endl ;
		}
		cout << opinions << endl ;
	}
	
	return 0 ;
}
