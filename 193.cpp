#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MaxN = 100 ;
set<int>	maxSet ;
set<int>	neighbor[ MaxN + 1 ] ;

void dfs( const int n, const set<int> neighbor[], int depth, set<int> current )
{
	if( depth <= n && n - depth + 1 + current.size() > maxSet.size() )
	{
		bool	notBlack = false ;
		for( set<int>::const_iterator iter = neighbor[ depth ].begin() ; 
		iter != neighbor[ depth ].end() ; iter++ )
		{
			if( current.find(*iter) != current.end() )
			{
				notBlack = true ;
				break ;
			}
		}
		
		if( notBlack == false )
		{
			current.insert( depth ) ;
			
			if( current.size() > maxSet.size() )
			{
				maxSet = current ;
			}
			
			dfs( n, neighbor, depth+1, current ) ;
			current.erase( depth ) ;
		}
		
		dfs( n, neighbor, depth+1, current ) ;
	}
}

int main()
{
	int		m = 0 ;
	
	cin >> m ;
	while( m > 0 )
	{
		m-- ;
		
		int		n = 0 ;
		int		k = 0 ;
		
		cin >> n >> k ;
		maxSet.clear() ;
		for( int i = 1 ; i <= n ; i++ )
			neighbor[ i ].clear() ;
		
		for( int i = 0 ; i < k ; i++ )
		{
			int	a = 0 ;
			int	b = 0 ;
			cin >> a >> b ;
			neighbor[ a ].insert( b ) ;
			neighbor[ b ].insert( a ) ;
		}
		
		dfs( n, neighbor, 1, set<int>() ) ;
		cout << maxSet.size() << endl ;
		for( set<int>::const_iterator iter = maxSet.begin() ; 
		iter != maxSet.end() ; iter++ )
		{
			if( iter != maxSet.begin() )
				cout << " " ;
			cout << *iter ;
		}
		cout << endl ;
	}
}
