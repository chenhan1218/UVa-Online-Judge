#include <iostream>
using namespace std ;

void sort( int **letters_times , int a , int b )
{
	int *temp ;
	for( int i = 0 ; i < b - a ; i++ )
	{
		for( int j = a + 1 ; j <= b - i ; j++ )
		{
			if( letters_times[ j ][ 1 ] < letters_times[ j - 1 ][ 1 ] )
			{
				temp = letters_times[ j ] ;
				letters_times[ j ] = letters_times[ j - 1 ] ;
				letters_times[ j - 1 ] = temp ;
			}
			else if( letters_times[ j ][ 1 ] == letters_times[ j - 1 ][ 1 ] && 
					letters_times[ j ][ 0 ] > letters_times[ j - 1 ][ 0 ] )
			{
				temp = letters_times[ j ] ;
				letters_times[ j ] = letters_times[ j - 1 ] ;
				letters_times[ j - 1 ] = temp ;
			}
		}
	}
}

int main()
{
	int letters[ 128 ] = { 0 } ;

	char input ;

	int nonzero , maxtime_input , max_input ;

	int loop_times = 0 ;

	while( cin.get( input ) )
	{
		if( input != '\n' && input != '\r' )
		{
			letters[ static_cast<int>( input ) ] ++ ;
		}
		else
		{
			loop_times++ ;
			int **letters_times = new int *[ 128 ] ;
			nonzero = 0 ;

			for( int i = 32 ; i < 128 ; i++ )
			{
				if( letters[ i ] > 0 )
				{
					nonzero ++ ;
					letters_times[ nonzero ] = new int [ 2 ] ;
					letters_times[ nonzero ][ 0 ] = i ;
					letters_times[ nonzero ][ 1 ] = letters[ i ] ;
				}
			}

			sort( letters_times , 1 , nonzero ) ;

			if( loop_times != 1 )
			{
				cout << endl ;
			}

			for( int i = 1 ; i <= nonzero ; i++ )
			{
				cout << letters_times[ i ][ 0 ] << " " << letters_times[ i ][ 1 ] << endl ;
			}

			for( int i = 32 ; i < 128 ; i++ )
			{
				letters[ i ] = 0 ;
			}
		}
	}

	return 0 ;
}
