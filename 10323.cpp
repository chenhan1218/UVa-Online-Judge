#include <iostream>
#include <iomanip>
using namespace std ;

long long int factorial( long long int n )
{
	if( n == 0 )
		return 1 ;
	else
		return n * factorial( n - 1 ) ;
}

int main()
{
	int		n = 0 ;
	int		i = 0 ;

	while( cin >> n )
	{
		if( n < 0 )
		{
			if( n % 2 == 0 )
				cout << "Underflow!" << endl ;
			else
				cout << "Overflow!" << endl ;
			continue ;
		}
		else if( n > 13 )
			cout << "Overflow!" << endl ;
		else if( n < 8 )
			cout << "Underflow!" << endl ;
		else
			cout << factorial( n ) << endl ;
	}

	return 0 ;
}


/* may be a correct but TLE version
#include <iostream>
#include <iomanip>
using namespace std ;

long long int factorial( int n, int &solved )
{
	long long int	temp = 0 ;
	if( n == 0 )
	{
		return 1 ;
	}
	else
	{
		temp = n * factorial( n - 1, solved ) ;
		if( solved == 0 )
		{
			if( temp > 62270208 * 100 )
				solved = 1 ;
		}

		return temp ;
	}
}

int main()
{
	long long int	ans = 0 ;
	int		solved = 0 ;
	int		n = 0 ;
	int		i = 0 ;

	while( cin >> n )
	{
		if( n < 0 )
		{
			if( n % 2 == 0 )
				cout << "Underflow!" << endl ;
			else
				cout << "Overflow!" << endl ;
			continue ;
		}

		solved = 0 ;
		ans = factorial( n, solved ) ;

		if( solved == 0 )
		{
			if( ans < 10000 )
				cout << "Underflow!" << endl ;
			else
				cout << ans << endl ;
		}
		else if( solved > 0 )
			cout << "Overflow!" << endl ;
	}

	return 0 ;
}

*/

