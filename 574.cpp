#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

int		type = 0 ;
int		x[ 13 ] = { 0 } ;
int		repeat[ 13 ] = { 0 } ;
int		timesType[ 13 ] = { 0 } ;
int		distinct = 0 ;

void findSolution( int remainSum, int layer )
{
	int		i = 0 ;
	int		j = 0 ;
	timesType[ layer ] = min( remainSum / x[ layer ], repeat[ layer ] ) ;
	remainSum -= x[ layer ] * timesType[ layer ] ;
	if( remainSum == 0 )
	{
		// print the result
		distinct ++ ;
		for( i = 1 ; i < layer ; i++ )
		{
				for( j = 1 ; j <= timesType[ i ] ; j++ )
			{
				cout << x[ i ] << "+" ;
			}
		}
		for( j = 1 ; j < timesType[ i ] ; j++ )
		{
			cout << x[ layer ] << "+" ;
		}
		cout << x[ layer ] << endl ;
	}

	// If we can keep going on.
	if( layer < type )
	{
		if( remainSum == 0 )
		{
			timesType[ layer ] -= 1 ;
			remainSum += x[ layer ] ;
		}

		for( ; 
			timesType[ layer ] >= 0 ; 
			timesType[ layer ] -= 1, remainSum += x[ layer ] )
		{
			findSolution( remainSum, layer + 1 ) ;
		}
	}

	// set timesType[ layer ] to 0.
	// ready for next usage.
	timesType[ layer ] = 0 ;
}

int
main()
{
	int		t = 0 ;
	int		n = 0 ;
	int		number[ 12 ] ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> t >> n )
	{
		if( t == 0 && n == 0 )
		{
			break ;
		}

		for( i = 0 ; i < n ; i++ )
		{
			cin >> number[ i ] ;
		}

		sort( number, number + n ) ;

		// find repeat of number.
		type = 1 ;
		x[ type ] = number[ n - 1 ] ;
		repeat[ type ] = 1 ;
		for( i = n - 2 ; i >= 0 ; i-- )
		{
			if( number[ i ] == number[ i + 1 ] )
			{
				repeat[ type ] += 1 ;
			}
			else
			{
				type++ ;
				x[ type ] = number[ i ] ;
				repeat[ type ] = 1 ;
			}
		}


		cout << "Sums of " << t << ":" << endl ;
		distinct = 0 ;
		findSolution( t, 1 ) ;

		if( distinct == 0 )
		{
			cout << "NONE" << endl ;
		}
	}

	return 0 ;
}
