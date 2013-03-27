#include <iostream>
using namespace std ;

#define MaxN 20

long long int gcd( long long int a, long long int b )
{
	if( b == 0 )
		return 0 ;

	while( b != 0 )
	{
		a %= b ;
		swap( a, b ) ;
	}

	return a ;
}

int main()
{
	long long int	inteval[ MaxN ] = { 0 } ;
	long long int	remainder[ MaxN ] = { 0 } ;
	long long int	y[ MaxN ] = { 0 } ;
	long long int	a[ MaxN ] = { 0 } ;
	long long int	b[ MaxN ] = { 0 } ;
	long long int	ans = 0 ;
	long long int	mod = 0 ;
	int		cases = 0 ;
	int		n = 0 ;
	int		i = 0 ;

	while( cin >> n && n != 0 )
	{
		cases++ ;
		for( i = 0 ; i < n ; i++ )
		{
			cin >> y[ i ] >> a[ i ] >> b[ i ] ;
			inteval[ i ] = b[ i ] - a[ i ] ;
			remainder[ i ] = y[ i ] % inteval[ i ] ;
		}

		ans = 0 ;
		mod = 1 ;
		for( i = 0 ; i < n ; i++ )
		{
			if( ( ans - remainder[ i ] ) % gcd( mod, inteval[ i ] ) != 0 )
				break ;

			while( ans % inteval[ i ] != remainder[ i ] )
				ans += mod ;

			mod = mod * inteval[ i ] / gcd( mod, inteval[ i ] ) ;
			ans %= mod ;
		}

		cout << "Case #" << cases << ":" << endl ;
		if( i < n )
		{
			cout << "Unknown bugs detected." << endl ;
		}
		else
		{
			for( i = 0 ; i < n ; i++ )
				while( ans < a[ i ] )
					ans += mod ;

			if( ans >= 10000 )
			{
				cout << "Unknown bugs detected." << endl ;
			}
			else
			{
				cout << "The actual year is " << ans << "." << endl ;
			}
		}
		cout << endl ;
	}

	return 0 ;
}

