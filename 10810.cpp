#include <iostream>
#include <vector>
using namespace std ;

long long int merge( vector<int> &v )
{
	vector<int>	left ;
	vector<int>	right ;
	vector<int>	sorted ;
	long long int		inversions = 0 ;
	int		i = 0 ;
	int		j = 0 ;

	if( v.size() == 1 )
	{
		return 0 ;
	}
	else
	{
		left.assign( v.begin(), v.begin() + v.size() / 2 ) ;
		right.assign( v.begin() + v.size() / 2, v.end() ) ;

		inversions += merge( left ) ;
		inversions += merge( right ) ;

		i = 0 ;
		j = 0 ;
		while( i < left.size() && j < right.size() )
		{
			if( left[ i ] <= right[ j ] )
			{
				v[ i + j ] = left[ i ] ;
				i++ ;
			}
			else
			{
				inversions += left.size() - i ;
				v[ i + j ] = right[ j ] ;
				j++ ;
			}
		}

		while( i < left.size() )
		{
			v[ i + j ] = left[ i ] ;
			i++ ;
		}

		while( j < right.size() )
		{
			v[ i + j ] = right[ j ] ;
			j++ ;
		}

		return inversions ;
	}
}

int main()
{
	int		n = 0 ;
	vector<int>	v ;
	int		i = 0 ; // loop counter

	while( cin >> n && n != 0 )
	{
		v.resize( n ) ;
		for( i = 0 ; i < n ; i++ )
			cin >> v[ i ] ;

		cout << merge( v ) << endl ;
	}

	return 0 ;
}
