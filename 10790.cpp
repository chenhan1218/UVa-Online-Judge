#include <iostream>
using namespace std ;

int main()
{
	long long int a, b ;
	long long int answer ;
	int cases = 0 ;

	while( cin >> a >> b )
	{
		if( a == 0 && b == 0 )
		{
			break ;
		}
		cases++ ;

		answer = a * ( a - 1 ) * b * ( b - 1 ) / 4 ;

		cout << "Case " << cases << ": "<< answer << endl ;
	}

	return 0 ;
}
