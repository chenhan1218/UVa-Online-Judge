#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std ;
#include <sstream>
using std::istringstream ;

#define MaxContestants 100
#define MaxProblem 9

class contestant
{
	public :
		bool	solved[ MaxProblem + 1 ] ;
		int		penalty[ MaxProblem + 1 ] ;
		int		accumu ;
		int		numSolved ;
		int		conNumber ;
		int		submission ;
		void	clear() {
			fill_n( solved + 1, MaxProblem, false ) ;
			fill_n( penalty + 1, MaxProblem, 0 ) ;
			accumu = 0 ;
			numSolved = 0 ;
			conNumber = 0 ;
			submission = 0 ;
		}
};

bool cmp( contestant a, contestant b )
{
	if( a.numSolved != b.numSolved )
	{
		return a.numSolved > b.numSolved ;
	}
	else if( a.accumu != b.accumu )
	{
		return a.accumu < b.accumu ;
	}
	else
	{
		return a.submission > b.submission ;
	}
}

int
main()
{
	contestant	con[ MaxContestants + 1 ] ;
	int		t = 0 ;
	string	buffer ;
	int		contestant = 0 ;
	int		problem = 0 ;
	int		time = 0 ;
	char	L = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	cin >> t ;
	getline( cin, buffer ) ; // absorb
	getline( cin, buffer ) ; // absorb

	for( i = 1 ; i <= t ; i++ )
	{
		// initial
		for( j = 1 ; j <= MaxContestants ; j++ )
		{
			con[ j ].clear() ;
			con[ j ].conNumber = j ;
		}

		while( getline( cin, buffer ) )
		{
			if( buffer == "" )
			{
				break ;
			}

			istringstream is( buffer ) ;
			is >> contestant >> problem >> time >> L ;

			con[ contestant ].submission = 1 ;

			if( con[ contestant ].solved[ problem ] == false )
			{
				if( L == 'C' )
				{
					con[ contestant ].solved[ problem ] = true ;
					con[ contestant ].penalty[ problem ] += time ;
					con[ contestant ].accumu += con[ contestant ].penalty[ problem ] ;
					con[ contestant ].numSolved += 1 ;
				}
				else if( L == 'I' )
				{
					con[ contestant ].penalty[ problem ] += 20 ;
				}
			}
		}

		// don't use stable_sort will cause WA
		stable_sort( con + 1 , con + 1 + MaxContestants, cmp ) ;

		if( i > 1 )
		{
			cout << endl ;
		}
		for( j = 1 ; j <= MaxContestants && con[ j ].submission != 0 ; j++ )
		{
			cout << con[ j ].conNumber << " " << con[ j ].numSolved << " " << con[ j ].accumu << endl ;
		}
	}

	return 0 ;
}
