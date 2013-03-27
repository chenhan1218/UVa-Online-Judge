#include <iostream>
#include <iomanip>
using namespace std ;

#include <cstdlib>
#include <cstring>

#define MaxLength 1000000

int
main()
{
	int				i = 0 ; // loop counter
	char			linePoly[ MaxLength ] ;
	char*			tokenPtr ;
	long long int	x = 0 ;
	long long int	DPx = 0 ;
	long long int	Px = 0 ;

	while( cin >> x )
	{
		cin.get() ; //absorb the character '\n'
		cin.getline( linePoly, MaxLength ) ;

		DPx = 0 ;
		Px = 0 ;
		tokenPtr = strtok( linePoly, " " ) ;
		while( tokenPtr != NULL )
		{
			DPx = Px + x * DPx ;
			Px = Px * x + atoi( tokenPtr ) ;

			tokenPtr = strtok( NULL, " " ) ;
		}

		cout << DPx << endl ;
	}

	return 0 ;
}
