#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

class node
{
	public:
		node() {
			pos = 0 ;
			length = 0 ;
		}
		node( int p, long long int l ) {
			pos = p ;
			length = l ;
		}
		int	pos ;
		long long int length ;
		bool operator<( const node &n ) const {
			return length < n.length ;
		}
		bool operator>( const node &n ) const {
			return length > n.length ;
		}
};

const int MaxN = 100 ;
long long int	dis[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;

int bfs( int n, int x, int y, int k )
{
	priority_queue<node, vector<node>, greater<node> >	q ;
	int		found = 0 ;
	vector<int>	visited( n+1, 0 ) ;
	long long int	ans = 0 ;
	
	q.push( node( x, 0 ) ) ;
	while( q.empty() != true )
	{
		// this point have been visited more than k times
		if( visited[ q.top().pos ] > k )
		{
			// Do not insert the point to the queue again.
		}
		else
		{
			visited[ q.top().pos ]++ ;
			for( int j = 1 ; j <= n ; j++ )
			{
				if( dis[ q.top().pos ][ j ] != INT_MAX )
				{
					q.push( node( j, q.top().length + dis[ q.top().pos ][ j ] ) ) ;
				}
			}
		}
		
		if( q.top().pos == y )
		{
			found++ ;
			ans = q.top().length ;
		}
		
		if( found == k )
			break ;
		
		q.pop() ;
	}
	
	if( found < k )
		return -1 ;
	else
		return ans ;
}

int main()
{
	int		n = 0 ;
	int		m = 0 ;
	int		x = 0 ;
	int		y = 0 ;
	int		k = 0 ;
	
	while( cin >> n >> m )
	{
		if( n == 0 && m == 0 )
			break ;
		
		for( int i = 1 ; i <= n ; i++ )
			fill( dis[ i ]+1, dis[ i ]+n+1, INT_MAX ) ;
		
		cin >> x >> y >> k ;
		for( int i = 0 ; i < m ; i++ )
		{
			int		u = 0, v = 0, l = 0 ;
			cin >> u >> v >> l ;
			dis[ u ][ v ] = l ;
		}
		
		cout << bfs( n, x, y, k ) << endl ;
	}
	
	return 0 ;
}
