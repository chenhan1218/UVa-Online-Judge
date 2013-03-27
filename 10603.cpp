#include <iostream>
#include <algorithm>
#include <climits>
using namespace std ;

const int	MaxA = 200 ;
const int	MaxB = 200 ;
const int	MaxD = 200 ;

int 	visited[ MaxA + 1 ][ MaxB + 1 ] = { 0 } ;
int		jugs[ MaxD + 1 ] = { 0 } ;

int		a = 0 ;
int		b = 0 ;
int		c = 0 ;

void pour( int &x, int &y, int MaxY, int &water )
{
	if( x >= MaxY - y )
	{
		water = MaxY - y ;
	}
	else
	{
		water = x ;
	}
	
	x -= water ;
	y += water ;
}

void dfs( int p, int q, int r, int water )
{
	int		tp = 0 ;
	int		tq = 0 ;
	int		tr = 0 ;
	int		tw = 0 ;
	
	if( visited[ p ][ q ] > water )
	{
		visited[ p ][ q ] = water ;
		jugs[ p ] = min( jugs[ p ], water ) ;
		jugs[ q ] = min( jugs[ q ], water ) ;
		jugs[ r ] = min( jugs[ r ], water ) ;
		
		tp = p ;
		tq = q ;
		tr = r ;
		pour( tp, tq, b, tw ) ;
		dfs( tp, tq, tr, water+tw ) ;
		
		tp = p ;
		tq = q ;
		tr = r ;
		pour( tp, tr, c, tw ) ;
		dfs( tp, tq, tr, water+tw ) ;
		
		tp = p ;
		tq = q ;
		tr = r ;
		pour( tq, tp, a, tw ) ;
		dfs( tp, tq, tr, water+tw ) ;
		
		tp = p ;
		tq = q ;
		tr = r ;
		pour( tq, tr, c, tw ) ;
		dfs( tp, tq, tr, water+tw ) ;
		
		tp = p ;
		tq = q ;
		tr = r ;
		pour( tr, tp, a, tw ) ;
		dfs( tp, tq, tr, water+tw ) ;
		
		tp = p ;
		tq = q ;
		tr = r ;
		pour( tr, tq, b, tw ) ;
		dfs( tp, tq, tr, water+tw ) ;
	}
}

int main()
{
	int		d = 0 ;
	int		closest = 0 ;
	int		casenum ;
	int		i = 0 ;
	int		j = 0 ;
	
	cin >> casenum ;
	
	for( i = 1 ; i <= casenum ; i++ )
	{
		cin >> a >> b >> c >> d ;
		
		fill( jugs, jugs + d + 1, INT_MAX ) ;
		for( j = 0 ; j <= a ; j++ )
			fill( visited[ j ], visited[ j ] + b + 1, INT_MAX ) ;
		dfs( 0, 0, c, 0 ) ;
		
		closest = d ;
		while( jugs[ closest ] == INT_MAX )
			closest-- ;
		
		cout << jugs[ closest ] << " " << closest << endl ;
	}
	
	return 0 ;
}
