#include <iostream>
using namespace std ;

int main()
{
	long long int a , b , temp , quotient , total_times ;

	while( cin >> a >> b )
	{
		if( a == 0 ||  b == 0 )
		{
			break ;
		}

		total_times = 0 ;
		while( ( temp = a % b ) != 0 )
		{
			quotient = a / b ;

			if( quotient > 1 )
			{
				break ;
			}
			else
			{
				/* If quotient = 0, a < b ,so there is no play times. */
				/* If quotient = 1, there is one play time. */
				total_times += quotient ;
			}

			a = b ;
			b = temp ;
		}

		if( total_times % 2 == 0 )
		{
			cout << "Stan wins" << endl ;
		}
		else
		{
			cout << "Ollie wins" << endl ;
		}
	}

	return 0 ;
}
