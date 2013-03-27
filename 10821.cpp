// Note that In this problem, you have to find the order of 1 to N integers 
// such that the BST constructed by them has height of "AT MOST" H.
#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxH 30

int		pow2s_1[ MaxH + 1 ] = { 0 } ;

void trace( int N, int H, int base )
{
	if( N > pow2s_1[ H ] )
	{
		cout << " Impossible." ;
	}
	else
	{
		if( N == 1 )
		{
			cout << " " << 1 + base ;
		}
		else if( N > pow2s_1[ H - 1 ] + 1 )
		{
			cout << " " << N - pow2s_1[ H - 1 ] + base ;
			trace( N - ( pow2s_1[ H - 1 ] + 1 ), 
				min( H - 1, N - ( pow2s_1[ H - 1 ] + 1 ) ), base ) ;
			trace( pow2s_1[ H - 1 ] , H - 1, N - pow2s_1[ H - 1 ] + base ) ;
		}
		else
		{
			cout << " " << 1 + base ;
			trace( N - 1 , H - 1, 1 + base ) ;
		}
	}
}

int
main()
{
	int		N = 0 ;
	int		H = 0 ;
	int		cases = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	pow2s_1[ 0 ] = 0 ;
	for( i = 1 ; i <= MaxH ; i++ )
	{
		pow2s_1[ i ] = pow2s_1[ i - 1 ] * 2 + 1 ;
	}

	while( cin >> N >> H )
	{
		if( N == 0 && H == 0 )
		{
			break ;
		}
		cases++ ;

		cout << "Case " << cases << ":" ;
		trace( N, H, 0 ) ;
		cout << endl ;
	}

	return 0 ;
}

