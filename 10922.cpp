#include <iostream>
#include <iomanip>
using namespace std ;

int _9degree( int number ) ;
int _9degree( const char *digits ) ;
int ctoi( char c ) ;

int 
ctoi( char c )
{
	return (int)c - (int)'0' ;
}

int 
_9degree( int number )
{
	int sumDigits = 0 ;
	if( number % 9 == 0 )
	{
		if( number <= 9 )
		{
			return 0 ;
		}
		else
		{
			while( number > 0 )
			{
				sumDigits += number % 10 ;
				number /= 10 ;
			}

			return _9degree( sumDigits ) + 1 ;
		}
	}
	else
	{
		return -1 ;
	}
}

int 
_9degree( const char *digits )
{
	int	sum = 0 ;
	int lenDigits = strlen( digits ) ;
	int i = 0 ; // loop counter ;

	for( i = 0 ; i < lenDigits ; i++ )
	{
		sum += ctoi( digits[ i ] ) ;
	}

	if( sum % 9 == 0 )
	{
		return _9degree( sum ) + 1 ;
	}
	else
	{
		return -1 ;
	}
}

int
main()
{
	char	digits[ 1001 ] ;
	int		depth = 0 ;

	while( cin >> digits )
	{
		if( digits[ 0 ] == '0' )
		{
			break ;
		}

		depth = _9degree( digits ) ;

		if( depth < 0 )
		{
			cout << digits << " is not a multiple of 9." << endl ;
		}
		else
		{
			cout 	<< digits << " is a multiple of 9 and has 9-degree "
					<< depth << "." << endl ;
		}
	}

	return 0 ;
}
