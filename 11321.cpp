/*
Robert Gerbicz
Learning poster


Joined: 02 May 2007
Posts: 55
Location: Hungary, Pest county, Halasztelek
	
PostPosted: Sun Oct 21, 2007 12:41 am    Post subject: Re: 11321 - Sort! Sort!! and Sort!!! 	Reply with quote
Orion wrote:
Hi, can someone give me a hand on this problem, i got WA , i just used a sort with the criteria explained in the problem:

the function used to compare:

Code:

int modcmp (int *a, int *b) {
...
   return *a - *b;  // when both are even the smaller precede the larger
...


Please note that the numbers are int, so -2^31<x,y<2^31 it means that -2^32<x-y<2^32 so you will get nice overflow for int type, and it gives you WA. Try to use <,> symbols in your function.
_________________
http://acm.uva.es/problemset/usersnew.php?user=47663

Last edited by Robert Gerbicz on Sun Oct 21, 2007 12:42 am; edited 1 time in total
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std ;
#define MaxM 10000

long long int		array[ MaxM ] = { 0 } ;
int		n = 0 ;
int		m = 0 ;

bool cmp( int a, int b )
{
	if( a % m != b % m )
	{
		return a % m < b % m ;
	}
	else if( ( a - b ) % 2 != 0 )
	{
		return a % 2 != 0 ;
	}
	else if( a % 2 == 0 )
	{
		return a < b ;
	}
	else
	{
		return a > b ;
	}
}

int main()
{
	int		i = 0 ;
	int		j = 0 ;

	while( cin >> n >> m )
	{
		if( n == 0 && m == 0 )
		{
			cout << "0 0" << endl ;
			break ;
		}

		for( j = 0 ; j < n ; j++ )
		{
			cin >> array[ j ] ;
		}

		sort( array, array + n, cmp ) ;

		cout << n << " " << m << endl ;
		for( j = 0 ; j < n ; j++ )
		{
			cout << array[ j ] << endl ;
		}
	}
	return 0 ;
}

