#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std ;
#define MaxP 100

class point
{
	public:
		double	 x ;
		double	 y ;
		static double d( point a, point b )
		{
			return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) ;
		}
		bool used ;
};

point	p[ MaxP ] ;
int		usedp = 0 ;

double find_shortest( int n )
{
	int		p1 = 0 ;
	int		p2 = 0 ;
	double	minLen = -1 ;
	double	length = 0 ;
	int		i = 0 ;
	int		j = 0 ;

	for( i=0 ; i<n ; i++ )
	{
		for( j=0 ; j<n ; j++ )
		{
			if( i!=j )
			{
				length = sqrt( (p[i].x-p[j].x)*(p[i].x-p[j].x) + 
						(p[i].y-p[j].y)*(p[i].y-p[j].y) ) ;
				if( minLen < 0 || length < minLen )
				{
					minLen = length ;
					p1 = i ;
					p2 = j ;
				}
			}
		}
	}

	p[ p1 ].used = true ;
	p[ p2 ].used = true ;
	usedp = 2 ;

	return minLen ;
}

double mst( int	n )
{
	int		smallp = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	double	minLen = -1 ;
	double	length = 0 ;

	for( i = 0 ; i < n ; i++ )
	{
		if( p[ i ].used == true )
		{
			for( j = 0 ; j < n ; j++ )
			{
				if( p[j].used == false )
				{
					length = sqrt( (p[i].x-p[j].x)*(p[i].x-p[j].x) + 
							(p[i].y-p[j].y)*(p[i].y-p[j].y) ) ;
					if( minLen < 0 || length < minLen )
					{
						minLen = length ;
						smallp = j ;
					}
				}
			}
		}
	}
	p[ smallp ].used = 1 ;
	usedp++ ;

	return minLen ;
}

int main()
{
	int		testcase = 0 ;
	int		running = 0 ;
	int		n = 0 ;
	double	minLen = 0 ;
	int		i = 0 ;

	cin >> testcase ;
	for( running = 0 ; running < testcase ; running++ )
	{
		cin >> n ;
		for( i = 0 ; i < n ; i++ )
		{
			cin >> p[ i ].x >> p[ i ].y ;
			p[ i ].used = false ;
		}

		if( n < 2 )
		{
			cout << "0.00" << endl ;
		}		

		minLen = find_shortest( n ) ;

		while( usedp < n )
		{
			minLen += mst( n ) ;
		}

		// The outputs of two consecutive cases will be separated by a blank line.
		if( running > 0 )
		{
			cout << endl ;
		}
		cout << setprecision( 2 ) << fixed << minLen << endl ;
	}

	return 0 ;
}

