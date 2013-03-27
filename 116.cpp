#include <iostream>
#include <vector>
using namespace std ;

#define MaxR 10 
#define MaxC 100

vector<int> path[ MaxR + 1 ][ MaxC + 1 ] ;
int		cost[ MaxR + 1 ][ MaxC + 1 ] = { 0 } ;
int		integer[ MaxR + 1 ][ MaxC + 1 ] = { 0 } ;

int after( int r, int i )
{
	return (i%r) + 1 ;
}

int	pre( int r, int i )
{
	if( i == 1 )
		return r ;
	else
		return i - 1 ;
}

void myprint( vector<int> &v )
{
	int	i = 0 ;
	for( i = 0 ; i < v.size() ; i++ )
		cout << "	" << v[ i ] ;
	cout << endl ;
}

int main()
{
	int		r = 0 ;
	int		c = 0 ;
	int		goal = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	while( cin >> r >> c )
	{
		for( i = 1 ; i <= r ; i++ )
		{
			for( j = 1 ; j <= c ; j++ )
			{
				cin >> integer[ i ][ j ] ;
			}
		}
		
		for( i = 1 ; i <= r ; i++ )
		{
			cost[ i ][ 1 ] = integer[ i ][ 1 ] ;
			path[ i ][ 1 ] = vector<int>( 1, i ) ;
		}
		
		for( j = 2 ; j <= c ; j++ )
		{
			for( i = 1 ; i <= r ; i++ )
			{
				// dynamic programming
				cost[ i ][ j ] = min( min( cost[ after(r,i) ][ j - 1 ], cost[ i ][ j - 1 ] ), cost[ pre(r,i) ][ j - 1 ] ) ;
				path[ i ][ j ].clear() ;
				
				if( cost[ after(r,i) ][ j - 1 ] == cost[ i ][ j ] )
				{
					if( path[ i ][ j ].empty() == true || path[ after(r,i) ][ j - 1 ] < path[ i ][ j ] )
						path[ i ][ j ] = path[ after(r,i) ][ j - 1 ] ;
				}
				if( cost[ i ][ j - 1 ] == cost[ i ][ j ] )
				{
					if( path[ i ][ j ].empty() == true || path[ i ][ j - 1 ] < path[ i ][ j ] )
						path[ i ][ j ] = path[ i ][ j - 1 ] ;
				}
				if( cost[ pre(r,i) ][ j - 1 ] == cost[ i ][ j ] )
				{
					if( path[ i ][ j ].empty() == true || path[ pre(r,i) ][ j - 1 ] < path[ i ][ j ] )
						path[ i ][ j ] = path[ pre(r,i) ][ j - 1 ] ;
				}
				
				// add current node to the cost and path
				cost[ i ][ j ] += integer[ i ][ j ] ;
				path[ i ][ j ].push_back( i ) ;
			}
		}
		
		// find the goal of the path
		goal = 1 ;
		for( i = 2 ; i <= r ; i++ )
		{
			if( cost[ i ][ c ] < cost[ goal ][ c ] )
			{
				goal = i ;
			}
			else if( cost[ i ][ c ] == cost[ goal ][ c ] && path[ i ][ c ] < path[ goal ][ c ] )
			{
				goal = i ;
			}
		}
		
		for( i = 0 ; i < path[ goal ][ c ].size() ; i++ )
		{
			if( i == 0 )
			{
				cout << path[ goal ][ c ][ 0 ] ;
			}
			else
			{
				cout << " " << path[ goal ][ c ][ i ] ;
			}
		}
		cout << endl ;
		cout << cost[ goal ][ c ] << endl ;
	}
	
	return 0 ;
}
