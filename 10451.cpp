#include <iostream>
using namespace::std ;

#include <iomanip>
using std::setprecision ;

#include <cmath>

int main()
{
	int n ;
	double A ;

	const double pi = acos( 0 ) * 2.0 ;

	double Rsquare , rsquare ;

	int counter = 0 ;

	cout.setf(ios::fixed) ;

	while( cin >> n >> A )
	{
		if( n < 3 )
		{
			break ;
		}

		Rsquare = A / n * 2 / sin( 2 * pi / n ) ;
		rsquare = Rsquare * cos( pi / n ) * cos( pi / n ) ;

		Rsquare = Rsquare * pi - A ;
		rsquare = A - rsquare * pi ;

		counter++ ;
		cout << "Case " << counter << ": " 
			<< setprecision( 5 ) << Rsquare 
			<< " "
			<< setprecision( 5 ) << rsquare << endl ;
	}

	system("pause") ;
	return 0 ;
}
