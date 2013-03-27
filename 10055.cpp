#include <iostream>
using namespace std ;

int main()
{
	long long int a , b ;
	long long int answer ;

	while( cin >> a >> b )
	{
		if( ( answer = a - b ) > 0 )
		{
			cout << answer << endl ;
		}
		else
		{
			cout << (-1) * answer << endl ;
		}
	}

	return 0 ;
}
