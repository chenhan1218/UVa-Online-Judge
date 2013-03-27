#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>
#include <string>
#include <sstream>
using std::istringstream ;

#define Max_n 33000

int			previous[ Max_n + 1 ] = { 0 } ;
int			next[ Max_n + 1 ] = { 0 } ;

void initial( long long int n )
{
	long long int	i = 0 ; // loop counter

	previous[ 2 ] = -1 ;
	next[ 2 ] = 3 ;
	previous[ 3 ] = 2 ;
	next[ 3 ] = 5 ;
	for( i = 3 ; i <= n ; i += 2 )
	{
		previous[ i ] = i - 2 ;
		next[ i ] = i + 2 ;
	}
	next[ i - 2 ] = -1 ;
}

void remove( int x )
{
	next[ previous[ x ] ] = next[ x ] ;
	previous[ next[ x ] ] = previous[ x ] ;

	previous[ x ] = 0 ;
	next[ x ] = 0 ;
}

string itostring( long long int x )
{
	string temp ;
	temp.insert( 0, 1, '0' + x % 10 ) ;
	while( x >= 10 )
	{
		x /= 10 ;
		temp.insert( 0, 1, '0' + x % 10 ) ;
	}

	return temp ;
}

int
main()
{
	long long int	n = 33000 ;
	long long int	numPrimes = 0 ;
	long long int	prime = 0 ;
	long long int	fact = 0 ;
	long long int	mult = 0 ;
	long long int	i = 0 ; // loop counter
	long long int	j = 0 ; // loop counter
	long long int	k = 0 ; // loop counter
	string	buffer ;
	string	answer ;
	int		value = 0 ;
	int		p = 0 ;
	int		e = 0 ;

	initial( n ) ;

	for( prime = 3 ; prime * prime <= n ; prime = next[ prime ] )
	{
		for( fact = prime ; prime * fact <= n ; fact = next[ fact ] )
		{
			for( mult = prime * fact ; mult <= n ; mult *= prime )
			{
				remove( mult ) ;
			}
		}
	}

	while( getline( cin, buffer ) )
	{
		if( buffer[ 0 ] == '0' )
		{
			break ;
		}

		istringstream stream( buffer ) ;
		value = 1 ;
		while( stream >> p >> e )
		{
			while( e > 0 )
			{
				e-- ;
				value *= p ;
			}
		}

		value-- ;
		answer = "" ;
		for( prime = 2 ; prime * prime <= value ; prime = next[ prime ] )
		{
			e = 0 ;
			while( value % prime == 0 )
			{
				e++ ;
				value /= prime ;
			}

			if( e > 0 )
			{
				if( answer.length() > 0 )
				{
					answer = ' ' + answer ;
				}
				answer = itostring( prime )+ ' ' + itostring( e ) + answer ;
			}
		}

		// if the remain value is a prime.
		if( value > 1 )
		{
			if( answer.length() > 0 )
			{
				answer = ' ' + answer ;
			}
			answer = itostring( value )+ ' ' + itostring( 1 ) + answer ;
		}

		cout << answer << endl ;
	}

	return 0 ;
}
