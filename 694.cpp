#include <iostream>
using namespace std ;

int main()
{
	long long int A , L , dealing_A , cases = 0 , terms , before_L ;

	while( cin >> A >> L )
	{
		if( A < 0 && L < 0 )
		{
			break ;
		}

		dealing_A = A ;
		cases++ ;
		terms = 1 ;
		before_L = ( L - 1 ) / 3 ;

		while( dealing_A != 1 )
		{
			if( dealing_A % 2 == 0 )
			{
				terms++ ;

				dealing_A /= 2 ;
			}
			else
			{
				if( dealing_A <= before_L )
				{
					terms++ ;

					dealing_A = 3 * dealing_A + 1 ;
				}
				else
				{
					break ;
				}
			}
		}

		cout << "Case " << cases << ": A = " << A << ", limit = " 
			<< L << ", number of terms = " << terms << endl ;
	}

	return 0 ;
}
