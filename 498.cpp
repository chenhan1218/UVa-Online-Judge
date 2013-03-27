#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstring>

#define TRUE 1
#define FALSE 0
#define MaxLength 10000
#define MaxOrder 10000

long long int myAtoi( char *string )
{
	int				i = 0 ; // loop counter
	long long int	returnValue = 0 ;

	if( string[ 0 ] == '-' )
	{
		string++ ;
		for( i = 0 ; string[ i ] != '\0' ; i++ )
		{
			returnValue = returnValue * 10 - ( string[ i ] - '0' ) ;
		}
	}
	else
	{
		for( i = 0 ; string[ i ] != '\0' ; i++ )
		{
			returnValue = returnValue * 10 + ( string[ i ] - '0' ) ;
		}
	}

	return returnValue ;
}

int
main()
{
	int				i = 0 ; // loop counter
	char			line1[ MaxLength ] ;
	char			line2[ MaxLength ] ;
	char*			tokenPtr ;
	long long int	polynomial[ MaxOrder ] ;
	int				order = 0 ;
	long long int	x = 0 ;
	long long int	resultValue = 0 ;
	bool			firstCase = 0 ;

	while( cin.getline( line1, MaxLength ) && cin.getline( line2, MaxLength ) )
	{
		tokenPtr = strtok( line1, " " ) ;
		order = -1 ;
		while( tokenPtr != NULL )
		{
			order++ ;
			polynomial[ order ] = myAtoi( tokenPtr ) ;

			tokenPtr = strtok( NULL, " " ) ;
		}

		firstCase = TRUE ;
		tokenPtr = strtok( line2, " " ) ;
		while( tokenPtr != NULL )
		{
			x = myAtoi( tokenPtr ) ;

			resultValue = polynomial[ 0 ] ;
			for( i = 1 ; i <= order ; i++ )
			{
				resultValue = resultValue * x + polynomial[ i ] ;
			}

			if( firstCase == FALSE )
			{
				cout << " " ;
			}
			else
			{
				firstCase = FALSE ;
			}
			cout << resultValue ;

			tokenPtr = strtok( NULL, " " ) ;
		}

		cout << endl ;
	}

	return 0 ;
}
