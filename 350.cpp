#include <iostream>
using namespace std ;

inline long long int gcd( long long int a , long long int b )
{
/* Here a and b should not be negative. */
	long long int temp ;

	while( a != 0 && b != 0 )
	{
		temp = a % b ;
		a = b ;
		b = temp ;
	}

	return a + b ;
}

int main()
{
	long long int Z , I , M , L ;
	long long int cases = 0 , z_series , gcd_M_Z , length ;

	while( cin >> Z >> I >> M >> L )
	{
		if( Z == 0 && I == 0 && M == 0 && L == 0 )
		{
			break ;
		}

		cases++ ;
		Z = Z % M ;
		I = I % M ;

		if( Z == 1 || Z == 0 )
		{
			cout << "Case " << cases << ": " << M / gcd( I , M ) << endl ;
		}
		else
		{
			M /= gcd( gcd( Z - 1 , M ) , I ) ;
			while( ( gcd_M_Z = gcd( M , Z ) ) != 1 )
			{
				M /= gcd_M_Z ;
			}

			z_series = 1 ;
			length = 1 ;
			while( ( z_series = z_series % M ) != 0 )
			{
				length++ ;
				z_series = z_series * Z + 1 ;
			}

			cout << "Case " << cases << ": " << length << endl ;
		}
	}

	return 0 ;
}
