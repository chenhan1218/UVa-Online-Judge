#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std ;

void dfs( int node, int n, set<int>	neighbor[], int dis[], int depth, int &length, int &finish )
{
	if( depth > dis[ node ] )
	{
		dis[ node ] = depth ;
		
		for( set<int>::const_iterator iter = neighbor[ node ].begin() ; 
		iter != neighbor[ node ].end() ; ++iter )
		{
			dfs( *iter, n, neighbor, dis, depth+1, length, finish ) ;
		}
	}
}

int main()
{
	const int	MaxN = 100 ;
	int		n = 0 ;
	int		runningCase = 0 ;
	
	while( cin >> n && n != 0 )
	{
		runningCase++ ;
		
		int		s = 0 ;
		int		p = 0 ;
		int		q = 0 ;
		int		length = 0 ;
		int		finish = 0 ;
		set<int>	neighbor[ MaxN + 1 ] ;
		int		dis[ MaxN + 1 ] = { 0 } ;
		
		cin >> s ;
		while( cin >> p >> q )
		{
			if( p == 0 && q == 0 )
				break ;
			
			neighbor[ p ].insert( q ) ;
		}
		
		fill( dis, dis+n+1, -1 ) ;
		dfs( s, n, neighbor, dis, 0, length, finish ) ;
		finish = max_element( dis+1, dis+n+1 ) - dis ;
		length = dis[ finish ] ;
		
		cout << "Case " << runningCase << ": The longest path from " << s << " has length " 
		<< length << ", finishing at " << finish << "." << endl ;
		cout << endl ;
	}
	
	return 0 ;
}
