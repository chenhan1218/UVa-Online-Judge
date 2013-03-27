#include <iostream>
#include <iomanip>
using namespace std ;

int
main()
{
	int		V = 0 ;
	int		V0 = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> V >> V0 )
	{
		if( V == 0 && V0 == 0 )
		{
			break ;
		}

		//The number we should return is the integer closest to V / ( 2V0 ).
		//But if the number is as N+0.5, this number is not unique, and we have 
		//to output 0.
		if( ( V+V0 ) % ( 2*V0 ) == 0 )
		{
			cout << 0 << endl ;
		}
		else
		{
			cout << (int)( (double)( V + V0 ) / ( 2.0 * V0 ) ) << endl ;
		}
	}

	return 0 ;
}
