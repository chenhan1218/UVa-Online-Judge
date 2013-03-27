#include <iostream>
#include <iomanip>
using namespace std ;

#include <string>
#include <algorithm>

bool cmp( int a[], int b[] )
{
	return a[ 1 ] > b[ 1 ] ;
}

int
main()
{
	int		cases = 0 ;
	string	text1 ;
	string	text2 ;
	string	buffer ;
	// frequency of character frequency[ i ][ 0 ] is frequency[ i ][ 1 ]
	int*	frequency1[ 256 ] ;
	int*	frequency2[ 256 ] ;
	int		map[ 256 ] = { 0 } ;
	
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 0 ; i < 256 ; i++ )
	{
		frequency1[ i ] = new int[ 2 ] ;
		frequency2[ i ] = new int[ 2 ] ;
	}

	cin >> cases ;
	getline( cin, buffer ) ;
	for( i = 1 ; i <= cases ; i++ )
	{
		getline( cin, buffer ) ;
		getline( cin, text1 ) ;
		getline( cin, text2 ) ;

		for( j = 0 ; j < 256 ; j++ )
		{
			frequency1[ j ][ 0 ] = j ;
			frequency1[ j ][ 1 ] = 0 ;
			frequency2[ j ][ 0 ] = j ;
			frequency2[ j ][ 1 ] = 0 ;
			map[ j ] = j ;
		}

		for( j = 0 ; j < text1.length() ; j++ )
		{
			if( isalpha( text1[ j ] ) != 0 )
			{
				frequency1[ (int)text1[ j ] ][ 1 ] += 1 ;
			}
		}
		for( j = 0 ; j < text2.length() ; j++ )
		{
			if( isalpha( text2[ j ] ) != 0 )
			{
				frequency2[ (int)text2[ j ] ][ 1 ] += 1 ;
			}
		}

		sort( frequency1, frequency1 + 256, cmp ) ;
		sort( frequency2, frequency2 + 256, cmp ) ;

		for( j = 0 ; frequency1[ j ][ 1 ] != 0 ; j++ )
		{
			map[ frequency2[ j ][ 0 ] ] = frequency1[ j ][ 0 ] ;
		}

		if( i > 1 )
		{
			cout << endl ;
		}
		for( j = 0 ; j < text2.length() ; j++ )
		{
			cout << (char)map[ (int)text2[ j ] ] ;
		}
		cout << endl ;
	}

	return 0 ;
}
