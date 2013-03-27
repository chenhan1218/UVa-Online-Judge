/*
male	female	magic	total
0		0		1		1
1		0		1		2
2		1		1		4
4		2		1		7
7		4		1		12

male	total
0		1
1		1

*/
#include <iostream>
#include <iomanip>
using namespace std ;

long long int	num[ 100 ][ 2 ] = { 0 } ;

int main()
{
	int		n = 0 ;
	int		i = 0 ; 
	num[ 0 ][ 0 ] = 0 ;
	num[ 0 ][ 1 ] = 1 ;

	for( i = 1 ; i < 100 ; i++ )
	{
		num[ i ][ 0 ] = num[ i - 1 ][ 1 ] ;
		num[ i ][ 1 ] = num[ i - 1 ][ 0 ] + num[ i - 1 ][ 1 ] + 1 ;
	}

	while( cin >> n )
	{
		if( n == -1 )
		{
			break ;
		}

		cout << num[ n ][ 0 ] << " " << num[ n ][ 1 ] << endl ;
	}

	return 0 ;
}

