// Solution is from http://episte.math.ntu.edu.tw/articles/sm/sm_01_01_2/page6.html

#include <iostream>
#include <iomanip>
using namespace std ;

int
main()
{
	int		n1 = 5544 ;	// solution under x=1(mod23), x=0(mod28) and x=0(mod33)
	int		n2 = 14421 ;	// solution under x=0(mod23), x=1(mod28) and x=0(mod33)
	int		n3 = 1288 ;	// solution under x=0(mod23), x=0(mod28) and x=1(mod33)
	int		lcm = 21252 ;	// lcm of 23, 28, and 33
	int		a1 = 0 ;
	int		a2 = 0 ;
	int		a3 = 0 ;
	int		d = 0 ;
	int		cases = 0 ;
	int		answer = 0 ;

	while( cin >> a1 >> a2 >> a3 >> d )
	{
		if( a1 == -1 && a2 == -1 && a3 == -1 && d == -1 )
		{
			break ;
		}

		cases++ ;

		answer = ( a1 * n1 + a2 * n2 + a3 * n3 - d ) % lcm ;

		if( answer <= 0 )
		{
			answer += lcm ;
		}

		cout 	<< "Case " << cases << ": the next triple peak occurs in "
				<< answer << " days." << endl ;
	}

	return 0 ;
}
