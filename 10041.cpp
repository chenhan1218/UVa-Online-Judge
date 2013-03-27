#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std ;

#define MaxR 500

int main()
{
	int		r = 0 ;
	int		s[ MaxR ] = { 0 } ;
	int		sum = 0 ;
	double	avg = 0 ;
	int		optimal = 0 ;
	int		total = 0 ;
	int		t = 0 ;
	int		i = 0 ;
	
	cin >> t ;
	while( t > 0 )
	{
		t-- ;
		
		cin >> r ;
		for( i = 0 ; i < r ; i++ )
			cin >> s[ i ] ;
		
		sort( s, s + r ) ;

		optimal = s[ r / 2 ] ;
		
		total = 0 ;
		for( i = 0 ; i < r ; i++ )
			total += abs( s[ i ] - optimal ) ;
		cout << total << endl ;
	}
	
	return 0 ;
}

/* WA version ( may be caused by float)
#include <iostream>
#include <numeric>
#include <cmath>
using namespace std ;

#define MaxR 500

int main()
{
	int		r = 0 ;
	int		s[ MaxR ] = { 0 } ;
	int		sum = 0 ;
	double	avg = 0 ;
	int		optimal = 0 ;
	int		total = 0 ;
	int		t = 0 ;
	int		i = 0 ;
	
	cin >> t ;
	while( t > 0 )
	{
		t-- ;
		
		cin >> r ;
		for( i = 0 ; i < r ; i++ )
			cin >> s[ i ] ;
		
		sum = accumulate( s, s + r, 0 ) ;
		avg = sum / (double)r ;

		optimal = s[ 0 ] ;
		for( i = 1 ; i < r ; i++ )
			if( fabs( s[ i ] - avg ) < fabs( optimal - avg ) )
				optimal = s[ i ] ;
		
		total = 0 ;
		for( i = 0 ; i < r ; i++ )
			total += abs( s[ i ] - optimal ) ;
		cout << total << endl ;
	}
	
	return 0 ;
}

*/
