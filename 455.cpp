#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>

int
Periodic_Strings( const char *buffer )
{
	int repetitions = 0 ;
	int Period = 0 ;
	int i = 0 ; // loop counter
	const int lenBuffer = strlen( buffer ) ;
	char subString[ lenBuffer + 1 ] ;

	for( Period = 1 ; Period * Period < lenBuffer ; Period++ )
	{
		if( lenBuffer % Period == 0 )
		{
			strncpy( subString, buffer, Period ) ;
			subString[ Period ] = '\0' ;
			for( i = 0 ; i < lenBuffer ; i += Period )
			{
				if( strncmp( buffer + i, subString, Period ) != 0 )
				// Compare buffer with the subString.
				// If subString is not the same as (buffer+i), this is not
				// a peroid substring of buffer.
				{
					break ;
				}
			}

			if( i == lenBuffer )
			// Now, subString is a substring of buffer(Also, the smallest!!).
			{
				return Period ;
			}
		}
	}

	for( repetitions = 2 ; repetitions * repetitions <= lenBuffer ; repetitions++ )
	{
		if( lenBuffer % repetitions == 0 )
		{
			Period = lenBuffer / repetitions ;
			strncpy( subString, buffer, Period ) ;
			subString[ Period ] = '\0' ;
			for( i = 0 ; i < lenBuffer ; i += Period )
			{
				if( strncmp( buffer + i, subString, Period ) != 0 )
				// Compare buffer with the subString.
				// If subString is not the same as (buffer+i), this is not
				// a peroid substring of buffer.
				{
					break ;
				}
			}

			if( i == lenBuffer ) // Now, subString is a substring of buffer.
			{
				return Periodic_Strings( subString ) ;
				// Keep on finding the smallest period of the input string.
			}
		}
	}

	return lenBuffer ;
	// If period can't be find on above two loops, that means the smallest 
	// period of the input string is itself.
}

int
main()
{
	int N = 0 ;
	int i = 0 ; // loop counter
	char buffer[ 100 ] ;

	cin >> N ;

	for( i = 1 ; i <= N ; i++ )
	{
		if( i > 1 )
		{
			cout << endl ;
		}

		do
		{
			cin.getline( buffer, 100, '\n' ) ;
		}while( strlen(buffer) == 0 );

		cout << Periodic_Strings( buffer ) << endl ;
	}

	return 0 ;
}
