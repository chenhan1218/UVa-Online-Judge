/*There may be 0 or 1 (special cases) in the judge's test data. It may cause your program run into infinite loop. It cause my program WA for many times.

Finally get AC and find the program run quite fast.

D ------> last digit
X ------> digits before D

if X is only one digit then

(X * base + D) * factor = D * base + X;
X = (D * base - D * factor) / (base * factor - 1);//if "/" makes an integer answer should be 2

if X is two than one digit then

(X * base + D) * factor = D * base * base + X;
X = (D * base * base - D * factor) / (base * factor - 1); // if "/" makes an integer answer should be 3

.......*/

#include <iostream>
#include <iomanip>

using namespace std ;

int
main()
{
	int	remainderOfDFactor = 0 ;
	int	remainderOfDBases = 0 ;
	int numbersOfDigits = 0 ;
	int	lastDigit = 0 ;
	int	base = 0 ;
	int factor = 0 ;

	while( cin >> base >> lastDigit >> factor )
	{
		if( lastDigit == 0 )
		{
			cout << 1 << endl ;
		}
		else
		{
			numbersOfDigits = 1 ;
			remainderOfDFactor = ( lastDigit * factor ) % (base * factor - 1) ;
			remainderOfDBases = lastDigit % (base * factor - 1) ;

			while( remainderOfDBases != remainderOfDFactor )
			{
				numbersOfDigits++ ;
				remainderOfDBases = ( remainderOfDBases * base ) % 
					(base * factor - 1) ;
			}

			cout << numbersOfDigits << endl ;
		}
	}

	return 0 ;
}
