#include <iostream>
using namespace std ;

int main()
{
	int k , k_square , x , y ,pairs ;

	int k_square_factors[ 1002 ] = { 0 } ;

	while( cin >> k )
	{
		k_square = k * k ;
		pairs = 0 ;

		for( int i = 1 ; i <= k ; i++ )
		{
			if( k_square % i == 0 )
			{
				pairs ++ ;
				k_square_factors[ pairs ] = i ;
			}
		}

		cout << pairs << endl ;

		for( int i = 1 ; ; i++ )
		{
			if( k_square_factors[ i ] > 0 )
			{
				y = k_square_factors[ i ] + k ;
				x = k * y / k_square_factors[ i ] ;
				cout << "1/" << k << " = 1/" << x 
					<< " + 1/" << y << endl ;

				k_square_factors[ i ] = 0 ;
			}
			else
			{
				break ;
			}
		}
	}

	return 0 ;
}
