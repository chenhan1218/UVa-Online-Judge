#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <limits>
using namespace std ;

int stringToLong( const string &a )
{
	return strtol( a.c_str(), NULL, 2 ) ;
}

int main()
{
	const int	MaxN = 8 ;
	long long int	win[ 1<<MaxN ][ 1<<MaxN ] = { 0 } ;
	int		grid[ MaxN ][ MaxN ] = { 0 } ;
	int		t = 0 ;
	
	cin >> t ;
	while( t > 0 )
	{
		t-- ;
		
		int		n = 0 ;
		cin >> n ;
		for( int i = 0 ; i < n ; i++ )
		{
			for( int j = 0 ; j < n ; j++ )
			{
				cin >> grid[ i ][ j ] ;
			}
		}
		
		for( int i = 1 ; i <= n ; i++ )
		{
			string	Alice = string( n-i, '0' ) + string( i, '1' ) ;
			string	Bob = string( n-i, '0' ) + string( i, '1' ) ;
			do
			{
				do
				{
					win[ stringToLong( Alice ) ][ stringToLong( Bob ) ] = INT_MIN ;
					for( int j = 0 ; j < n ; j++ )
					{
						if( Alice[ j ] == '0' )
							continue ;
						
						long long int	tmp = INT_MAX ;
						string	a = Alice ;
						a[ j ] = '0' ;
						for( int k = 0 ; k < n ; k++ )
						{
							if( Bob[ k ] == '0' )
								continue ;
							
							string	b = Bob ;
							b[ k ] = '0' ;
							
							// do the dp here.
							tmp = min( tmp, win[ stringToLong( a ) ][ stringToLong( b ) ] + grid[ j ][ k ] ) ;
						}
						
						win[ stringToLong( Alice ) ][ stringToLong( Bob ) ] = 
							max( win[ stringToLong( Alice ) ][ stringToLong( Bob ) ], tmp ) ;
					}
					
				}while( next_permutation( Bob.begin(), Bob.end() ) == true ) ;
			}while( next_permutation( Alice.begin(), Alice.end() ) == true ) ;
		}
		
		cout << win[ (1<<n)-1 ][ (1<<n)-1 ] << endl ;
	}
	
	return 0 ;
}

/* TLE version
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <limits>
using namespace std ;

int main()
{
	map< string, map<string,long long int> >	win ;
	const int	MaxN = 8 ;
	int		grid[ MaxN ][ MaxN ] = { 0 } ;
	int		t = 0 ;
	
	cin >> t ;
	while( t > 0 )
	{
		t-- ;
		
		int		n = 0 ;
		cin >> n ;
		for( int i = 0 ; i < n ; i++ )
		{
			for( int j = 0 ; j < n ; j++ )
			{
				cin >> grid[ i ][ j ] ;
			}
		}
		
		for( int i = 1 ; i <= n ; i++ )
		{
			string	Alice = string( n-i, '0' ) + string( i, '1' ) ;
			string	Bob = string( n-i, '0' ) + string( i, '1' ) ;
			do
			{
				do
				{
					win[ Alice ][ Bob ] = INT_MIN ;
					for( int j = 0 ; j < n ; j++ )
					{
						if( Alice[ j ] == '0' )
							continue ;
						
						long long int	tmp = INT_MAX ;
						string	a = Alice ;
						a[ j ] = '0' ;
						for( int k = 0 ; k < n ; k++ )
						{
							if( Bob[ k ] == '0' )
								continue ;
							
							string	b = Bob ;
							b[ k ] = '0' ;
							
							// do the dp here.
							tmp = min( tmp, win[ a ][ b ] + grid[ j ][ k ] ) ;
						}
						
						win[ Alice ][ Bob ] = max( win[ Alice ][ Bob ], tmp ) ;
					}
					
				}while( next_permutation( Bob.begin(), Bob.end() ) == true ) ;
			}while( next_permutation( Alice.begin(), Alice.end() ) == true ) ;
		}
		
		cout << win[ string( n, '1' ) ][ string( n, '1' ) ] << endl ;
	}
	
	return 0 ;
}
*/
