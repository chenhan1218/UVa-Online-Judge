#include <iostream>
#include <string>
using namespace std ;

#define MaxM 7776
#define MaxQ 50

int main()
{
	int		numColumn = 0 ;
	int		y1 = 0 ;
	int		y2 = 0 ;
	int		diff = 0 ;
	bool	firstCase = true ;
	bool	closable = false ;
	int		testcase = 0 ;
	int		i = 0 ;
	int		j = 0 ;

	cin >> testcase ;

	while( testcase > 0 )
	{
		testcase-- ;

		cin >> numColumn ;
		if( numColumn < 0 )
			closable = false ;
		else if( numColumn == 0 )
		{
			closable = true ;
		}
		else
		{
			cin >> y1 >> y2 ;
			diff = y1 - y2 ;

			closable = true ;

			for( i = 2 ; i <= numColumn ; i++ )
			{
				cin >> y1 >> y2 ;

				if( diff != y1 - y2 )
					closable = false ;
			}
		}

		if( firstCase == true )
			firstCase = false ;
		else
			cout << endl ;

		if( closable == false )
			cout << "no" << endl ;
		else
			cout << "yes" << endl ;
	}

	return 0 ;
}

