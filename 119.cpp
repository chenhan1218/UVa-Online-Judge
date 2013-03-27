#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>
#include <string>

#define MaxPeople 10

string list[ MaxPeople ] ;
int		gain[ MaxPeople ] ;

int
main()
{
	int		firstCase = 0 ;
	int		num = 0 ;
	string	giver ;
	int		serialGiver ;
	int		spent = 0 ;
	int		numReceiver = 0 ;
	int		division = 0 ;
	string	receiver ;
	int		serialReceiver ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	firstCase = 1 ;
	while( cin >> num )
	{
		for( i = 0 ; i < num ; i++ )
		{
			cin >> list[ i ] ;
			gain[ i ] = 0 ;
		}

		for( i = 0 ; i < num ; i++ )
		{
			cin >> giver >> spent >> numReceiver ;
			if( numReceiver == 0 )
			{
				continue ;
			}

			serialGiver = find( list, list + num, giver ) - list ;
			division = spent / numReceiver ;

			gain[ serialGiver ] -= division * numReceiver ;

			for( j = 1 ; j <= numReceiver ; j++ )
			{
				cin >> receiver ;
				serialReceiver = find( list, list + num, receiver ) - list ;

				gain[ serialReceiver ] += division ;
			}
		}

		if( firstCase == 0 )
		{
			cout << endl ;
		}
		else
		{
			firstCase = 0 ;
		}

		for( i = 0 ; i < num ; i++ )
		{
			cout << list[ i ] << " " << gain[ i ] << endl ;
		}
	}

	return 0 ;
}
