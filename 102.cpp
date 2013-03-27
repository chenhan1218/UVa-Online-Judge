#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	int bin[ 3 ][ 3 ] , total_bottles = 0 , temp , largest_unmove , string_order ;

	while( cin >> bin[ 0 ][ 0 ] )
	{
		cin >> bin[ 0 ][ 1 ] >> bin[ 0 ][ 2 ] ;
		cin >> bin[ 1 ][ 0 ] >> bin[ 1 ][ 1 ] >> bin[ 1 ][ 2 ] ;
		cin >> bin[ 2 ][ 0 ] >> bin[ 2 ][ 1 ] >> bin[ 2 ][ 2 ] ;

		total_bottles = 0 ;

		for( int i = 0 ; i < 3 ; i++ )
		{
			for( int j = 0 ; j < 3 ; j++ )
			{
				total_bottles += bin[ i ][ j ] ;
			}
		}

		largest_unmove = bin[ 0 ][ 0 ] + bin[ 1 ][ 2 ] + bin[ 2 ][ 1 ] ;
		string_order = 1 ;

		if( ( temp = bin[ 0 ][ 0 ] + bin[ 1 ][ 1 ] + bin[ 2 ][ 2 ] ) > largest_unmove )
		{
			largest_unmove = temp ;
			string_order = 2 ;
		}
		if( ( temp = bin[ 0 ][ 2 ] + bin[ 1 ][ 0 ] + bin[ 2 ][ 1 ] ) > largest_unmove )
		{
			largest_unmove = temp ;
			string_order = 3 ;
		}
		if( ( temp = bin[ 0 ][ 2 ] + bin[ 1 ][ 1 ] + bin[ 2 ][ 0 ] ) > largest_unmove )
		{
			largest_unmove = temp ;
			string_order = 4 ;
		}
		if( ( temp = bin[ 0 ][ 1 ] + bin[ 1 ][ 0 ] + bin[ 2 ][ 2 ] ) > largest_unmove )
		{
			largest_unmove = temp ;
			string_order = 5 ;
		}
		if( ( temp = bin[ 0 ][ 1 ] + bin[ 1 ][ 2 ] + bin[ 2 ][ 0 ] ) > largest_unmove )
		{
			largest_unmove = temp ;
			string_order = 6 ;
		}

		if( string_order == 1 )
		{
			cout << "BCG " ;
		}
		else if( string_order == 2 )
		{
			cout << "BGC " ;
		}
		else if( string_order == 3 )
		{
			cout << "CBG " ;
		}
		else if( string_order == 4 )
		{
			cout << "CGB " ;
		}
		else if( string_order == 5 )
		{
			cout << "GBC " ;
		}
		else if( string_order == 6 )
		{
			cout << "GCB " ;
		}

		cout << total_bottles- largest_unmove << endl ;
	}

	return 0 ;
}
