#include <iostream>
using namespace std ;

int main()
{
	int N , last_length ;
	char cards[ 52 ][ 21 ] ;
	char spelt[ 52 ][ 21 ] ;
	int length_spelt[ 52 ] ;

	char **order = new char *[ 52 ] ;

	while( cin >> N )
	{
		if( N == 0 )
		{
			break ;
		}

		last_length = 0 ;

		for( int i = 0 ; i < N ; i++ )
		{
			order[ i ] = NULL ;
			cin >> cards[ i ] >> spelt[ i ] ;

			length_spelt[ i ] = 1 ;

			while( spelt[ i ][ length_spelt[ i ] ] != '\0' )
			{
				( length_spelt[ i ] )++ ;
			}
		}

		for( int i = 0 ; i < N ; i++ )
		{
			length_spelt[ i ] = length_spelt[ i ] % ( N - i ) ;
			if( length_spelt[ i ] == 0 )
			{
				length_spelt[ i ] = N - i ;
			}

			for( int j = 1 ; j <= length_spelt[ i ] ; j++ )
			{
				last_length = ( last_length + 1 ) % N ;
				while( order[ last_length ] != NULL )
				{
					last_length = ( last_length + 1 ) % N ;
				}
			}

			order[ last_length ] = cards[ i ] ;
		}

		for( int i = 1 ; i < N ; i++ )
		{
			cout << order[ i ] << " " ;
		}
		cout << order[ 0 ] << endl ;
	}

	return 0 ;
}
