#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std ;

#include <cstring>

#define MaxCharacters 100
#define Maxdigit9s 12

long long	digit9 = 1000000000 ;
long long	digit9s[ Maxdigit9s + 1 ] = { 0 } ;
char		VeryLongInteger[ MaxCharacters + 1 ] = { 0 } ;


void print()
{
	int		i = 0 ;

	i = Maxdigit9s ;
	while( digit9s[ i ] == 0 && i > 1 )
	{
		i-- ;
	}

	cout << digit9s[ i ] ;

	for( i = i - 1 ; i >= 1 ; i-- )
	{
		cout << setw( 9 ) << setfill('0') << digit9s[ i ] ;
	}
}

void add( char *VeryLongInteger )
{
	int		lenVeryLongInteger = 0 ;
	int		startOfdigit9 = 0 ;
	int		i = 0 ; // loop counter

	lenVeryLongInteger = strlen( VeryLongInteger ) ;

	for( 	i = 1, startOfdigit9 = lenVeryLongInteger - 9 ; startOfdigit9 >= 0 ; 
			i++, startOfdigit9 -= 9 )
	{
		digit9s[ i ] += atol( VeryLongInteger + startOfdigit9 ) ;

		VeryLongInteger[ startOfdigit9 ] = '\0' ;
	}

	digit9s[ i ] += atol( VeryLongInteger ) ;

	for( i = 1 ; i < Maxdigit9s ; i++ )
	{
		if( digit9s[ i ] >= digit9 )
		{
			digit9s[ i + 1 ] += digit9s[ i ] / digit9 ;
			digit9s[ i ] %= digit9 ;
		}
	}
}

int
main()
{
	while( cin.getline( VeryLongInteger, MaxCharacters + 1 ) )
	{
		if( VeryLongInteger[ 0 ] == '0' )
		{
			break ;
		}

		add( VeryLongInteger ) ;
	}

	print() ;
	cout << endl ;

	return 0 ;
}
