#include <iostream>
#include <string>
#include <map>
using namespace std ;

map<char,char> m ;

bool isPalinDrome( string a )
{
	int		i = 0 ;
	for( i = 0 ; i < a.size() / 2 ; i++ )
	{
		if( a[ i ] != a[ a.size() - i - 1 ] )
			break ;
	}
	
	if( i < a.size() / 2 )
		return false ;
	else
		return true ;
}

bool isMirrored( string a )
{
	int		i = 0 ;
	for( i = 0 ; i <= a.size() / 2 ; i++ )
	{
		if( m[ a[ i ] ] != a[ a.size() - i - 1 ] )
			break ;
	}
	
	if( i <= a.size() / 2 )
		return false ;
	else
		return true ;
}

int main()
{
	string	input ;
	int		i = 0 ;
	
	m[ 'A' ] = 'A' ;
	m[ 'E' ] = '3' ;
	m[ 'H' ] = 'H' ;
	m[ 'I' ] = 'I' ;
	m[ 'J' ] = 'L' ;
	m[ 'L' ] = 'J' ;
	m[ 'M' ] = 'M' ;
	m[ 'O' ] = 'O' ;
	m[ 'S' ] = '2' ;
	m[ 'T' ] = 'T' ;
	m[ 'U' ] = 'U' ;
	m[ 'V' ] = 'V' ;
	m[ 'W' ] = 'W' ;
	m[ 'X' ] = 'X' ;
	m[ 'Y' ] = 'Y' ;
	m[ 'Z' ] = '5' ;
	m[ '1' ] = '1' ;
	m[ '2' ] = 'S' ;
	m[ '3' ] = 'E' ;
	m[ '5' ] = 'Z' ;
	m[ '8' ] = '8' ;

	while( cin >> input )
	{
		cout << input ;
		if( isPalinDrome( input ) == true )
		{
			if( isMirrored( input ) == true )
			{
				cout << " -- is a mirrored palindrome." ;
			}
			else
			{
				cout << " -- is a regular palindrome." ;
			}
		}
		else
		{
			if( isMirrored( input ) == true )
			{
				cout << " -- is a mirrored string." ;
			}
			else
			{
				cout << " -- is not a palindrome." ;
			}
		}
		
		cout << endl ;
		//In addition, after each output line, you must print an empty line.
		cout << endl ;
	}
	
	return 0 ;
}
