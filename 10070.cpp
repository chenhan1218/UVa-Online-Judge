#include <iostream>
#include <iomanip>
using namespace std ;

#define Max_digits 10000
char	year[ Max_digits + 1 ] ;
int		lenYear ;

int main()
{
	int		last4digits = 0 ;
	int		rem3 = 0 ; // remainder when divided by 3
	int		rem11 = 0 ; // remainder when divided by 11
	bool	firstCase = 1 ;
	int		i = 0 ; // loop counter

	while( cin >> year )
	{
		if( firstCase == 1 )
		{
			firstCase = 0 ;
		}
		else // If it is not first case, print a blank line.
		{
			cout << endl ;
		}

		lenYear = strlen( year ) ;
		last4digits = 	( year[ lenYear - 4 ] - '0' ) * 1000 + 
						( year[ lenYear - 3 ] - '0' ) * 100 + 
						( year[ lenYear - 2 ] - '0' ) * 10 + 
						( year[ lenYear - 1 ] - '0' ) ;

		rem3 = 0 ;
		rem11 = 0 ;
		for( i = 0 ; i + 1 < lenYear ; i = i + 2 )
		{
			rem3 += ( year[ i ] - '0' ) + ( year[ i + 1 ] - '0' ) ;
			rem11 += ( year[ i ] - '0' ) - ( year[ i + 1 ] - '0' ) ;
		}

		if( i == lenYear - 1 )
		{
			rem3 += ( year[ i ] - '0' ) ;
			rem11 += ( year[ i ] - '0' ) ;
		}

		if( last4digits % 400 == 0 )
		{
			cout << "This is leap year." << endl ;

			if( rem3 % 3 == 0 ) 	// Now year is divisible by 400, 
									// so if year divisible by 3, 
									// it must divisible by 15.
			{
				cout << "This is huluculu festival year." << endl ;
			}

			if( rem11 % 11 == 0 )
			{
				cout << "This is bulukulu festival year." << endl ;
			}
		}
		else if( last4digits % 100 != 0 && last4digits % 4 == 0 )
		{
			cout << "This is leap year." << endl ;

			if( last4digits % 5 == 0 && rem3 % 3 == 0 )
			{
				cout << "This is huluculu festival year." << endl ;
			}

			if( last4digits % 5 == 0 && rem11 % 11 == 0 )
			{
				cout << "This is bulukulu festival year." << endl ;
			}
		}
		else
		{
			if( last4digits % 5 == 0 && rem3 % 3 == 0 )
			{
				cout << "This is huluculu festival year." << endl ;
			}
			else
			{
				cout << "This is an ordinary year." << endl ;
			}
		}
	}
	return 0 ;
}
