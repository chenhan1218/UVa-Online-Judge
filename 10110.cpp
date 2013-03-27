#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	long long int n , temp ;

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}
		else
		{
			temp = static_cast<int>( pow( n , 0.5 ) ) ;

			if( temp * temp == n )
			{
				cout << "yes" << endl ;
			}
			else
			{
				cout << "no" << endl ;
			}
		}
	}

	return 0 ;
}
