#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std ;

#define MaxIntersection 500

int		d[ MaxIntersection + 1 ][ MaxIntersection + 1 ] = { 0 } ;
int		nearest[ MaxIntersection + 1 ] = { 0 } ;

int main()
{
	int		f = 0 ;
	int		intersection = 0 ;
	bool	station[ MaxIntersection + 1 ] ;
	string	buffer ;
	istringstream	is ;
	int		a = 0 ;
	int		b = 0 ;
	int		len = 0 ;
	int		selectedStation = 0 ;
	int		maxDist = 0 ;
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ; // loop counter ;
	int		j = 0 ; // loop counter ;
	int		k = 0 ; // loop counter ;
	
	cin >> casenum ;
	
	for( runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		cin >> f >> intersection ;
		fill( station, station + intersection + 1, false ) ;
		for( i = 0 ; i < f ; i++ )
		{
			cin >> a ;
			station[ a ] = true ;
		}
		
		for( i = 1 ; i <= intersection ; i++ )
		{
			fill( d[ i ], d[ i ] + intersection + 1, 99999999 ) ;
			d[ i ][ i ] = 0 ;
		}
		
		getline( cin, buffer ) ; // absorb end of line
		while( getline( cin, buffer ) && buffer != "" )
		{
			is.clear() ;
			is.str( buffer ) ;
			is >> a >> b >> len ;
			d[ a ][ b ] = min( d[ a ][ b ], len ) ;
			d[ b ][ a ] = min( d[ b ][ a ], len ) ;
		}
		
		for( k = 1 ; k <= intersection ; k++ )
		{
			for( i = 1 ; i <= intersection ; i++ )
			{
				for( j = 1 ; j <= intersection ; j++ )
				{
					d[ i ][ j ] = min( d[ i ][ j ], d[ i ][ k ] + d[ k ][ j ] ) ;
				}
			}
		}
		
		for( i = 1 ; i <= intersection ; i++ )
		{
			nearest[ i ] = 99999999 ;
			for( j = 1 ; j <= intersection ; j++ )
			{
				if( station[ j ] == true )
					nearest[ i ] = min( nearest[ i ], d[ i ][ j ] ) ;
			}
		}
		
		selectedStation = 1 ;
		maxDist = *( max_element( nearest + 1, nearest + intersection + 1 ) ) ;
		for( i = 1 ; i <= intersection ; i++ ) // for each intersection that has no fire station, test the result ;
		{
			if( station[ i ] == false ) // there is no fire station at intersection i
			{
				vector<int>	distToNewStation( intersection+1, 0 ) ;
				for( j = 1 ; j <= intersection ; j++ )
					distToNewStation[ j ] = min( d[ j ][ i ], nearest[ j ] ) ;
				
				if( selectedStation == 0 )
				{
					selectedStation = i ;
					maxDist = *( max_element( distToNewStation.begin() + 1, distToNewStation.end() ) ) ;
				}
				else if( *( max_element( distToNewStation.begin() + 1, distToNewStation.end() ) ) < maxDist )
				{
					selectedStation = i ;
					maxDist = *( max_element( distToNewStation.begin() + 1, distToNewStation.end() ) ) ;
				}
			}
		}
		
		if( runningCase != 1 )
		{
			cout << endl ;
		}
		cout << selectedStation << endl ;
	}
	
	return 0 ;
}
