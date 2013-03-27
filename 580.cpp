#include <iostream>
using namespace std;

int main(){
	const int MAX_N = 30 ;
	long long int num[ MAX_N + 1 ] = { 0 } ;
	int n = 0 ;

	num[ 0 ] = 1 ;
	num[ 1 ] = 2 ;
	num[ 2 ] = 4 ;
	for( int i = 3 ; i <= MAX_N ; i++ ) {
		num[ i ] = num[ i - 1 ] + num[ i - 2 ] + num[ i - 3 ] ;
	}

	for( int i = 0 ; i <= MAX_N ; i++ ) {
		num[ i ] = ( ((long long int)1) << i ) - num[ i ] ;
	}

	while( 1 ) {
		cin >> n ;
		if( n == 0 )
			break;

		cout << num[ n ] << endl ;
	}

	return 0 ;
}
