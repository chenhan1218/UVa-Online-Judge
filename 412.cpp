#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

#define MaxN 50

int		data[ MaxN ] = { 0 } ;

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
	int		n = 0 ;
	double	coprime = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	while( cin >> n && n != 0 )
	{
		for( i = 0 ; i < n ; i++ )
			cin >> data[ i ] ;
		
		coprime = 0 ;
		for( i = 0 ; i < n ; i++ )
		{
			for( j = 0 ; j < i ; j++ )
			{
				if( gcd( data[ i ], data[ j ] ) == 1 )
					coprime++ ;
			}
		}
		
		if( coprime == 0 )
			cout << "No estimate for this data set." << endl ;
		else
			cout << setprecision( 6 ) << fixed
			<< sqrt( ( n * ( n - 1 ) / 2 ) / coprime * 6 ) << endl ;
	}
	
	return 0 ;
}
