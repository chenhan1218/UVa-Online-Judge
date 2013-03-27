#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
using namespace std;

long long int h( long long int n )
{
	if( n <= 0 )
		return 0 ;
	
	long long int res = 0 ;
	for( long long int i = 1 ; (n/i)*(n/i)>n ; i++ )
	{
		res += n/i ;
	}
	
	long long int root = 0 ;
	while( root*root <= n )
		root++ ;
	root-- ;
	
	for( long long int i = 1 ; i <= root ; i++ )
	{
		res += ( n/i ) - (n/(root+1)) ;
	}
	
	return res ;
}

/* AC version
long long int h( long long int n )
{
	if( n <= 0 )
		return 0 ;
	
	long long int res = 0 ;
	for( long long int i = 1 ; (n/i)*(n/i)>n ; i++ )
	{
		res += n/i ;
	}
	
	for( long long int i = 1 ; i*i <= n ; i++ )
	{
		res += i * ( ( n/i ) - n/(i+1) ) ;
	}
	
	return res ;
}
*/

int main()
{
	int		t = 0 ;
	long long int n = 0 ;
	
	cin.sync_with_stdio( false ) ;
	cout.sync_with_stdio( false ) ;

	cin >> t ;
	for( int i = 0 ; i < t ; i++ )
	{
		cin >> n ;
		
		cout << h( n ) << endl ;
	}
	
	return 0 ;
}
