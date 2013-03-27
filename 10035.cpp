#include <iostream>
using namespace std ;

int main()
{
	long long int a , b ;

	long int carry = 0 ;

	int remainder , remainder_a , remainder_b ;

	while( cin >> a >> b )
	{
		if( a != 0 || b != 0 )
		{
			carry = 0 ;
			remainder = 0 ;

			while( ( a != 0 && b != 0 ) || remainder != 0 )
			{
				remainder_a = a % 10 ;
				remainder_b = b % 10 ;
				remainder += remainder_a + remainder_b ;

				if( remainder >= 10 )
				{
					carry++ ;
					remainder = remainder / 10 ;
				}
				else
				{
					remainder = 0 ;
				}

				a = a / 10 ;
				b = b / 10 ;
			}

			if( carry == 0 )
			{
				cout << "No carry operation." << endl ;
			}
			else if( carry > 1 )
			{
				cout << carry << " carry operations." << endl ;
			}
			else
			{
				cout << carry << " carry operation." << endl ;
			}
		}
		else
		{
			break ;
		}
	}

	return 0 ;
}
