#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;
#define MaxLen 60

int	d[ MaxLen + 1 ][ MaxLen + 1 ][ MaxLen + 1 ][ 2 ] = { 0 } ;

int
main()
{
	int		testcase = 0 ;
	string	a ;
	string	b ;
	string	c ;
	int		x = 0 ;
	int		y = 0 ;
	int		z = 0 ;
	int		loc = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cin >> testcase ;

	while( testcase > 0 )
	{
		testcase-- ;

		cin >> a >> b >> c ;

		for( x = 1 ; x <= a.size() ; x++ )
		{
			d[ 1 ][ x ][ 0 ][ 0 ] = d[ 1 ][ x - 1 ][ 0 ][ 0 ] ;
			if( c[ 0 ] == a[ x - 1 ] )
				d[ 1 ][ x ][ 0 ][ 0 ] += 1 ;

			for( y = 1 ; y <= b.size() ; y++ )
				d[ 1 ][ x ][ y ][ 0 ] = d[ 1 ][ x ][ 0 ][ 0 ] ;
		}

		for( y = 1 ; y <= b.size() ; y++ )
		{
			d[ 1 ][ 0 ][ y ][ 1 ] = d[ 1 ][ 0 ][ y - 1 ][ 1 ] ;
			if( c[ 0 ] == b[ y - 1 ] )
				d[ 1 ][ 0 ][ y ][ 1 ] += 1 ;

			for( x = 1 ; x <= a.size() ; x++ )
				d[ 1 ][ x ][ y ][ 1 ] = d[ 1 ][ 0 ][ y ][ 1 ] ;
		}

/*
for( x = 0 ; x <= a.size() ; x++ )
{
	for( y = 0 ; y <= b.size() ; y++ )
	{
		cout << d[ 1 ][ x ][ y ][ 0 ] << " " << d[ 1 ][ x ][ y ][ 1 ] << "\t" ;
	}
	cout << endl ;
}
cout << endl ;
*/

		for( z = 2 ; z <= c.size() ; z++ )
		{
			for( x = 0 ; x <= a.size() ; x++ )
			{
				for( y = 0 ; y <= b.size() ; y++ )
				{
					if( x > 0 )
					{
						d[ z ][ x ][ y ][ 0 ] = d[ z ][ x - 1 ][ y ][ 0 ] ;

						if( c[ z - 1 ] == a[ x - 1 ] )
						{
							d[ z ][ x ][ y ][ 0 ] += d[ z - 1 ][ x - 1 ][ y ][ 0 ] + 
													d[ z - 1 ][ x - 1 ][ y ][ 1 ] ;
						}

						d[ z ][ x ][ y ][ 0 ] %= 10007 ;
					}

					if( y > 0 )
					{
						d[ z ][ x ][ y ][ 1 ] = d[ z ][ x ][ y - 1 ][ 1 ] ;

						if( c[ z - 1 ] == b[ y - 1 ] )
						{
							d[ z ][ x ][ y ][ 1 ] += d[ z - 1 ][ x ][ y - 1 ][ 0 ] + 
													d[ z - 1 ][ x ][ y - 1 ][ 1 ] ;
						}

						d[ z ][ x ][ y ][ 1 ] %= 10007 ;
					}
				}
			}
		}

		cout << ( d[ c.size() ][ a.size() ][ b.size() ][ 0 ] + 
				d[ c.size() ][ a.size() ][ b.size() ][ 1 ] ) % 10007 << endl ;
	}

	return 0 ;
}

/* TLE but easy Version
#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;
#define MaxLen 60

int	d[ MaxLen + 1 ][ MaxLen + 1 ][ MaxLen + 1 ] = { 0 } ;

int
main()
{
	int		testcase = 0 ;
	string	a ;
	string	b ;
	string	c ;
	int		x = 0 ;
	int		y = 0 ;
	int		z = 0 ;
	int		loc = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cin >> testcase ;

	for( i = 0 ; i <= MaxLen ; i++ )
	{
		for( j = 0 ; j <= MaxLen ; j++ )
		{
			d[ 0 ][ i ][ j ] = 1 ;
			d[ 0 ][ i ][ j ] = 1 ;
		}
	}

	while( testcase > 0 )
	{
		testcase-- ;

		cin >> a >> b >> c ;

		for( z = 1 ; z <= c.size() ; z++ )
		{
			for( x = 0 ; x <= a.size() ; x++ )
			{
				for( y = 0 ; y <= b.size() ; y++ )
				{
					d[ z ][ x ][ y ] = 0 ;
					for( i = 1 ; i <= x ; i++ )
					{
						if( c[ z - 1 ] == a[ i - 1 ] )
						{
							d[ z ][ x ][ y ] += d[ z - 1 ][ i - 1 ][ y ] ;
						}
					}

					for( i = 1 ; i <= y ; i++ )
					{
						if( c[ z - 1 ] == b[ i - 1 ] )
						{
							d[ z ][ x ][ y ] += d[ z - 1 ][ x ][ i - 1 ] ;
						}
					}

					d[ z ][ x ][ y ] %= 10007 ;
				}
			}
		}

		cout << d[ c.size() ][ a.size() ][ b.size() ] << endl ;
	}

	return 0 ;
}*/

