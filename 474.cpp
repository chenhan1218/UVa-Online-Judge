#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

int main()
{
	long double	log2 = log10( 2 ) ;
	long double	ans = 0 ;
	long double	fraction = 0 ;
	long long int	integral = 0 ;
	int		n = 0 ;
	int		i = 0 ;
	
	cout << fixed << setprecision( 3 ) ;
	
	while( cin >> n )
	{
		ans = -1 * n * log2 ;
		integral = (long long int)floor( ans ) ;
		fraction = ans - integral ;
		
		cout << "2^-" << n << " = " << pow( 10, fraction ) << "e" << integral << endl ;
	}
	
	return 0 ;
}
