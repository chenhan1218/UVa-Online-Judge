#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

bool valid( string a )
{
	int		i = 0 ; // loop counter
	for( i = 1 ; i < a.size() ; i++ )
	{
		if( a[ i - 1 ] >= a[ i ] )
		{
			return false ;
		}
	}

	return true ;
}

int	c( int a, int b )
{
	int		answer = 1 ;
	int		i = 0 ; // loop counter

	for( i = 1 ; i <= b ; i++ )
	{
		answer = answer * (a - i + 1) / i ;
	}

	return answer ;
}

int
main()
{
	string	word ;
	int		answer = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> word )
	{
		if( valid( word ) == true )
		{
			answer = 0 ;
			for( i = 1 ; i < word.size() ; i++ )
			{
				answer += c( 26, i ) ;
			}

			for( i = 1 ; i <= word[ 0 ] - 'a' ; i++ )
			{
				answer += c( 26 - i, word.size() - 1 ) ;
			}

			for( i = 1 ; i < word.size() ; i++ )
			{
				for( j = 1 ; j < word[ i ] - word[ i - 1 ] ; j++ )
				{
					answer += c( 26 - ( word[ i - 1 ] - 'a' + 1 ) - j, 
									word.size() - ( i + 1 ) ) ;
				}
			}

			answer ++ ;
			cout << answer << endl ;
		}
		else
		{
			cout << 0 << endl ;
		}
	}

	return 0 ;
}
