#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define Max_n 50
#define Max_m 100

class DNAString
{
	public:
		DNAString() ;
		static int	n ;
		static int	m ;
		void		calInversion() ;
		int			inversion ;
		char		*string ;
};

DNAString::DNAString()
{
	inversion = 0 ;
	string = new char[ Max_n + 1 ] ;
}

void DNAString::calInversion()
{
	int		occurances[ 4 ] = { 0 } ;
	int		i = 0 ; // loop counter

	inversion = 0 ;
	for( i = 0 ; i < DNAString::n ; i++ )
	{
		switch( string[ i ] )
		{
			case 'A' :
				inversion += occurances[ 1 ] + occurances[ 2 ] + occurances[ 3 ] ;
				occurances[ 0 ] ++ ;
				break ;
			case 'C' :
				inversion += occurances[ 2 ] + occurances[ 3 ] ;
				occurances[ 1 ] ++ ;
				break ;
			case 'G' :
				inversion += occurances[ 3 ] ;
				occurances[ 2 ] ++ ;
				break ;
			case 'T' :
				occurances[ 3 ] ++ ;
				break ;
		}
	}
}

// static data member must be initialized once at file scope.
int			DNAString::n = 0 ;
int			DNAString::m = 0 ;

bool cmp( DNAString a, DNAString b )
{
	return ( a.inversion < b.inversion ) ;
}

int main()
{
	int			cases = 0 ;
	DNAString	data[ Max_m + 1 ] ;
	int			i = 0 ; // loop counter
	int			j = 0 ; // loop counter

	cin >> cases ;

	for( i = 1 ; i <= cases ; i++ )
	{
		if( i > 1 ) //Print a blank line between consecutive test cases.
		{
			cout << endl ;
		}

		cin >> DNAString::n >> DNAString::m ;
		cin.get() ; // absorb the character '\n'

		for( j = 1 ; j <= DNAString::m ; j++ )
		{
			cin.getline( data[ j ].string, DNAString::n + 1 ) ;

			data[ j ].calInversion() ;
		}

		stable_sort( &data[ 1 ] , &data[ DNAString::m + 1 ], cmp ) ;

		for( j = 1 ; j <= DNAString::m ; j++ )
		{
			cout << data[ j ].string << endl ;
		}
	}

	return 0 ;
}

