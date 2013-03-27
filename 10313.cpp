/*
The number of ways of making $i with coins of value $j or less is the same as the # of ways of making $i with at most j coins. This is a property of integer partitions (splitting a number into a sum of smaller numbers), which is basically what we're dealing with. i.e., the number of partitions of n with <= k parts (in the sum) is equal to the number of partitions of n where each part is <= k.

The proof is to draw the partition as what's called a Ferrer's diagram. Let's take 1+1+1+3+3+4 = 13 as an example:

XXXX
XXX
XXX
X
X
X

Well, if you transpose this (like a matrix) you get:

XXXXXX
XXX
XXX
X

*/
#include <iostream>
#include <numeric>
#include <sstream>
using namespace std ;

const int	MaxN = 300 ;
const int	MaxL = 1000 ;
// way[ n ][ l ] represent ways of pay n dollars using less than or equal to l value coins
long long int	way[ MaxN + 1 ][ MaxL + 1 ] = { 0 } ;

int main()
{
	int		n = 0 ;
	int		l1 = 0 ;
	int		l2 = 0 ;
	string	buffer ;
	
	for( int i = 0 ; i <= MaxL ; i++ )
		way[ 0 ][ i ] = 1 ;
	for( int i = 1 ; i <= MaxN ; i++ )
	{
		for( int j = 1 ; j <= MaxL ; j++ )
		{
			way[ i ][ j ] = way[ i ][ j - 1 ] ;

			if( i >= j )
				way[ i ][ j ] += way[ i - j ][ j ] ;
		}
	}
	
	while( getline( cin, buffer ) )
	{
		istringstream	is( buffer ) ;
		is >> n ;
		
		if( is >> l1 )
		{
			if( is >> l2 )
			{
				if( l1 != 0 )
					cout << way[n][l2] - way[n][l1-1] << endl ;
				else
					cout << way[n][l2] << endl ;
			}
			else
			{
				cout << way[n][l1] << endl ;
			}
		}
		else
		{
			cout << way[n][n] << endl ;
		}
	}
	
	return 0 ;
}

/* AC but slower version
#include <iostream>
#include <numeric>
#include <sstream>
using namespace std ;

int main()
{
	const int	MaxN = 300 ;
	const int	MaxL = 1000 ;
	// way[ n ][ l ] represent ways of pay n dollars using l coins
	long long int	way[ MaxN + 1 ][ MaxL + 1 ] = { 0 } ;
	int		n = 0 ;
	int		l1 = 0 ;
	int		l2 = 0 ;
	string	buffer ;
	
	way[ 0 ][ 0 ] = 1 ;
	for( int i = 1 ; i <= MaxN ; i++ )
	{
		for( int j = 1 ; j <= i ; j++ )
		{
			// number of 1 dollars in way[ i ][ j ]
			for( int k = 0 ; k <= j ; k++ )
			{
				way[ i ][ j ] += way[ i - j ][ j - k ] ;
			}
		}
	}
	
	while( getline( cin, buffer ) )
	{
		istringstream	is( buffer ) ;
		is >> n ;
		
		if( is >> l1 )
		{
			if( is >> l2 )
			{
				cout << accumulate( &way[n][l1], &way[n][l2]+1, (long long int)0 ) << endl ;
			}
			else
			{
				cout << accumulate( &way[n][0], &way[n][l1]+1, (long long int)0 ) << endl ;
			}
		}
		else
		{
			cout << accumulate( &way[n][0], &way[n][n]+1, (long long int)0 ) << endl ;
		}
	}
	
	return 0 ;
}
*/
