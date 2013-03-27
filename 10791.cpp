#include <iostream>
#include <iomanip>
using namespace std ;

#define Max_n 50000

int			previous[ Max_n + 100 ] = { 0 } ;
int			next[ Max_n + 100 ] = { 0 } ;

void initial( long long int n )
{
	long long int	i = 0 ; // loop counter

	previous[ 2 ] = -1 ;
	next[ 2 ] = 3 ;
	previous[ 3 ] = 2 ;
	next[ 3 ] = 5 ;
	for( i = 3 ; i <= n ; i += 2 )
	{
		previous[ i ] = i - 2 ;
		next[ i ] = i + 2 ;
	}
}

void remove( int x )
{
	next[ previous[ x ] ] = next[ x ] ;
	previous[ next[ x ] ] = previous[ x ] ;

	previous[ x ] = 0 ;
	next[ x ] = 0 ;
}

void cal( long long int n )
{
	long long int	numPrimes = 0 ;
	long long int	prime = 0 ;
	long long int	fact = 0 ;
	long long int	mult = 0 ;

	initial( n ) ;

	for( prime = 3 ; prime * prime <= n ; prime = next[ prime ] )
	{
		for( fact = prime ; prime * fact <= n ; fact = next[ fact ] )
		{
			for( mult = prime * fact ; mult <= n ; mult *= prime )
			{
				remove( mult ) ;
			}
		}
	}
}

int
main()
{
	long long int		n = 0 ;
	long long int		factor = 0 ;
	long long int		powOfFactor = 0 ;
	bool	isprime = false ;
	long long int		ans = 0 ;
	int		testcase = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cal( Max_n ) ;

	while( cin >> n && n != 0 )
	{
		testcase ++ ;

		if( n == 1 )
		{
			cout << "Case " << testcase << ": " << 2 << endl ;
			continue ;
		}

		isprime = true ;
		ans = 0 ;
		i = 2 ;
		while( n != 1 && i <= Max_n )
		{
			if( n % i == 0 )
			{
				if( ans != 0 )
				{
					isprime = false ;
				}

				n /= i ;
				powOfFactor = i ;

				while( n % i == 0 )
				{
					n /= i ;
					powOfFactor *= i ;
				}

				ans += powOfFactor ;
			}

			i = next[ i ] ;
		}

		if( n > 1 )
		{
			if( ans != 0 )
			{
				isprime = false ;
			}

			ans += n ;
		}

		if( isprime == true )
		{
			ans += 1 ;
		}

		cout << "Case " << testcase << ": " << ans << endl ;
	}

	return 0 ;
}
