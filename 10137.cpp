#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxStudents 1000

int
main()
{
	int		dollar[ MaxStudents + 1 ] = { 0 } ;
	int		cent[ MaxStudents + 1 ] = { 0 } ;
	char	buffer ;
	int		sum = 0 ;
	int		avg = 0 ;
	int		remainder = 0 ;
	int		exchange = 0 ;
	int		n = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}
		sum = 0 ;
		for( i = 1 ; i <= n ; i++ )
		{
			cin >> dollar[ i ] >> buffer >> cent[ i ] ;
			cent[ i ] += dollar[ i ] * 100 ;
			sum += cent[ i ] ;
		}

		avg = sum / n ;
		remainder = sum % n ;

		sort( &cent[ 1 ], &cent[ n + 1 ] ) ;

		exchange = 0 ;
		for( i = 1 ; i <= n - remainder ; i++ )
		{
			if( cent[ i ] < avg )
			{
				exchange += avg - cent[ i ] ;
			}
			else
			{
				break ;
			}
		}

		for( i = n - remainder + 1 ; i <= n ; i++ )
		{
			if( cent[ i ] < avg + 1 )
			{
				exchange += avg + 1 - cent[ i ] ;
			}
			else
			{
				break ;
			}
		}

		cout 	<< "$" << exchange / 100 << "." 
				<< setw(2) << setfill('0') << exchange % 100 << endl ;
	}

	return 0 ;
}
