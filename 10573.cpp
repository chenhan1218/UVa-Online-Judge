#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std ;

int main()
{
	string	buffer ;
	int		n = 0 ;
	double	t = 0 ;
	double	r1 = 0 ;
	double	r2 = 0 ;
	const double	pi = 2 * acos( 0 ) ;
	
	getline( cin, buffer ) ;
	n = atoi( buffer.c_str() ) ;
	
	cout << fixed << setprecision( 4 ) ;
	
	for( int i = 0 ; i < n ; i++ )
	{
		getline( cin, buffer ) ;
		istringstream	is( buffer ) ;
		
		is >> t ;
		if( is >> r2 )
		{
			r1 = t ;
			cout << 2 * r1 * r2 * pi << endl ;
		}
		else
		{
			cout << t * t / 8 * pi << endl ;
		}
	}
	
	return 0 ;
}
