#include <iostream>
#include <iomanip>
using namespace std ;

int
main()
{
	unsigned long long int	integer[ 1501 ] ;
	unsigned long long int	temp ;
	int		a[ 7 ] = { 0 } ;
	int		n = 0 ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cin >> n ;
	for( cases = 1 ; cases <= n ; cases++ )
	{
		for( i = 1 ; i <= 1500 ; i++ )
		{
			cin >> integer[ i ] ;
		}

		// set a[ i ] for each i.
		for( i = 0 ; i <= 6 ; i++ )
		{
			a[ i ] = integer[ 1500 ] % 1500 ;
			integer[ 1500 ] = integer[ 1500 ] / 1500 ;

			if( a[ i ] < 0 || a[ i ] >= 1001 )
			{
				break ;
			}
		}

		if( i <= 6 )
		{
			cout << "This is a smart sequence!" << endl ;
		}
		else
		{
			for( i = 1 ; i < 1500 ; i++ )
			{
				temp = a[ 6 ] ;
				for( j = 5 ; j >= 0 ;j-- )
				{
					temp = temp * i + a[ j ] ;
				}

				if( temp != integer[ i ] )
				{
					break ;
				}
			}

			if( i < 1500 )
			{
				cout << "This is a smart sequence!" << endl ;
			}
			else
			{
				cout << a[ 0 ] ;
				for( i = 1 ; i <= 6 ; i++ )
				{
					cout << " " << a[ i ] ;
				}
				cout << endl ;
			}
		}
	}

	return 0 ;
}

