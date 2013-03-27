#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstdlib>
#include <cstring>

#define MaxN 1000000
#define bufferlength 4000000

int		permutation[ MaxN + 1 ] ;
char*	place[ MaxN + 1 ] ;
char	buffer[ bufferlength ] ;

int main()
{
	int		cases = 0 ;
	int		n = 0 ;
	char*	tokenPtr ;
	char*	storePlace ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cin >> cases ;

	for( i = 1 ; i <= cases ; i++ )
	{
		if( i > 1 )
		{
			cout << endl ;
			//The outputs of two consecutive cases will be separated by a blank line.
		}

		cin.getline( buffer, bufferlength ) ; // absorb the blank line.
		cin.getline( buffer, bufferlength ) ; // absorb the blank line.
		cin.getline( buffer, bufferlength ) ;

		n = 0 ;
		tokenPtr = strtok( buffer, " " ) ;
		while( tokenPtr != NULL )
		{
			n++ ;
			permutation[ n ] = atoi( tokenPtr ) ;

			tokenPtr = strtok( NULL, " " ) ;
		}

		storePlace = buffer ;
		for( j = 1 ; j <= n ; j++ )
		{
			cin >> storePlace ; // Read in the number.
			place[ permutation[ j ] ] = storePlace ; // Store the place of the number.
			storePlace = storePlace + strlen( storePlace ) + 1 ;
		}

		for( j = 1 ; j <= n ; j++ )
		{
			cout << place[ j ] << endl ;
		}
	}

	return 0 ;
}
