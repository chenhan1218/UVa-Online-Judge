#include <iostream>
using namespace std ;

int main()
{
	int N ;
	cin >> N ;

	long long int data , temp_data , compare ;
	long long int power[ 10 ] ;
	power[ 0 ] = 1 ;
	for( int i = 1 ; i <= 9 ; i++ )
	{
		power[ i ] = power[ i - 1 ] * 10 ;
	}

	int iterations ;
	for( int i = 1 ; i <= N ; i++ )
	{
		cin >> data ;

		iterations = 0 ;

		while( 1 )
		{
			int j ;
			for( j = 9 ; j >= 0 ; j-- )
			{
				if( data >= power[ j ] )
				{
					break ;
				}
			}

			compare = 0 ;
			temp_data = data ;
			for( int k = j ; k >= 0 ; k-- )
			{
				compare += ( temp_data / power[ k ] ) * power[ j - k ] ;
				temp_data = temp_data % power[ k ] ;
			}

			if( compare == data )
			{
				break ;
			}
			else
			{
				iterations++ ;
				data += compare ;
			}
		}

		cout << iterations << " " << data << endl ;
	}

	return 0 ;
}
