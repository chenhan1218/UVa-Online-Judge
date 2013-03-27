#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxS 20000

/*
int		niceness[ MaxS + 1 ] = { 0 } ;
int		sum[ MaxS + 1 ] = { 0 } ;
*/

int
main()
{
	int		b = 0 ;
	int		s = 0 ;
	int		max = 0 ;
	int		start = 0 ;
	int		end = 0 ;
	int		sum = 0 ;
	int		newStart = 0 ;
	int		temp = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	int		k = 0 ; // loop counter

	cin >> b ;
	for( i = 1 ; i <= b ; i++ )
	{
		cin >> s ;
		max = 0 ;
		start = 1 ;
		end = 1 ;
		sum = 0 ;
		newStart = 1 ;
		for( j = 1 ; j <= s - 1 ; j++ )
		{
			cin >> temp ;
			if( temp > 0 )
			{
				if( sum < 0 )	// a new start.
				{
					sum = temp ;
					newStart = j ;
				}
				else
				{
					sum += temp ;
				}

				if( sum > max )	// make max larger
				{
					max = sum ;
					start = newStart ;
					end = j + 1 ;
				}
				else if( sum == max && j + 1 - newStart > end - start )
				{
					start = newStart ;
					end = j + 1 ;
				}
			}
			else
			{
				sum += temp ;
			}
		}

		if( max == 0 )
		{
			cout << "Route " << i << " has no nice parts" << endl ;
		}
		else
		{
			cout 	<< "The nicest part of route " << i << " is between stops " 
					<< start << " and " << end << endl ;
		}
	}

	return 0 ;
}
