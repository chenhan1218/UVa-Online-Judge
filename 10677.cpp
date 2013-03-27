#include <iostream>
using namespace std ;

int main()
{
	int n, B1, B2, r1, r2;
	int i, j ;
	int a[ 4 ] ;
	long long power_B1[ 4 ], power_B2[ 4 ] ;
	power_B1[ 0 ] = 1 ;
	power_B2[ 0 ] = 1 ;
	long long number_Base_B2 ;
	
	cin >> n ;
	
	for( i = 1 ; i <= n ; i++ )
	{
		cin >> B1 >> B2 >> r1 >> r2 ;
		power_B1[ 1 ] = B1 ;
		power_B1[ 2 ] = B1 * B1 ;
		power_B1[ 3 ] = power_B1[ 2 ] * B1 ;
		power_B2[ 1 ] = B2 ;
		power_B2[ 2 ] = B2 * B2 ;
		power_B2[ 3 ] = power_B2[ 2 ] * B2 ;
		
		a[ 3 ] = r2 / power_B1[ 3 ] ;
		a[ 2 ] = r2 / power_B1[ 2 ] - a[ 3 ] * power_B1[ 1 ] ;
		a[ 1 ] = r2 / B1 - a[ 3 ] * power_B1[ 2 ] - a[ 2 ] * power_B1[ 1 ] ;
		a[ 0 ] = r2 % B1 ;

		number_Base_B2 = a[ 3 ] * power_B2[ 3 ] + a[ 2 ] * power_B2[ 2 ]
			+ a[ 1 ] * power_B2[ 1 ] + a[ 0 ] * power_B2[ 0 ] ;
		
		for( j = r2 ; j >= r1 ; j-- )
		{
			if( number_Base_B2 % j == 0 )
			{
				break ;
			}
			
			if( j % power_B1[ 3 ] == 0 )
			{
				number_Base_B2 -= power_B2[ 3 ] - ( B1 - 1 ) * ( power_B2[ 2 ] + power_B2[ 1 ] + power_B2[ 0 ] ) ;
			}
			else if( j % power_B1[ 2 ] == 0 )
			{
				number_Base_B2 -= power_B2[ 2 ] - ( B1 - 1 ) * ( power_B2[ 1 ] + power_B2[ 0 ] ) ;
			}
			else if( j % B1 == 0 )
			{
				number_Base_B2 -= power_B2[ 1 ] - ( B1 - 1 ) * ( power_B2[ 0 ] ) ;
			}
			else
			{
				number_Base_B2 -= 1 ;
			}
		}
		
		if( j < r1 )
		{
			cout << "Non-existent." << endl ;
		}
		else
		{
			cout << j << endl ;
		}
	}

	return 0 ;
}
