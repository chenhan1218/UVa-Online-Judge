#include <iostream>
using namespace::std ;

int main()
{
	long long int n , k ;

	long long butt ;

	while( cin >> n >> k )
	{
		butt = n ;

		while( butt >= k )
		{
			n += butt / k ;
			butt = butt % k + butt / k ;
		}

		cout << n << endl ;
	}

	return 0 ;
}
