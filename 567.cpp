#include <iostream>
#include <set>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std ;

int main()
{
	const int	NODE = 20 ;
	int		num = 0 ;
	int		testset = 0 ;
	while( cin >> num )
	{
		testset++ ;
		
		set<int>	neighbors[ NODE + 1 ] ;
		int			dist[ NODE + 1 ][ NODE + 1 ] = { 0 } ;
		int			testcase = 0 ;
		
		// initialize of dist array
		for( int i = 1 ; i <= NODE ; i++ )
		{
			fill( dist[ i ] + 1, dist[ i ] + NODE + 1, -1 ) ;
		}
		
		// read in the configuration of the graph
		for( int i = 1 ; i < NODE ; i++ )
		{
			int		idx = 0 ;
			
			// we read the number of the neighbors in the begin of the program.
			// so only read the number when i is not equal to 1
			if( i != 1 )
			{
				cin >> num ;
			}
			
			for( int j = 0 ; j < num ; j++ )
			{
				cin >> idx ;
				neighbors[ i ].insert( idx ) ;
				neighbors[ idx ].insert( i ) ;
			}
		}
		
		// BFS
		for( int i = 1 ; i <= NODE ; i++ )
		{
			queue< pair<int,int> >	q ;
			q.push( pair<int,int>(i,0) ) ;
			while( q.size() > 0 )
			{
				int		point = q.front().first ;
				int		d = q.front().second ;
				if( dist[ i ][ point ] == -1 )
				{
					dist[ i ][ point ] = d ;
					//cout << i << "\t" << point << "\t" << d << endl ;
					
					for( set<int>::const_iterator iter = neighbors[ point ].begin() ; iter != neighbors[ point ].end() ; iter++ )
					{
						q.push( pair<int,int>(*iter,d+1) ) ;
					}
				}
				
				q.pop() ;
			}
			
		}
		
		// run for each test case and output the result
		cin >> testcase ;
		cout << "Test Set #" << testset << endl ;
		for( int i = 0 ; i < testcase ; i++ )
		{
			int		a = 0 ;
			int		b = 0 ;
			cin >> a >> b ;
			cout << setw(2) << a << " to " << setw(2) << b << ":" << setw(2) << dist[ a ][ b ] << endl ;
		}
		//Following all result lines of each input set, your program should print a single blank line. 
		cout << endl ;
	}
	
	return 0 ;
}
