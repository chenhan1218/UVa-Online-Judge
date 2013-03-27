#include <iostream>
using namespace std ;

int main()
{
	long long int N ;

	while( cin >> N )
	{
		if( N == 0 )
		{
			break ;
		}

		if( N <= 100 )
		{
			cout << "f91(" << N << ") = " << "91" << endl ;
		}
		else
		{
			cout << "f91(" << N << ") = " ;
			N -= 10 ;
			cout  << N << endl ;
		}
	}

	return 0 ;
}
