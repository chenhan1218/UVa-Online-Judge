#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>
#include <cstdlib>

#define MaxCharacters 255
#define MaxS 100

bool cmp( int *timedataA, int *timedataB )
{
	if( timedataA[ 0 ] != timedataB[ 0 ] )
	{
		return timedataA[ 0 ] < timedataB[ 0 ] ;
	}
	else if( timedataA[ 1 ] != timedataB[ 1 ] )
	{
		return timedataA[ 1 ] < timedataB[ 1 ] ;
	}
	else if( timedataA[ 2 ] != timedataB[ 2 ] )
	{
		return timedataA[ 2 ] < timedataB[ 2 ] ;
	}
	else
	{
		return timedataA[ 3 ] < timedataB[ 3 ] ;
	}
}

int
main()
{
	int		day = 0 ;
	int**	timedata = NULL ;
	char	line[ MaxCharacters + 1 ] ;
	char	buffer[ 30 ] ;
	int		nap[ MaxS + 3 ] ;
	int		s = 0 ;
	int		numLargestNap = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	timedata = new int *[ MaxS + 3 ] ;
	for( i = 1 ; i <= MaxS + 2 ; i++ )
	{
		timedata[ i ] = new int[ 4 ] ;
	}

	while( cin.getline( buffer, 30 ) )
	{
		day++ ;
		s = atoi( buffer ) ;

		for( i = 1 ; i <= s ; i++ )
		{
			cin.getline( line, MaxCharacters + 1 ) ;

			timedata[ i ][ 0 ] = atoi( line ) ;
			timedata[ i ][ 1 ] = atoi( line + 3 ) ;
			timedata[ i ][ 2 ] = atoi( line + 6 ) ;
			timedata[ i ][ 3 ] = atoi( line + 9 ) ;
		}

		timedata[ s + 1 ][ 0 ] = 10 ;
		timedata[ s + 1 ][ 1 ] = 0 ;
		timedata[ s + 1 ][ 2 ] = 10 ;
		timedata[ s + 1 ][ 3 ] = 0 ;
		timedata[ s + 2 ][ 0 ] = 18 ;
		timedata[ s + 2 ][ 1 ] = 0 ;
		timedata[ s + 2 ][ 2 ] = 18 ;
		timedata[ s + 2 ][ 3 ] = 0 ;

		sort( &timedata[ 1 ], &timedata[ 1 ] + s + 2, cmp ) ;

		for( i = 1 ; i <= s + 1 ; i++ )
		{
			nap[ i ] = ( timedata[ i + 1 ][ 0 ] - timedata[ i ][ 2 ] ) * 60 + 
						( timedata[ i + 1 ][ 1 ] - timedata[ i ][ 3 ] ) ;
		}

		// find the largest nap
		numLargestNap = 1 ;
		for( i = 2 ; i <= s + 1 ; i++ )
		{
			if( nap[ i ] > nap[ numLargestNap ] )
			{
				numLargestNap = i ;
			}
		}

		if( nap[ numLargestNap ] >= 60 )
		{
			cout 	<< "Day #" << day << ": the longest nap starts at " 
					<< setw( 2 ) << setfill('0') << timedata[ numLargestNap ][ 2 ] << ":" 
					<< setw( 2 ) << setfill('0') << timedata[ numLargestNap ][ 3 ] 
					<< " and will last for " << nap[ numLargestNap ] / 60 
					<< " hours and " << nap[ numLargestNap ] % 60 
					<< " minutes." << endl ;
		}
		else
		{
			cout 	<< "Day #" << day << ": the longest nap starts at " 
					<< setw( 2 ) << setfill('0') << timedata[ numLargestNap ][ 2 ] << ":" 
					<< setw( 2 ) << setfill('0') << timedata[ numLargestNap ][ 3 ] 
					<< " and will last for " << nap[ numLargestNap ] 
					<< " minutes." << endl ;
		}
	}

	return 0 ;
}
