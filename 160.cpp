#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	int prime[ 26 ] = { 	 0 ,
				 2 ,  3 ,  5 ,  7 , 11 , 
				13 , 17 , 19 , 23 , 29 , 
				31 , 37 , 41 , 43 , 47 , 
				53 , 59 , 61 , 67 , 71 , 
				73 , 79 , 83 , 89 , 97 , } ;
	int factors_factorials[ 101 ][ 27 ] = { 0 } ;

	for( int i = 2 ; i <= 100 ; i++ )
	{
		int dealing = i ;
		int j = 1 ;
		while( dealing > 1 )
		{
			while( dealing % prime[ j ] != 0 )
			{
				j++ ;
			}

			while( dealing % prime[ j ] == 0 )
			{
				dealing /= prime[ j ] ;
				factors_factorials[ i ][ j ]++ ;
			}
		}

		for( int j = 1 ; factors_factorials[ i - 1 ][ j ] > 0 ; j++ )
		{
			factors_factorials[ i ][ j ] += factors_factorials[ i - 1 ][ j ] ;
		}
	}

	int N ;

	while( cin >> N )
	{
		if( N == 0 )
		{
			break ;
		}
		else if( N == 1 )
		{
			cout << "  1! =   0" << endl ;
		}
		else
		{
			cout << setw( 3 ) << N << "! =" ;

			for( int i = 1 ; factors_factorials[ N ][ i ] > 0 ; i++ )
			{
				if( i % 15 == 1 && i > 15 )
				{
					cout << endl << setw( 9 ) << factors_factorials[ N ][ i ] ;
				}
				else
				{
					cout << setw( 3 ) << factors_factorials[ N ][ i ] ;
				}
			}

			cout << endl ;
		}
	}

	return 0 ;
}
