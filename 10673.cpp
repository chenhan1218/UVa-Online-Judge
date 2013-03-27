#include <iostream>
using namespace std ;

int main()
{
	int T , x , k , p , q ;
	cin >> T ;

	for( int i = 1 ; i <= T ; i++ )
	{
		cin >> x >> k ;

		q = x % k ;
		p = k - q ;

		cout << p << " " << q << endl ;
	}

	return 0 ;
}
