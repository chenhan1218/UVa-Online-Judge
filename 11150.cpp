#include <iostream>
using namespace std ;

#define MaxN 200

int	emptybottle[ MaxN + 1 ] = { 0 } ;

int main()
{
	int		n = 0 ;
	int		i = 0 ; // loop counter
	
	emptybottle[ 0 ] = 0 ;
	emptybottle[ 1 ] = 0 ;
	emptybottle[ 2 ] = 1 ;
	for( i = 3 ; i <= MaxN ; i++ )
	{
		emptybottle[ i ] = i / 3 + emptybottle[ i / 3 + i % 3 ] ;
	}
	
	while( cin >> n )
	{
		cout << n + emptybottle[ n ] << endl ;
	}
	
	return 0 ;
}

/* a simple version
#include <iostream>
using namespace std ;

int main()
{
	int		n = 0 ;
	int		ans = 0 ;
	
	while( cin >> n )
	{
		ans = n ;

		while( n >= 3 )
		{
			ans += n / 3 ;
			n = n % 3 + n / 3 ;
		}

		if( n == 2 )
		{
			ans += 1 ;
		}

		cout << ans << endl ;
	}
	
	return 0 ;
}
*/

