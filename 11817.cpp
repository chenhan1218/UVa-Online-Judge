#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void vec_calculate( long double latitude, long double longitude, long double vec[] )
{
	vec[ 0 ] = cos( longitude ) * cos( latitude ) ;
	vec[ 1 ] = sin( longitude ) * cos( latitude ) ;
	vec[ 2 ] = sin( latitude ) ;
}

long double inner_product( long double vec1[], long double vec2[] )
{
	return vec1[ 0 ] * vec2[ 0 ] + vec1[ 1 ] * vec2[ 1 ] + vec1[ 2 ] * vec2[ 2 ] ;
}

long double deg2rad( long double deg )
{
	const long double	PI = acos(-1) ;
	return deg/180*PI ;
}

int main()
{
	int	testcase = 0 ;
	long double	latitude1 = 0 ;
	long double	longitude1 = 0 ;
	long double	latitude2 = 0 ;
	long double	longitude2 = 0 ;
	long double	vec1[3] = { 0 } ;
	long double	vec2[3] = { 0 } ;
	long double	angle = 0 ;
	long double	len_curve = 0 ;
	long double	len_tunnel = 0 ;

	cout << fixed;
	cout << setprecision (0) ;
	cin >> testcase ;

	for( int i = 0 ; i < testcase ; i++ ) {
		cin >> latitude1 >> longitude1 ;
		cin >> latitude2 >> longitude2 ;

		latitude1 = deg2rad( latitude1 ) ;
		longitude1 = deg2rad( longitude1 ) ;
		latitude2 = deg2rad( latitude2 ) ;
		longitude2 = deg2rad( longitude2 ) ;

		vec_calculate( latitude1, longitude1, vec1 ) ;
		vec_calculate( latitude2, longitude2, vec2 ) ;

		angle = acos( inner_product( vec1, vec2 ) ) ;
		len_curve = angle ;
		len_tunnel = sin( angle/2 )*2 ;

		cout << round( 6371009 * ( len_curve - len_tunnel ) ) << endl ;
	}
	return 0 ;
}
