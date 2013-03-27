#include <iostream>
#include <iomanip>
using namespace std ;

long long int	pow( long long int b, long long int p, long long int m )
{
	long long int	temp = 0 ;
	if( p == 0 )
	{
		return 1 ;
	}
	else if( p == 1 )
	{
		return b % m ;
	}
	else
	{
		temp = pow( b, p / 2, m ) ;
		if( p % 2 == 0 )
		{
			return ( temp * temp ) % m ;
		}
		else
		{
			return ( ( temp * temp ) % m * b ) % m ;
		}
	}
}

int
main()
{
	long long int	b = 0 ;
	long long int	p = 0 ;
	long long int	m = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> b >> p >> m )
	{
		cout << pow( b, p, m ) << endl ;
	}

	return 0 ;
}
