/*
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
using namespace std ;

#define MaxR 100

vector<unsigned long long int>	table[ 126 + 1 ] ;
vector<unsigned long long int>	powOfTable[ 126 + 1 ] ;

void makeTable( int r, string s[] )
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 0 ; i <= 126 ; i++ )
		table[ i ].assign( 127, 0 ) ;

	for( i = 33 ; i <= 126 ; i++ )
		table[ i ][ i ] = 1 ;

	for( i = 0 ; i < r ; i++ )
	{
		for( j = 33 ; j <= 126 ; j++)
		{
			table[ (int)s[ i ][ 0 ] ][ j ] = 
				count( s[ i ].begin() + 3, s[ i ].end(), (char)j ) ;
		}
	}
}

int	matrixmult( vector<unsigned long long int> a[], vector<unsigned long long int> b[], int n )
{
	vector<unsigned long long int>	matrix[ n ] ;
	int	i = 0 ;
	int	j = 0 ;
	int	k = 0 ;

	for( i = 0 ; i < n ; i++ )
	{
		matrix[ i ].assign( n, 0 ) ;
	}

	for( i = 0 ; i < n ; i++ )
	{
		for( j = 0 ; j < n ; j++ )
		{
			for( k = 0 ; k < n ; k++ )
			{
				matrix[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ] ;
			}
		}
	}

	for( i = 0 ; i < n ; i++ )
	{
		a[ i ].assign( matrix[ i ].begin(), matrix[ i ].begin() + n ) ;
	}
}

void matrix_pow( vector<unsigned long long int> b[], const int n , int power )
{
	vector<unsigned long long int>	matrix[ n ] ;
	int	i = 0 ;
	int	j = 0 ;


	if( power == 1 )
	{
		return ;
	}
	else if( power == 0 )
	{
		for( i = 0 ; i < n ; i++ )
			b[ i ].assign( n, 0 ) ;
		for( i = 0 ; i < n ; i++ )
			b[ i ][ i ] = 1 ;
		return ;
	}

	if( power % 2 == 1 )
	{
		for( i = 0 ; i < n ; i++ )
		{
			matrix[ i ].assign( b[ i ].begin(), b[ i ].begin() + n ) ;
		}

		matrix_pow( b, n, power / 2 ) ;
		matrixmult( b, b, n ) ;
		matrixmult( b, matrix, n ) ;
	}
	else
	{
		matrix_pow( b, n, power / 2 ) ;
		matrixmult( b, b, n ) ;
	}
}

unsigned long long int occurances( string initial_string, char x, int n )
{
	unsigned long long int	occur[ 126 + 1 ] = { 0 } ;
	unsigned long long int	ans = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	for( i = 33; i <= 126 ; i++ )
	{
		occur[ i ] = count( initial_string.begin(), initial_string.end(), (char)i ) ;
	}

	for( i = 0 ; i <= 126 ; i++ )
		powOfTable[ i ].assign( table[ i ].begin(), table[ i ].end() ) ;

	matrix_pow( powOfTable, 127, n ) ;

	for( i = 0 ; i <= 126 ; i++ )
		ans += occur[ i ] * powOfTable[ i ][ (int)x ] ;

	return ans ;
}

int
main()
{
	int		r = 0 ;
	string	s[ MaxR ] ;
	int		q = 0 ;
	string	initial_string ;
	char	x = 0 ;
	int		n = 0 ;
	int		testcase = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cin >> testcase ;

	while( testcase > 0 )
	{
		testcase-- ;

		cin >> r ;

		for( i = 0 ; i < r ; i++ )
		{
			cin >> s[ i ] ;
		}

		makeTable( r, s ) ;

		cin >> q ;

		for( i = 0 ; i < q ; i++ )
		{
			cin >> initial_string >> x >> n ;

			cout << occurances( initial_string, x, n ) << endl ;
		}
	}

	return 0 ;
}
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std ;

#define MaxR 100

int	table[ 126 + 1 ][ 126 + 1 ] = { 0 } ;

void makeTable( int r, string s[] )
{
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( i = 0 ; i <= 126 ; i++ )
		fill( table[ i ], table[ i ] + 127 , 0 ) ;

	for( i = 33 ; i <= 126 ; i++ )
		table[ i ][ i ] = 1 ;

	for( i = 0 ; i < r ; i++ )
	{
		for( j = 33 ; j <= 126 ; j++)
		{
			table[ (int)s[ i ][ 0 ] ][ j ] = 
				count( s[ i ].begin() + 3, s[ i ].end(), (char)j ) ;
		}
	}
}

unsigned long long int occurances( string initial_string, char x, int n )
{
	unsigned long long int	occur[ 126 + 1 ] = { 0 } ;
	unsigned long long int	ans[ 126 + 1 ] = { 0 } ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	for( i = 33; i <= 126 ; i++ )
	{
		ans[ i ] = count( initial_string.begin(), initial_string.end(), (char)i ) ;
	}

	for( i = 0 ; i < n ; i++ )
	{
		copy( ans, &ans[ 126 ] + 1, occur ) ;
		fill( ans, &ans[ 126 ] + 1, (unsigned long long int)0 ) ;

		for( j = 33 ; j <= 126 ; j++ )
		{
			for( k = 33 ; k <= 126 ; k++ )
			{
				ans[ k ] += occur[ j ] * table[ j ][ k ] ;
			}
		}
	}

	return ans[ (int)x ] ;
}

int
main()
{
	int		r = 0 ;
	string	s[ MaxR ] ;
	int		q = 0 ;
	string	initial_string ;
	char	x = 0 ;
	int		n = 0 ;
	int		testcase = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cin >> testcase ;

	while( testcase > 0 )
	{
		testcase-- ;

		cin >> r ;

		for( i = 0 ; i < r ; i++ )
		{
			cin >> s[ i ] ;
		}

		makeTable( r, s ) ;

		cin >> q ;

		for( i = 0 ; i < q ; i++ )
		{
			cin >> initial_string >> x >> n ;

			cout << occurances( initial_string, x, n ) << endl ;
		}
	}

	return 0 ;
}
