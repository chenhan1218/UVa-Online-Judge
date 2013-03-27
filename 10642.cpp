#include <iostream>
using namespace std ;

int main()
{
	int n ;
	long long int x1 , y1 , x2 , y2 , order1 , order2 , answer ;

	cin >> n ;

	for( int cases = 1 ; cases <= n ; cases++ )
	{
		cin >> x1 >> y1 >> x2 >> y2 ;

		order1 = x1 + y1 + 1 ;
		order1 = order1 * ( order1 + 1 ) / 2 - y1 ;

		order2 = x2 + y2 + 1 ;
		order2 = order2 * ( order2 + 1 ) / 2 - y2 ;

		answer = order2 - order1 ;

		cout << "Case " << cases << ": " << answer << endl ;
	}

	return 0 ;
}
