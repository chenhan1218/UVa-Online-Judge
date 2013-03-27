#include <iostream>
#include <vector>
using namespace std ;

vector<int>	visited ;
vector<int>	x ;
vector<int>	y ;
int		shortestLen = 0 ;
int		k = 0 ;

void dfs( int len )
{
	int		i = 0 ;
	int		l = 0 ;
	
	if( visited.size() == k + 1 ) // all points are visited
	{
		shortestLen = min( shortestLen, len + abs( x[ 0 ] - x[ visited.back() ] ) + abs( y[ 0 ] - y[ visited.back() ] ) ) ;
		return ;
	}
	
	for( i = 1 ; i <= k ; i++ )
	{
		if( find( visited.begin(), visited.end(), i ) == visited.end() ) // not visited yet
		{
			l = len + abs( x[ i ] - x[ visited.back() ] ) + abs( y[ i ] - y[ visited.back() ] ) ;
			visited.push_back( i ) ;
			dfs( l ) ;
			visited.pop_back() ;
		}
	}
}

int main()
{
	int		m = 0 ;
	int		n = 0 ;
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;
	
	x.assign( 11, 0 ) ;
	y.assign( 11, 0 ) ;
	
	cin >> casenum ;
	for( runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		cin >> m >> n ;
		cin >> x[ 0 ] >> y[ 0 ] ;
		cin >> k ;
		for( i = 1 ; i <= k ; i++ )
			cin >> x[ i ] >> y[ i ] ;
		
		visited.assign( 1, 0 ) ;
		shortestLen = 999999 ;
		dfs( 0 ) ;
		
		cout << "The shortest path has length " << shortestLen << endl ;
	}
	
	return 0 ;
}
