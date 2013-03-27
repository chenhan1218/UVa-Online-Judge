#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std ;

class fre
{
	public:
		char	v ;
		int		f ;
		fre(){
			f = 0 ;
		}
		static bool cmp( const fre &a, const fre &b )
		{
			if( a.f != b.f )
				return a.f > b.f ;
			else
				return ( a.v -'A' ) < ( b.v -'A' ) ;
		}
};

int main()
{
	string	buffer ;
	fre		c[ 26 ] ;
	int		t = 0 ;
	int		i = 0 ;

	for( i = 0 ; i < 26 ; i++ )
	{
		c[ i ].v = 'A' + i ;
		c[ i ].f = 0 ;
	}

	cin >> t ;
	getline( cin, buffer ) ;
	while( t > 0 )
	{
		t-- ;
		getline( cin, buffer ) ;

		for( i = 0 ; i < buffer.size() ; i++ )
		{
			if( isalpha( buffer[ i ] ) )
			{
				c[ toupper( buffer[ i ] ) - 'A' ].f += 1 ;
			}
		}
	}

	sort( c, c + 26, fre::cmp ) ;

	for( i = 0 ; i < 26 && c[ i ].f > 0 ; i++ )
		cout << c[ i ].v << " " << c[ i ].f << endl ;

	return 0 ;
}
