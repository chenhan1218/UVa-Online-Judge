#include <iostream>
using namespace std ;

int main()
{
	int n ;
	int input[ 3000 ] ;

	int first , second , dealing , jolly ;

	while( cin >> n )
	{
		jolly = 1 ;
		for( int i = 1 ; i <= n - 1 ; i++ )
		{
			input[ i ] = 0 ;
		}

		if( n >= 1 )
		{
			cin >> first ;
		}
		int i ;
		for( i = 2 ; i <= n ; i++ )
		{
			cin >> second ;
			if( jolly == 1 )
			{
				dealing = second - first ;

				if( dealing >= n )
				{
					jolly = 0 ;
				}
				else if( dealing > 0 )
				{
					if( input[ dealing ] >= 1 )
					{
						jolly = 0 ;
					}
					else
					{
						input[ dealing ] = 1 ;
					}
				}
				else if( dealing <= ( (-1) * n ) )
				{
					jolly = 0 ;
				}
				else if( dealing < 0 )
				{
					dealing *= -1 ;

					if( input[ dealing ] >= 1 )
					{
						jolly = 0 ;
					}
					else
					{
						input[ dealing ] = 1 ;
					}
				}
				else
				{
					jolly = 0 ;
				}

				first = second ;
			}
		}

		if( jolly == 1 )
		{
			cout << "Jolly" << endl ;
		}
		else
		{
			cout << "Not jolly" << endl ;
		}
	}

	return 0 ;
}
