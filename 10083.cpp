/*
http://www.csie.nctu.edu.tw/~chchu/acm/online/problem.php?no=10083
星子 寫於 2003-04-09 21:30:41
‧小心t=1和a=b的結果！
*/
#include <iostream>
#include <iomanip>
using namespace std ;

long long digit9 = 1000000000 ;
long long digit10 = digit9 * 10 ;
long long	digit9s[ 11 ] ;

void print()
{
	int		i = 0 ;

	i = 10 ;
	while( digit9s[ i ] == 0 && i > 0 )
	{
		i-- ;
	}

	cout << digit9s[ i ] ;

	for( i = i - 1 ; i >= 0 ; i-- )
	{
		cout << setw( 9 ) << setfill('0') << digit9s[ i ] ;
	}
}

void multiply( long long *digits9s, int t )
{
	int		i = 0 ; // loop counter
	digit9s[ 0 ] *= t ;

	for( i = 1 ; i < 11 ; i++ )
	{
		digit9s[ i ] *= t ;
		if( digit9s[ i - 1 ] >= digit9 )
		{
			digit9s[ i ] += digit9s[ i - 1 ] / digit9 ;
			digit9s[ i - 1 ] %= digit9 ;
		}
	}
}

void add1( long long *digits9s )
{
	int		i = 0 ; // loop counter
	digit9s[ 0 ] ++ ;

	for( i = 1 ; i < 11 ; i++ )
	{
		if( digit9s[ i - 1 ] >= digit9 )
		{
			digit9s[ i ] += digit9s[ i - 1 ] / digit9 ;
			digit9s[ i - 1 ] %= digit9 ;
		}
		else
		{
			break ;
		}
	}
}

int
main()
{
	int		t = 0 ;
	int		a = 0 ;
	int		b = 0 ;
	int		k = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> t >> a >> b )
	{
		cout << "(" << t << "^" << a << "-1)/(" << t << "^" << b << "-1) " ;

		if( t == 1 || a % b != 0 )
		{
			cout << "is not an integer with less than 100 digits." << endl ;
		}
		else
		{
			k = a / b ;

			digit9s[ 0 ] = 1 ;
			for( i = 1 ; i < 11 ; i++ )
			{
				digit9s[ i ] = 0 ;
			}

			for( i = 1 ; i <= k - 1 ; i++ )
			{
				for( j = 1 ; j <= b ; j++ )
				{
					multiply( digit9s, t ) ;

					if( digit9s[ 10 ] >= digit10 )
					{
						break ;
					}
				}

				add1( digit9s ) ;

				if( digit9s[ 10 ] >= digit10 )
				{
					break ;
				}
			}

			if( i >= k )
			{
				print() ;
				cout << endl ;
			}
			else
			{
				cout << "is not an integer with less than 100 digits." << endl ;
			}
		}
	}

	return 0 ;
}
