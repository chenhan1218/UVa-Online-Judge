#include <iostream>
#include <iomanip>
using namespace std ;

int
main()
{
	unsigned int	a = 0 ;
	unsigned int	b = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> a >> b )
	{
		cout << ( a ^ b ) << endl ;
	}

	return 0 ;
}
