// C(n/2-1,0)*0.5^(n/2) + C(n/2-1+i,i)*0.5^(n/2+i) ....C(n-3,n/2-2)*0.5^(n-2)

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

#define MaxN 100000

int	main()
{
	int		t = 0 ;
	int		n = 0 ;
	long double	ans[ MaxN + 1 ] = { 0 } ;
	long double	add = 0 ;
	long double	sub = 0 ;
	int		i = 0 ;

	ans[ 4 ] = 0.5 ;

	// ans[ n ] = ans[ n - 2 ] + ( C(n-4,n/2-2)*0.5^(n-3) - C(n-3,n/2-2)*0.5^(n-2) ) * 2
	add = 1.0 ;
	sub = 1.0/2 ;
	for( n = 6 ; n <= MaxN ; n += 2 )
	{
		add = add * (n-4) * (n-5) / (n/2-2) / (n/2-2) / 4.0 ;
		sub = sub * (n-3) * (n-4) / (n/2-2) / (n/2-1) / 4.0 ;
		ans[ n ] = ans[ n - 2 ] + add - sub ;
	}

	cin >> t ;
	while( t > 0 )
	{
		t-- ;

		cin >> n ;

		cout << setprecision( 4 ) << fixed << ans[ n ] << endl ;
	}

	return 0 ;
}

/* double is not enough
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

#define MaxN 10000

int	main()
{
	int		t = 0 ;
	int		n = 0 ;
	long double	ans = 0 ;
	long double	temp = 0 ;
	int		i = 0 ;

	cin >> t ;
	while( t > 0 )
	{
		t-- ;

		cin >> n ;

		if( n == 2 )
		{
			ans = 0 ;
		}
		else
		{
			temp = pow( (long double)0.5, n/2 ) ;
			ans = temp ;
			for( i = 1 ; i <= n/2 - 2 ; i++ )
			{
				temp *= (long double)( n/2-1 + i ) / i / 2 ;
				ans += temp ;
			}

			ans *= 2 ;
		}

		cout << setprecision( 4 ) << fixed << ans << endl ;
	}

	return 0 ;
}
*/

