#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
	int earlier_hh = 0 , earlier_mm = 0 , earlier_ss = 0 
		, hh = 0 , mm = 0 , ss = 0 ;
	long double speed = 0 , distance = 0 ;
	char buffer ;
	bool getSpeed = 0 ;

	cout.setf( ios::fixed ) ;

	while( cin >> hh >> buffer >> mm >> buffer >> ss )
	{
		cin.get( buffer ) ;
		if( buffer == ' ' )
		{
			distance += ( ( hh - earlier_hh ) + 
				( mm - earlier_mm ) / 60.0 + 
				( ss - earlier_ss ) / 3600.0 ) * speed ;

			earlier_hh = hh ;
			earlier_mm = mm ;
			earlier_ss = ss ;

			cin >> speed ;
		}
		else
		{
			distance += ( ( hh - earlier_hh ) + 
				( mm - earlier_mm ) / 60.0 + 
				( ss - earlier_ss ) / 3600.0 ) * speed ;

			cout.precision( 0 ) ;

			cout << setw( 2 ) << setfill( '0' ) << hh << ":" 
				<< setw( 2 ) << setfill( '0' ) << mm << ":" 
				<< setw( 2 ) << setfill( '0' ) << ss << " " ;

			cout.precision( 2 ) ;
			cout << distance << " km" << endl ;

			earlier_hh = hh ;
			earlier_mm = mm ;
			earlier_ss = ss ;
		}
	}

	return 0 ;
}
