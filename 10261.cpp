#include <iostream>
#include <vector>
#include <set>
using namespace std ;

int main()
{
	int		testcase = 0 ;
	const int	MaxLen = 10000 ;
	
	cin.sync_with_stdio( false ) ;
	cout.sync_with_stdio( false ) ;
	
	cin >> testcase ;
	for( int runningCase = 1 ; runningCase <= testcase ; runningCase++ )
	{
		int		ferry = 0 ;
		int		buffer = 0 ;
		int		sum = 0 ;
		vector<int>		car ;
		set<int>		port[ MaxLen + 1 ] ;
		pair<int,set<int> >	result ;
		
		cin >> ferry ;
		ferry *= 100 ;
		
		while( cin >> buffer && buffer != 0 )
			car.push_back( buffer ) ;
		
		for( int i = 0 ; i < car.size() ; i++ )
		{
			for( int j = ferry - car[ i ] ; j >= 0 ; j-- )
			{
				if( port[ j ].empty() == false && port[ j + car[ i ] ].empty() == true )
				{
					port[ j + car[ i ] ] = port[ j ] ;
					port[ j + car[ i ] ].insert( i ) ;
				}
			}
			
			if( port[ car[ i ] ].empty() == true )
				port[ car[ i ] ].insert( i ) ;
			
			sum += car[ i ] ;
			
			// find one correct arrangement or quit the loop
			int	largestIndex = ferry ;
			while( largestIndex >= 0 && port[ largestIndex ].empty() == true )
			{
				largestIndex-- ;
			}
			
			if( sum - largestIndex <= ferry )
			{
				result = pair<int,set<int> >( i+1, port[ largestIndex ] ) ;
			}
			else
			{
				break ;
			}
		}
		
		if( runningCase > 1 )
			cout << endl ;
		cout << result.first << endl ;
		for( int i = 0 ; i < result.first ; i++ )
		{
			if( result.second.find( i ) != result.second.end() )
			{
				cout << "port" << endl ;
			}
			else
			{
				cout << "starboard" << endl ;
			}
		}
	}
	
	return 0 ;
}
