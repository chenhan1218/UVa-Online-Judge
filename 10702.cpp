#include <iostream>
#include <vector>
using namespace std ;

#define MaxC 100
#define MaxE 100

void print( vector< vector<int> > v )
{
	int		i = 0 ;
	int		j = 0 ;
	for( i = 0 ; i < v.size() ; i++ )
	{
		for( j = 0 ; j < v[ i ].size() ; j++ )
		{
			cout << v[ i ][ j ] << "\t" ;
		}
		cout << endl ;
	}
}

vector< vector<int> > matrix_mul( const vector< vector<int> > &a, const vector< vector<int> > &b )
{
	vector< vector<int> > ret( a.size(), vector<int>( b[ 0 ].size() , 0 ) ) ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	for( i = 0 ; i < a.size() ; i++ )
	{
		for( j = 0 ; j < b[ 0 ].size() ; j++ )
		{
			for( k = 0 ; k < a[ 0 ].size() ; k++ )
			{
				ret[ i ][ j ] = max( ret[ i ][ j ], a[ i ][ k ] + b[ k ][ j ] ) ;
			}
		}
	}
	
	return ret ;
}

vector< vector<int> > matrix_pow( const vector< vector<int> > &v, long long int p )
{
	if( p == 0 )
	{
		return vector< vector<int> >( v.size(), vector<int>( v.size(), 0 ) ) ;
	}
	else if( p == 1 )
	{
		return v ;
	}
	else
	{
		vector< vector<int> > ret ;
		
		ret = matrix_pow( v, p/2 ) ;
		ret = matrix_mul( ret, ret ) ;
		if( p%2 == 1 )
		{
			ret = matrix_mul( ret, v ) ;
		}
		
		return ret ;
	}
}

int main()
{
	int		c = 0 ;
	int		s = 0 ;
	int		e = 0 ;
	int		t = 0 ;
	vector< vector<int> >	profit ;
	int		end[ MaxE ] = { 0 } ;
	int		maxProfit = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	while( cin >> c >> s >> e >> t )
	{
		if( c == 0 && s == 0 && e == 0 && t == 0 )
			break ;
		
		profit = vector< vector<int> >( c, vector<int>( c, 0 ) ) ;
		for( i = 0 ; i < c ; i++ )
		{
			for( j = 0 ; j < c ; j++ )
			{
				cin >> profit[ i ][ j ] ;
			}
		}
		
		for( i = 0 ; i < e ; i++ )
			cin >> end[ i ] ;
		
		profit = matrix_pow( profit, t ) ;
		
		maxProfit = 0 ;
		for( i = 0 ; i < e ; i++ )
		{
			maxProfit = max( maxProfit, profit[ s - 1 ][ end[ i ] - 1 ] ) ;
		}
		
		cout << maxProfit << endl ;
	}
	
	return 0 ;
}
