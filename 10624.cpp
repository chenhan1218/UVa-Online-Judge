// ac because of little number of testcase  ( 1<=t<=15)
#include <iostream>
#include <string>
using namespace std ;

string	ans ;
int		n = 0 ;
int		m = 0 ;

int mymod( const string &input, int m )
{
	int		remainder = 0 ;
	int		i = 0 ;
	for( i = 0 ; i < input.size() ; i++ )
		remainder = (remainder*10 + input[ i ] - '0' )%m ;
	return remainder ;
}


void dfs( int index, const string &value )
{
	int		i = 0 ;
	int		j = 0 ;
	
	if( index == m + 1 ) // stop recursive here
	{
		ans = value ;
	}
	else if( index == 1 )
	{
		for( i = 1 ; i < 10 && ans == "" ; i++ )
		{
			dfs( index+1, value + (char)('0' + i) ) ;
		}
	}
	else
	{
		if( index >= n )
		{
			if( (mymod( value, index )*10)%index == 0 )
			{
				i = 0 ;
			}
			else
			{
				i = index - (mymod( value, index )*10)%index ;
			}
			
			for( ; i < 10 && ans == "" ; i += index )
			{
				dfs( index+1, value + (char)('0' + i) ) ;
			}
		}
		else
		{
			for( i = 0 ; i < 10 && ans == "" ; i++ )
			{
				dfs( index+1, value + (char)('0' + i) ) ;
			}
		}
	}
}

int main()
{
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;

	cin >> casenum ;
	for( runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		cin >> n >> m ;

		ans = "" ;
		dfs( 1, "" ) ;
		cout << "Case " << runningCase << ": " ;
		if( ans == "" )
		{
			cout << -1 << endl ;
		}
		else
		{
			cout << ans << endl ;
		}
	}
	
	return 0 ;
}

/* precalculated version, TLE, need about 10s
#include <iostream>
#include <vector>
#include <string>
using namespace std ;

#define MaxN 28
#define MaxM 29

string	ans[ MaxN + 1 ][ MaxM + 1 ] ;
int		n = 0 ;
int		m = 0 ;

int mymod( const string &input, int m )
{
	int		remainder = 0 ;
	int		i = 0 ;
	for( i = 0 ; i < input.size() ; i++ )
		remainder = (remainder*10 + input[ i ] - '0' )%m ;
	return remainder ;
}


void dfs( int index, const string &value )
{
	int		i = 0 ;
	int		j = 0 ;
	
	if( ans[ n ][ index - 1 ] == "" )
	{
		ans[ n ][ index - 1 ] = value ;
	}
	
	if( index >= MaxM + 1 ) // stop recursive here
	{
		return ;
	}
	else if( index == 1 )
	{
		for( i = 1 ; i < 10 && ans[ n ][ MaxM ] == "" ; i++ )
		{
			dfs( index+1, value + (char)('0' + i) ) ;
		}
	}
	else
	{
		if( index >= n )
		{
			if( (mymod( value, index )*10)%index == 0 )
			{
				i = 0 ;
			}
			else
			{
				i = index - (mymod( value, index )*10)%index ;
			}
			
			for( ; i < 10 && ans[ n ][ MaxM ] == "" ; i += index )
			{
				dfs( index+1, value + (char)('0' + i) ) ;
			}
		}
		else
		{
			for( i = 0 ; i < 10 && ans[ n ][ MaxM ] == "" ; i++ )
			{
				dfs( index+1, value + (char)('0' + i) ) ;
			}
		}
	}
}

int main()
{
	int		casenum = 0 ;
	int		runningCase = 0 ;
	vector<int>	v ;
	int		i = 0 ;
	
	for( n = 1 ; n <= MaxN ; n++ )
	{
		v = vector<int>( MaxM + 1, 0 ) ;
		dfs( 1, "" ) ;
		
		for( i = 1 ; i <= MaxM ; i++ )
			cout << n << "\t" << i << "\t" << ans[ n ][ i ] << endl ;
	}

	cin >> casenum ;
	for( runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		cin >> n >> m ;

		cout << "Case " << runningCase << ": " ;
		if( ans[ n ][ m ] == "" )
		{
			cout << -1 << endl ;
		}
		else
		{
			cout << ans[ n ][ m ] << endl ;
		}
	}
	
	return 0 ;
}
*/
