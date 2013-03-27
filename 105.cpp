#include <iostream>
#include <iomanip>
using namespace std ;
#define MaxCordinate 10000

int		height[ MaxCordinate + 1 ] = { 0 } ;

int main()
{
	int		L = 0, H = 0, R = 0 ;
	int		smallest = 0 ;
	int		largest = 0 ;
	int		i = 0 ;
	int		j = 0 ;

	cin >> L >> H >> R ;
	smallest = L ;
	largest = R ;
	for( i = L - smallest ; i < R - smallest ; i++ )
	{
		if( height[ i ] < H )
		{
			height[ i ] = H ;
		}
	}

	while( cin >> L >> H >> R )
	{
		if( H > 0 )
		{
			if( R > largest )
			{
				largest = R ;
			}
		}

		for( i = L - smallest ; i < R - smallest ; i++ )
		{
			if( height[ i ] < H )
			{
				height[ i ] = H ;
			}
		}
	}

	cout << smallest << " " << height[ 0 ] ;
	for( i = 1 ; i <= largest - smallest ; i++ )
	{
		if( height[ i ] != height[ i - 1 ] )
		{
			cout << " " << i + smallest << " " << height[ i ] ;
		}
	}
	cout << endl ;

	return 0 ;
}
