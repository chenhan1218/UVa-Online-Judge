#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>
#include <cmath>
#include <string>
using namespace std ;

unsigned int str2int( const string &s )
{
	unsigned int ans = 0 ;
	for( int i = 0 ; i < s.size() ; i++ )
	{
		ans <<= 1;
		if( s[ i ] != '0' )
			ans ++ ;
	}
	return ans ;
}

int main()
{
	const int	MaxN = 8 ;
	int		n = 0 ;
	double	dis[ 1 << (MaxN*2) ] = { 0 } ;
	double	EuDis[ MaxN*2 ][ MaxN*2 ] = { 0 } ;
	
	cout << fixed << setprecision( 2 ) ;
	
	for( int casenum = 1 ; cin >> n && n != 0 ; casenum++ )
	{
		string	name ;
		vector< pair<double,double> >	house( n*2 ) ;
		
		for( int i = 0 ; i < n*2 ; i++ )
		{
			cin >> name >> house[ i ].first >> house[ i ].second ;
		}
		
		// calculate distance between points
		for( int i = 0 ; i < n*2 ; i++ )
		{
			for( int j = 0 ; j < i ; j++ )
			{
				EuDis[ i ][ j ] = sqrt( 
					(house[ i ].first-house[ j ].first)*(house[ i ].first-house[ j ].first) + 
					(house[ i ].second-house[ j ].second)*(house[ i ].second-house[ j ].second) ) ;
				EuDis[ j ][ i ] = EuDis[ i ][ j ] ;
			}
		}
		
		// using dp algorithm
		for( int i = 2 ; i <= n*2 ; i+=2 )
		{
			string	subset = string( 2*n-i, '0' ) + string( i, '1' ) ;
			
			do
			{
				int	first = subset.find( '1' ) ;
				int	current = str2int( subset ) ;
				
				dis[ current ] = 99999999 ;
				for( int second = subset.find( '1', first+1 ) ; second != string::npos ; second = subset.find( '1', second+1 ) )
				{
					string	buffer = subset ;
					buffer[ first ] = '0' ;
					buffer[ second ] = '0' ;
					dis[ current ] = min( dis[ current ], 
						dis[ str2int( buffer ) ] + EuDis[ first ][ second ] ) ;
					//cout << first << "\t" << second << "\t" << EuDis[ first ][ second ] << "\t" << dis[ str2int( buffer ) ] << "\t" << dis[ str2int( buffer ) ] + EuDis[ first ][ second ] << endl ;
				}
				
			} while( next_permutation( subset.begin(), subset.end() ) == true ) ;
		}
		
		cout << "Case " << casenum << ": " << dis[ (1 << (n*2)) - 1 ] << endl ;
	}
	
	return 0 ;
}
