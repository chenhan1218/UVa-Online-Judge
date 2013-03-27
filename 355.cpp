#include <iostream>
#include <string>
using namespace std ;

int	char2int( char c )
{
	if( c >= '0' && c <= '9' )
		return c - '0' ;
	else
		return c - 'A' + 10 ;
}

char int2char( int n )
{
	if( n < 10 )
		return '0' + n ;
	else
		return 'A' + n - 10 ;
}

bool str2int( const string &s, int base, unsigned long long int &n )
{
	n = 0 ;
	for( int i = 0 ; i < s.size() ; i++ )
	{
		if( char2int( s[ i ]) < base )
		{
			n = n * base + char2int( s[ i ]) ;
		}
		else
		{
			return false ;
		}
	}
	
	return true ;
}

string int2str( unsigned long long int num, int base )
{
	string	str ;
	do
	{
		str.insert( 0, 1, int2char( num % base ) ) ;
		num /= base ;
	} while( num != 0 ) ;
	
	return str ;
}

int main()
{
	int		m = 0 ;
	int		n = 0 ;
	string	origin ;
	
	while( cin >> m >> n >> origin )
	{
		unsigned long long int	num = 0 ;
		string	converted ;
		
		if( str2int( origin, m, num ) == true )
		{
			cout << origin << " base " << m << " = " << int2str( num, n ) << " base " << n << endl ;
		}
		else
		{
			cout << origin << " is an illegal base " << m << " number" << endl ;
		}
	}
	
	return 0 ;
}
