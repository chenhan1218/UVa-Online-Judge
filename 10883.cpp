#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

#define MaxN 50000

int main()
{
	int		n = 0 ;
	long double logFactorial[ MaxN ] = { 0 } ;
	long double	data[ MaxN ] = { 0 } ;
	long double	ans = 0 ;
	int		t = 0 ;
	int		cases = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	for( i = 1 ; i < MaxN ; i++ )
	{
		logFactorial[ i ] = logFactorial[ i - 1 ] + log( i ) / log( 2 ) ;
	}
	
	cin >> t ;
	for( cases = 1 ; cases <= t ; cases++ )
	{
		cin >> n ;
		for( i = 0 ; i < n ; i++ )
			cin >> data[ i ] ;
		
		ans = 0 ;
		for( i = 0 ; i <= n - 1 ; i++ )
		{
			ans += data[ i ] * pow( (long double)2.0, 
			logFactorial[ n-1 ] - logFactorial[ i ] - logFactorial[ n-1-i ] - (n-1) ) ;
		}
		
		cout << "Case #" << cases << ": " 
			<< fixed << setprecision( 3 ) << ans << endl ;
	}
	
	return 0 ;
}

/* Memory is not enough
#include <iostream>
#include <iomanip>
using namespace std ;

#define MaxN 50000

long double c[ MaxN ][ MaxN ] = { 0 } ;

int main()
{
	int		n = 0 ;
	long double	data[ MaxN ] = { 0 } ;
	long double	ans = 0 ;
	int		t = 0 ;
	int		cases = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	c[ 0 ][ 0 ] = 1 ;
	for( i = 1 ; i < MaxN ; i++ )
	{
		c[ i ][ 0 ] = c[ i - 1 ][ 0 ] / 2 ;
		for( j = 1 ; j < i ; j++ )
		{
			c[ i ][ j ] = ( c[ i - 1 ][ j - 1 ] + c[ i - 1 ][ j ] ) / 2 ;
		}
		c[ i ][ i ] = c[ i - 1 ][ i - 1 ] / 2 ;
	}
	
	cin >> t ;
	for( cases = 1 ; cases <= t ; cases++ )
	{
		cin >> n ;
		for( i = 0 ; i < n ; i++ )
			cin >> data[ i ] ;
		
		ans = 0 ;
		for( i = 0 ; i <= n - 1 ; i++ )
		{
			ans += data[ i ] * c[ n - 1 ][ i ] ;
		}
		
		cout << "Case #" << cases << ": " 
			<< fixed << setprecision( 3 ) << ans << endl ;
	}
	
	return 0 ;
}
*/

