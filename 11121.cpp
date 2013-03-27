#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;

int main()
{
	int		caseNum = 0 ;
	int		n = 0 ;
	string	output ;
	int		i = 0 ;
	
	cin >> caseNum ;
	for( i = 1 ; i <= caseNum ; i++ )
	{
		cin >> n ;
		output.clear() ;

		do
		{
			if( n % (-2) != 0 )
			{
				n = ( n - 1 ) / -2 ;
				output = '1' + output ;
			}
			else
			{
				n /= -2 ;
				output = '0' + output ;
			}
		} while( n != 0 ) ;

		cout << "Case #" << i << ": " << output << endl ;
	}

	return 0 ;
}

