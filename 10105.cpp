#include <iostream>
using namespace std ;

int main()
{
	long long int factorial[ 13 ] ;
	factorial[ 0 ] = 1 ;
	factorial[ 1 ] = 1 ;
	for( int i = 2 ; i < 13 ; i++ )
	{
		factorial[ i ] = factorial[ i - 1 ] * i ;
	}

	int n , k , variables;

	long long int answer ;

	while( cin >> n >> k )
	{
		answer = factorial[ n ] ;

		for( int i = 1 ; i <= k ; i++ )
		{
			cin >> variables ;

			if( variables >= 2 )
			{
				answer /= factorial[ variables ] ;
			}
		}

		cout << answer << endl ;
	}

	return 0 ;
}
