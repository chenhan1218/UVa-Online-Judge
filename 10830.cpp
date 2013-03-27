/*
The idea is from Algorithmist.
http://www.algorithmist.com/

A number d appears \lfloor N/d \rfloor times as a divisor of the numbers 1 \ldots N. (Try it on paper if you don't see this) Because the number itself should not be counted, we have to substract 1 from this. This leads to this algorithm: \sum_{2\le d\le N}d(\lfloor \frac{N}{d} \rfloor-1). This formula gives the right results, but is way to slow.

When studying the sequence of values for \lfloor N/d \rfloor, we see that it is decreasing and that (especially at the end) the values are the same for quite a long time. Given l, we can binary search on the last value h, for which \lfloor N/l \rfloor =\lfloor N/h \rfloor. So

\sum_{l\le d\le h}d(\lfloor N/d \rfloor-1)

=\sum_{l\le d\le h}d(\lfloor N/l \rfloor -1)

=(\lfloor N/l \rfloor -1)\sum_{l\le d\le h}d

=(\lfloor N/l \rfloor -1)\frac{1}{2}(h-l+1)(l+h). If we binary search in [l\ldots N] it is still gets TLE. But if we tweak the upper bound, using the observation that h - l usually doesn't change much for two adjacent intervals, we can get AC. 
*/
#include <iostream>
#include <iomanip>
using namespace std ;

#include <cmath>

int main()
{
	long long n, CSOD_n, l, h, d;
	double n_root ;
	int cases = 0 ;

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}
		cases++ ;
		CSOD_n = 0 ;
		
		n_root = pow( n , 0.5 ) ;

		l = n ;
		for( int k = 2 ; k < n_root ; k++ )
		{
			// l is a number larger than N / ( k + 1 ) but cloest to N / ( k + 1 ) 
			// l is a number small than or equal to N / k but cloest to N / ( k + 1 ) 
			l = n / ( k + 1 ) + 1 ;
			h = n / k ;
			
			CSOD_n += ( (long long)( n/l )  - 1 ) * ( h - l + 1 ) * ( l + h ) / 2 ;
		}
		d = l - 1 ;
		for( ; d >= 2 ; d-- )
		{
			CSOD_n += d * (long long)( n/d - 1 ) ;
		}

		cout << "Case " << cases << ": " << CSOD_n << endl ;
	}

	return 0 ;
}
