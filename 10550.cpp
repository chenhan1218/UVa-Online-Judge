#include <iostream>
using namespace std ;

int	clockwise( int from, int to, int calibration )
{
	if( to <= from )
	{
		return from - to ;
	}
	else
	{
		return calibration - ( to - from ) ;
	}
}
int	counterClockwise( int from, int to, int calibration )
{
	if( to >= from )
	{
		return to - from ;
	}
	else
	{
		return calibration - ( from - to ) ;
	}
}

int main()
{
	const int calibration = 40 ;
	int		initial = 0 ;
	int		combination[ 3 ] ;
	
	while( cin >> initial >> combination[ 0 ] >> combination[ 1 ] >> combination[ 2 ] )
	{
		if( initial == 0 && combination[ 0 ] == 0 && 
			combination[ 1 ] == 0 && combination[ 2 ] == 0 )
			break ;
		
		cout << ( calibration * 2 + 
				clockwise( initial, combination[ 0 ], calibration ) + 
				calibration * 1 + 
				counterClockwise( combination[ 0 ], combination[ 1 ], calibration ) +
				clockwise( combination[ 1 ], combination[ 2 ], calibration ) ) * 
				360 / calibration << endl ;
	}
	
	return 0 ;
}


/*
#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int a , b , c , d , answer ;

	while( cin >> a >> b >> c >> d )
	{
		if( a == 0 && b == 0 && c == 0 && d == 0 )
		{
			break ;
		}
		else
		{
			if( a > b )
			{
				answer = a - b ;
			}
			else
			{
				answer = a + 40 - b ;
			}

			if( b < c )
			{
				answer += c - b ;
			}
			else
			{
				answer += 40 - b + c ;
			}

			if( c > d )
			{
				answer += c - d ;
			}
			else
			{
				answer += c + 40 - d ;
			}

			cout << ( answer + 120 ) * 9 << endl ;
		}
	}

	return 0 ;
}
*/
