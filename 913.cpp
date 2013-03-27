#include <iostream>
#include <iomanip>
using namespace std ;

int
main()
{
	long long	N = 0 ;
	long long	Nplus1 = 0 ;

	while( cin >> N )
	{
		Nplus1 = N + 1 ;

		cout << 3 * Nplus1 * Nplus1 / 2 - 9 << endl ;
	}

	return 0 ;
}
