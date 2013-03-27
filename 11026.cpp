#include <iostream>
using namespace std ;

int main()
{
	int N , M , data , answer ;

	while( cin >> N >> M )
	{
		if( N == 0 && M == 0 )
		{
			break ;
		}

		long long int *coefficient = new long long int [ N ] ;

		cin >> data ;

		coefficient[ 0 ] = -1 * data ;

		for( int i = 2 ; i <= N ; i++ )
		{
			cin >> data ;

			data = data * -1  ;

			coefficient[ i - 1 ] = ( coefficient[ i - 2 ] + data ) % M ;

			for( int j = i - 2 ; j >= 1 ; j-- )
			{
				coefficient[ j ] = ( coefficient[ j - 1 ] + data * coefficient[ j ] ) % M ;
			}

			coefficient[ 0 ] = ( coefficient[ 0 ] * data ) % M ;
		}

		for( int i = N - 1 ; i >= 0 ; i = i - 2 )
		{
			coefficient[ i ] *= -1 ;
		}

		for( int i = 0 ; i <= N - 1 ; i++ )
		{
			if( coefficient[ i ] < 0 )
			{
				coefficient[ i ] += M ;
			}
		}

		answer = coefficient[ 0 ] ;

		for( int i = 1 ; i <= N - 1 ; i++ )
		{
			if( answer < coefficient[ i ] )
			{
				answer = coefficient[ i ] ;
			}
		}

		cout << answer << endl ;
	}

	return 0 ;
}
