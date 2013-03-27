#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std ;

class TIME
{
	public:
		TIME(){
			hh = 0 ;
			mm = 0 ;
		}
		TIME( int h, int m ){
			hh = h ;
			mm = m ;
		}
		int		hh ;
		int		mm ;
		static bool cmp( const TIME &a, const TIME &b )
		{
			if( b.hh > a.hh )	return true ;
			else if( b.hh == a.hh ) return b.mm > a.mm ;
			else	return false ;
		}
};

int main()
{
	vector<TIME>	v ;
	int		n = 0 ;
	int		hh = 0 ;
	int		mm = 0 ;
	char	buf ;
	int		index = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	for( i = 0 ; i <= 9 ; i++ )
		v.push_back( TIME( 0, i ) ) ;
	for( i = 11 ; i <= 55 ; i += 11 )
		v.push_back( TIME( 0, i ) ) ;

	for( i = 1 ; i <= 9 ; i++ )
		for( j = 0 ; j < 6 ; j++ )
			v.push_back( TIME( i, j * 10 + i ) ) ;

	for( j = 0 ; j < 6 ; j++ )
		v.push_back( TIME( 1 * 10 + j, j * 10 + 1 ) ) ;
	for( j = 0 ; j <= 3 ; j++ )
		v.push_back( TIME( 2 * 10 + j, j * 10 + 2 ) ) ;

	sort( v.begin(), v.end(), TIME::cmp ) ;
	
	cin >> n ;
	for( i = 0 ; i < n ; i++ )
	{
		cin >> hh >> buf >> mm ;
		
		index = upper_bound( v.begin(), v.end(), TIME( hh, mm ), TIME::cmp ) - v.begin() ;
		if( index != v.size() )
		{
			cout 	<< setfill('0') << setw( 2 ) << v[ index ].hh << ":" 
					<< setfill('0') << setw( 2 ) << v[ index ].mm << endl ;
		}
		else
		{
			cout << "00:00" << endl ;
		}
	}
	
	return 0 ;
}
