#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std ;

double cosValue( double x1, double y1, double x2, double y2 )
{
	return ( x1*x2 + y1*y2 ) / sqrt( x1*x1 + y1*y1 ) / sqrt( x2*x2 + y2*y2 ) ;
}

class GT_cls
{
public:
	pair<long long int,long long int>	 ref ;
	pair<long long int,long long int>	 diff ;
	GT_cls( pair<long long int,long long int> r, pair<long long int,long long int> d ): ref( r ), diff( d ){ } ;
	bool operator()( pair<long long int,long long int> const &a, pair<long long int,long long int> const &b ) const
	{
		double	dx1 = a.first-ref.first ;
		double	dy1 = a.second-ref.second ;
		double	dx2 = b.first-ref.first ;
		double	dy2 = b.second-ref.second ;
		
		if( cosValue( dx1, dy1, diff.first, diff.second ) == cosValue( dx2, dy2, diff.first, diff.second ) )
		{
			if( abs( cosValue( dx1, dy1, diff.first, diff.second ) - 1 ) < 1e-6 )
			{
				return dx1 < dx2 ;
			}
			else
			{
				if( dx1 == dx2 )
				{
					return dy1 > dy2 ;
				}
				else
				{
					return dx1 > dx2 ;
				}
			}
		}
		else
		{
			return cosValue( dx1, dy1, diff.first, diff.second ) > cosValue( dx2, dy2, diff.first, diff.second ) ;
		}
	}
};

int main( )
{
	int		t = 0 ;
	
	cin >> t ;
	while( t > 0 )
	{
		t-- ;
		int		n = 0 ;
		long long int	x = 0 ;
		long long int	y = 0 ;
		int		minIndex = 0 ;
		char	isConvex ;
		vector< pair<long long int,long long int> >	point ;
		
		cin >> n ;
		
		for( int i = 0 ; i < n ; i++ )
		{
			cin >> x >> y >> isConvex ;
			if( isConvex == 'Y' )
			{
				point.push_back( pair<long long int,long long int>(x,y) ) ;
			}
		}
		
		swap( *(min_element(point.begin(),point.end())), point[ 0 ] ) ;
		minIndex = 1 ;
		for( int i = 2 ; i < point.size() ; i++ )
		{
			if( point[ minIndex ].first - point[ 0 ].first == 0 || 
				( point[ i ].first - point[ 0 ].first != 0 &&
				(point[ i ].second - point[ 0 ].second)*(point[ minIndex ].first - point[ 0 ].first) < 
				(point[ minIndex ].second - point[ 0 ].second)*(point[ i ].first - point[ 0 ].first) ) )
			{
				minIndex = i ;
			}
		}
		swap( point[ minIndex ], point[ 1 ] ) ;
		
		sort( point.begin()+2, point.end(), GT_cls( point[ 0 ], 
			pair<long long int,long long int>(point[ 1 ].first-point[ 0 ].first,point[ 1 ].second-point[ 0 ].second) ) ) ;
		
		cout << point.size() << endl ;
		for( int i = 0 ; i < point.size() ; i++ )
		{
			cout << point[ i ].first << " " << point[ i ].second << endl ;
		}
	}

	return 0 ;
}

