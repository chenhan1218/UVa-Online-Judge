#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	long long int input , origin_c , later_c , hour_to_smallseconds ;

	hour_to_smallseconds = 60 ;
	hour_to_smallseconds *= 6000 ;

	while( cin >> input )
	{
		origin_c = input % 100 ;
		input /= 100 ;
		origin_c += ( input % 100 ) * 100 ;
		input /= 100 ;
		origin_c += ( input % 100 ) * 6000 ;
		input /= 100 ;
		origin_c += ( input % 100 ) * hour_to_smallseconds ;

		later_c = static_cast< int >( origin_c / 0.864 ) ;

		cout << setw( 7 ) << setfill( '0' ) << later_c << endl ;
	}

	return 0 ;
}
