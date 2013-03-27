#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	char input ;

	int H , M ;
	double angle_H , angle_M , answer ;

	cout.setf( ios::fixed ) ;
	cout.precision( 3 ) ;

	while( cin >> H >> input >> M )
	{
		if( H != 0 || M != 0 )
		{
			if( H == 12 )
			{
				H = 0 ;
			}

			angle_H = H * 30.0 + M / 2.0 ;
			angle_M = M * 6.0 ;

			if( angle_H >= angle_M )
			{
				answer = angle_H - angle_M ;
			}
			else
			{
				answer = angle_M - angle_H ;
			}

			if( answer > 180 )
			{
				answer = 360 - answer ;
			}

			cout << answer << endl ;
		}
		else
		{
			break ;
		}
	}

	return 0 ;
}
