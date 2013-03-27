#include <iostream>
using namespace::std ;

int main()
{
	int N ;

	int array[ 1001 ] = { 0 } ;
	long long int data ;

	long long int answer ;

	int first , last , dealing ;

	while( cin >> N )
	{
		answer = 0 ;

		if( N >= 1 )
		{
			cin >> data ;
			array[ 1 ] = data ;
		}
		for( int i = 2 ; i <= N ; i++ )
		{
			cin >> data ;
			array[ i ] = data ;

			if( array[ 1 ] > data )
			{
				first = 0 ;
			}
			else
			{
				first = 1 ;
			}

			if( array[ i - 1 ] > data )
			{
				last = i - 1 ;

				while( last - first > 1 )
				{
					dealing = ( first + last ) / 2 ;

					if( array[ dealing ] > data )
					{
						last = dealing ;
					}
					else
					{
						first = dealing ;
					}
				}

				for( int j = i ; j > first + 1 ; j-- )
				{
					array[ j ] = array[ j - 1 ] ;
				}

				array[ first + 1 ] = data ;

				answer += i - first - 1 ;
			}
		}
		cout << "Minimum exchange operations : " << answer << endl ;
	}



	return 0 ;
}
