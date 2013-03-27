#include <iostream>
#include <iomanip>
using namespace std ;

#define MaxN 24

long long int findgcd( long long int a, long long int b )
{
	while( b != 0 )
	{
		a %= b ;
		swap( a, b ) ;
	}

	return a ;
}

class fraction
{
	friend ostream& operator<<(ostream& os, const fraction& x) {
		if( x.deno == 1 )	os << x.numer ;
		else	os << x.numer << "/" << x.deno ;
		return os;
	}

	public:	
		long long int	deno ;
		long long int	numer ;

	fraction() {
		numer = 0 ;
		deno = 1 ;
	}

	fraction& operator=( int x ) {
		numer = x ;
		deno = 1 ;

		return *this ;
	}

	fraction& operator+=(const fraction& x ) {
		long long int gcd = 0 ;
		gcd = findgcd( deno, x.deno ) ;
		numer = numer * ( x.deno / gcd )  + x.numer * ( deno / gcd ) ;
		deno *= x.deno / gcd ;

		gcd = findgcd( deno, numer ) ;
		numer /= gcd ;
		deno /= gcd ;
		return *this ;
	}

	fraction& operator/=(int x) {
		long long int gcd = 0 ;
		gcd = findgcd( numer, x ) ;
		numer /= gcd ;
		x /= gcd ;
		deno *= x ;

		return *this ;
	}
};

int main()
{
	fraction	f[ MaxN * 6 + 1 ] ;
	fraction	ans ;
	int		n = 0 ;
	int		x = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	while( cin >> n >> x )
	{
		if( n == 0 && x == 0 )
			break ;

		// at the begin
		f[ 0 ] = 1 ;
		for( i = 1 ; i <= n * 6 ; i++ )
			f[ i ] = 0 ;


		for( i = 1 ; i <= n ; i++ )
		{
			for( j = i * 6 ; j >= i ; j-- )
			{
				f[ j ] = 0 ;
				for( k = 1 ; k <= 6 && j - k >= 0 ; k++ )
					f[ j ] += f[ j - k ] ;
				f[ j ] /= 6 ;
			}

			for( j = 0 ; j < i ; j++  )
				f[ j ] = 0 ;
		}

		ans = 0 ;
		for( i = x ; i <= n * 6 ; i++ )
			ans += f[ i ] ;

		cout << ans << endl ;
	}

	return 0 ;
}
