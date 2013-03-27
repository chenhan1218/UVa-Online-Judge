// The testdata contains some space, we must handle it.
#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

int lenDigits( long long int a )
{
	int	 i = 1 ;
	while( a > 10 )
	{
		i++ ;
		a /= 10 ;
	}

	return i ;
}

int
main()
{
	long long int		maxOperand0 = 0 ;
	long long int		maxOperand1 = 0 ;
	long long int		minOperand0 = 0 ;
	long long int		minOperand1 = 0 ;
	long long int		operand2 = 0 ;
	char	op ;
	long long int		max = 0 ;
	long long int		min = 0 ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cin >> cases ;
	for( i = 1 ; i <= cases ; i++ )
	{
		cin >> operand2 ;

		maxOperand0 = 1 ;
		maxOperand1 = operand2 ;
		minOperand0 = 0 ;
		minOperand1 = operand2 ;
		
		while( cin >> op )
		{
			if( op != '*' && op != '+' )
			{
				ungetc( op, stdin ) ;
				break ;
			}
			cin >> operand2 ;

			if( op == '+' )
			{
				maxOperand1 += operand2 ;

				minOperand0 += minOperand1 ;
				minOperand1 = operand2 ;
			}
			else
			{
				maxOperand0 *= maxOperand1 ;
				maxOperand1 = operand2 ;

				minOperand1 *= operand2 ;
			}
		}

		max = maxOperand0 * maxOperand1 ;
		min = minOperand0 + minOperand1 ;
		cout << "The maximum and minimum are " << max << " and " << min << "." << endl ;
	}

	return 0 ;
}
