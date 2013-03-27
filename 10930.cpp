#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define True 1
#define False 0
#define MaxD 30
#define MaxInteger 1000

int
main()
{
	int		D = 0 ;
	int		seq[ MaxD + 1 ] = { 0 } ;
	bool	sum[ MaxInteger * MaxD + 1 ] = { 0 } ;
	int		sumSeq = 0 ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	for( cases = 1 ; cin >> D ; cases++ )
	{
		for( i = 1 ; i <= D ; i++ )
		{
			cin >> seq[ i ] ;
		}

		sumSeq = 0 ;
		for( j = 1 ; j <= MaxInteger * D ; j++ )
		{
			sum[ j ] = False ;
		}

		for( i = 1 ; i < D ; i++ )
		{
			if( seq[ i ] <= seq[ i - 1 ] || sum[ seq[ i ] ] == True )
			{
				break ;
			}

			for( j = sumSeq ; j >= seq[ 1 ] ; j-- )
			{
				if( sum[ j ] == True )
				{
					sum[ seq[ i ] + j ] = True ;
				}
			}
			sum[ seq[ i ] ] = True ;
			sumSeq += seq[ i ] ;
		}

		if( i < D )
		{
				cout << "Case #" << cases << ":" ;
				for( i = 1 ; i <= D ; i++ )
				{
					cout << " " << seq[ i ] ;
				}
				cout << endl ;
				cout << "This is not an A-sequence." << endl ;
		}
		else
		{
			if( seq[ D ] <= seq[ D - 1 ] || sum[ seq[ D ] ] == True )
			{
				cout << "Case #" << cases << ":" ;
				for( i = 1 ; i <= D ; i++ )
				{
					cout << " " << seq[ i ] ;
				}
				cout << endl ;
				cout << "This is not an A-sequence." << endl ;
			}
			else
			{
				cout << "Case #" << cases << ":" ;
				for( i = 1 ; i <= D ; i++ )
				{
					cout << " " << seq[ i ] ;
				}
				cout << endl ;
				cout << "This is an A-sequence." << endl ;
			}
		}
	}

	return 0 ;
}

