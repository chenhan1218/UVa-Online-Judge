#include <iostream>
using namespace std ;

#include <cmath>

// Caution: This function can only solve x  having magnitude at least 2 
// and being within the range of a (32-bit) int in C, C++, and Java.
int main()
{
	long long x ;
	long double b, temp, p ;
	bool answer_founded = 0 ;
	
	while( cin >> x )
	{
		if( x == 0 )
		{
			break ;
		}
		
		answer_founded = 0 ;
		
		if( x > 0 )
		{
			for( b = 2 ; b <= 8 && answer_founded == 0 ; b++ )
			{
				temp = log( x ) / log( b ) ;
				p = floor( temp + 0.5 ) ;
				if( abs( temp - p ) < 0.1 && x == ( long long )( pow( b , p ) + 0.5 ) )
				{
					cout << p << endl ;
					answer_founded = 1 ;
				}
			}
		
			for( p = 10 ; p >= 2 && answer_founded == 0 ; p-- )
			{
				temp = pow( x , 1.0 / p ) ;
				b = (long double)( floor( temp + 0.5 ) ) ;
				if( abs( temp - b ) < 0.1 && x == ( long long )( pow( b , p ) + 0.5 ) )
				{
					cout << p << endl ;
					answer_founded = 1 ;
				}
			}
		
			if( answer_founded == 0 )
			{
				cout << "1" << endl ;
				answer_founded = 1 ;
			}
		}
		else
		{
			x = -1 * x ;
			// let x be positive, but we should be careful that p can't be an even number.
			
			for( b = 2 ; b <= 8 && answer_founded == 0 ; b++ )
			{
				temp = log( x ) / log( b ) ;
				p = floor( temp + 0.5 ) ;
				if( abs( temp - p ) < 0.01 && x == ( long long )( pow( b , p ) + 0.5 ) )
				{
					while( ( (int)p ) % 2 == 0 )
					{
						p /= 2 ;
					}
					cout << p << endl ;
					answer_founded = 1 ;
				}
			}
		
			// let p allways be odd number, so the loop is changed.
			for( p = 9 ; p >= 3 && answer_founded == 0 ; p = p - 2 )
			{
				temp = pow( x , 1.0 / p ) ;
				b = (long double)( floor( temp + 0.5 ) ) ;
				if( abs( temp - b ) < 0.01 && x == ( long long )( pow( b , p ) + 0.5 ) )
				{
					cout << p << endl ;
					answer_founded = 1 ;
				}
			}
		
			if( answer_founded == 0 )
			{
				cout << "1" << endl ;
				answer_founded = 1 ;
			}
		}
	}

	return 0 ;
}
