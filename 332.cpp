#include <iostream>
#include <cstdlib>
#include <string>
using namespace std ;

long long int mypow( long long int n, long long int p )
{
	long long int	temp = 0 ;
	if( p == 0 )
	{
		return 1 ;
	}
	else if( p == 1 )
	{
		return n ;
	}
	else
	{
		temp = mypow( n, p/2 ) ;
		temp *= temp ;
		if( p % 2 == 1 )
		{
			temp *= n ;
		}
		
		return temp ;
	}
}

long long int gcd( long long int a, long long int b )
{
	while( b != 0 )
	{
		a %= b ;
		swap( a, b ) ;
	}
	return a ;
}

int main()
{
	int		j = 0 ;
	int		k = 0 ;
	int		iBuffer = 0 ;
	char	cBuffer = 0 ;
	string	str ;
	long long int	d = 0 ;
	long long int	denominator = 0 ;
	long long int	numerator = 0 ;
	long long int	temp = 0 ;
	int		cases = 0 ;
	int		i = 0 ;
	
	while( cin >> j >> iBuffer >> cBuffer >> str )
	{
		cases++ ;
		
		k = str.length() - j ;
		d = atoi( str.c_str() ) ;
		
		if( j == 0 )
		{
			numerator = d ;
			denominator = mypow( 10, k ) ;
		}
		else
		{
			numerator = d - d / mypow( 10, j ) ;
			denominator = mypow( 10, k + j ) - mypow( 10, k ) ;
		}

		temp = gcd( numerator, denominator ) ;
		numerator /= temp ;
		denominator /= temp ;
			
		cout << "Case " << cases << ": " << numerator << "/" << denominator << endl ;
	}
	
	return 0 ;
}
