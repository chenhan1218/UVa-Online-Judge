#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define TRUE 1
#define FALSE 0
#define Max_T 2001
#define Max_n 2004

int			previous[ Max_n + 1 ] ;
int			next[ Max_n + 1 ] ;

void remove( int x )
{
	next[ previous[ x ] ] = next[ x ] ;
	previous[ next[ x ] ] = previous[ x ] ;

	previous[ x ] = 0 ;
	next[ x ] = 0 ;
}

void sieve( long long int n )
{
	long long int	prime = 0 ;
	long long int	fact = 0 ;
	long long int	mult = 0 ;
	long long int	i = 0 ; // loop counter

	previous[ 2 ] = 0 ;
	next[ 2 ] = 3 ;
	previous[ 3 ] = 2 ;
	next[ 3 ] = 5 ;
	for( i = 3 ; i <= n ; i += 2 )
	{
		previous[ i ] = i - 2 ;
		next[ i ] = i + 2 ;
	}
	next[ i - 2 ] = 0 ;

	for( i = 4 ; i <= n ; i+= 2 )
	{
		previous[ i ] = 0 ;
		next[ i ] = 0 ;
	}

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

}

int
main()
{
	int		T = 0 ;
	int		frequency = 0 ;
	char	line[ Max_T + 1 ] ;
	int		lenLine = 0 ;
	bool	empty ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	sieve( Max_n ) ;

	cin >> T ;
	cin.getline( line, Max_T + 1 ) ; // absorb the first line.
	for( i = 1 ; i <= T ; i++ )
	{
		cout << "Case " << i << ": " ;

		cin.getline( line, Max_T + 1 ) ;
		lenLine = strlen(line) ;
		sort( line, line + lenLine ) ;

		// Now we deal with the fronest character.
		empty = TRUE ;
		frequency = 1 ;
		for( j = 1 ; j <= lenLine ; j++ )
		{
			if( line[ j ] == line[ j - 1 ] )
			{
				frequency++ ;
			}
			else
			{
				if( next[ frequency ] != 0 )
				{
					// It's frequency is a prime number.
					cout << line[ j - 1 ] ;
					empty = FALSE ;
				}

				// Set frequency for line[ j ]
				frequency = 1 ;
			}
		}

		if( empty == TRUE )
		{
			cout << "empty" ;
		}

		cout << endl ;
	}

	return 0 ;
}
