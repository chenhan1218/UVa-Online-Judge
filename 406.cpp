#include <iostream>
using namespace std ;

int main()
{
	int **prime = new int *[ 171 ] ;
	prime[ 1 ] = new int [ 2 ] ;
	prime[ 1 ][ 0 ] = 1 ;
	prime[ 1 ][ 1 ] = 1 ;
	prime[ 2 ] = new int [ 1 ] ;
	prime[ 2 ][ 0 ] = 2 ;
	prime[ 2 ][ 1 ] = 4 ;
	prime[ 3 ] = new int [ 1 ] ;
	prime[ 3 ][ 0 ] = 3 ;
	prime[ 3 ][ 1 ] = 9 ;
	int largest_prime_number = 2 ;

	for( int i = 4 ; i < 171 ; i++ )
	{
		for( int j = prime[ i - 1 ][ 0 ] + 2 ;  ; j = j + 2 )
		{
			int k ;
			for( k = 2 ; prime[ k ][ 1 ] < j ; k++ )
			{
				if( j % prime[ k ][ 0 ] == 0 )
				{
					break ;
				}
			}

			if( prime[ k ][ 1 ] > j )
			{
				prime[ i ] = new int [ 2 ] ;

				prime[ i ][ 0 ] = j ;
				prime[ i ][ 1 ] = j * j ;

				break ;
			}
		}
	}

	int N , C , first , last , list , median_list ;

	while( cin >> N >> C )
	{
		first = 1 ;
		last = 170 ;
		list = ( first + last ) / 2 ;
		while( last - first > 1 )
		{
			if( prime[ list ][ 0 ] > N )
			{
				last = list ;
			}
			else
			{
				first = list ;
			}

			list = ( first + last ) / 2 ;
		}

		if( list % 2 == 0 )
		{
			median_list = list / 2 ;

			if( median_list >= C )
			{
				cout << N << " " << C << ":" ;
				for( int i = median_list - C + 1 ; i <= median_list + C ; i++ )
				{
					cout << " " << prime[ i ][ 0 ] ;
				}
			}
			else
			{
				cout << N << " " << C << ":" ;
				for( int i = 1 ; i <= list ; i++ )
				{
					cout << " " << prime[ i ][ 0 ] ;
				}
			}
		}
		else
		{
			median_list = list / 2 + 1 ;

			if( median_list >= C )
			{
				cout << N << " " << C << ":" ;
				for( int i = median_list - C + 1 ; i <= median_list + C - 1 ; i++ )
				{
					cout << " " << prime[ i ][ 0 ] ;
				}
			}
			else
			{
				cout << N << " " << C << ":" ;
				for( int i = 1 ; i <= list ; i++ )
				{
					cout << " " << prime[ i ][ 0 ] ;
				}
			}
		}

		cout << endl << endl ;
	}

	return 0 ;
}
