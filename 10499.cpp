#include <iostream>
#include <iomanip>
using namespace std ;

int
main()
{
	long long N ;

	while( cin >> N )
	{
		if( N < 0 )
		{
			break ;
		}

		if( N == 1 )
		{
			cout << "0%" << endl ;
		}
		else
		{
			cout << N * 25 << "%" << endl ;
		}
	}

	return 0 ;
}
