#include <iostream>
#include <iomanip>
using namespace std ;

#define MAX_n 200

int		correspondingNumber[ MAX_n + 1 ] ;
int		cycle[ MAX_n + 1 ] ;

void setCycle( int n )
{
	int		cycleCounter = 0 ;
	int		visitedNumber = 0 ;
	int		i = 0 ; // loop counter

	for( i = 1 ; i <= n ; i++ )
	{
		cycle[ i ] = 0 ;
	}

	for( i = 1 ; i <= n ; i++ )
	{
		if( cycle[ i ] == 0 )
		{
			cycleCounter = 1 ;
			visitedNumber = correspondingNumber[ i ] ;

			while( visitedNumber != i )
			{
				cycleCounter++ ;
				visitedNumber = correspondingNumber[ visitedNumber ] ;
			}

			cycle[ i ] = cycleCounter ;
			visitedNumber = correspondingNumber[ i ] ;
			while( visitedNumber != i )
			{
				cycle[ i ] = cycleCounter ;
				visitedNumber = correspondingNumber[ visitedNumber ] ;
			}
		}
	}
}

void addSpaces( char *message, int n )
{
	int i = 0 ; // loop counter ;

	for( i = strlen( message ) ; i < n ; i++  )
	{
		message[ i ] = ' ' ;
	}

	message[ n ] = '\0' ;
}

int position( int i, int k )
{
	int		currentPosition = i ;

	k = k % cycle[ i ] ;
	while( k > 0 )
	{
		currentPosition = correspondingNumber[ currentPosition ] ;
		k-- ;
	}

	return currentPosition ;
}

void encode( char *message, int n , int k )
{
	char	encodedMessage[ n + 1 ] ;
	int		i = 0 ; // loop counter

	for( i = 1 ; i <= n ; i++ )
	{
		encodedMessage[ position( i, k ) - 1 ] = message[ i - 1 ] ;
	}
	encodedMessage[ n ] = '\0' ;

	strcpy( message, encodedMessage ) ;
}

int
main()
{
	int		n = 0 ;
	int		k = 0 ;
	char	message[ MAX_n + 1 ] ;
	int		i = 0 ; //loop counter
	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}

		for( i = 1 ; i <= n ; i++ )
		{
			cin >> correspondingNumber[ i ] ;
		}
		setCycle( n ) ;

		while( cin >> k )
		{
			if( k == 0 )
			{
				break ;
			}

			cin.get() ; // absorb space
			cin.getline( message, MAX_n + 1, '\n' ) ;

			addSpaces( message, n ) ;
			// spaces are added to the end of the message to get the 
			// message with the length n.

			encode( message, n , k ) ;

			cout << message << endl ;
		}

		cout << endl ;
	}

	return 0 ;
}
