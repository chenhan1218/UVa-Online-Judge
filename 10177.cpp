#include <iostream>
using namespace std ;

int main()
{
	long long int N , intermediate ; /* intermediate = N * ( N + 1 ) / 2 */
	long long int S2 , R2 , S3 , R3 , S4 , R4 ;

	while( cin >> N )
	{
		intermediate = N * ( N + 1 ) / 2 ;

		S2 = intermediate * ( 2 * N + 1 ) / 3 ;
		S3 = intermediate * intermediate ;
		S4 = intermediate * ( 2 * N + 1 ) * ( 3 * N * N + 3 * N - 1 ) / 15 ;

		R2 = S3 - S2 ;
		R3 = S3 * ( intermediate - 1 ) ;
		R4 = S3 * S3 - S4 ;

		cout << S2 << " " << R2 << " " 
			<< S3 << " " << R3 << " " 
			<< S4 << " " << R4 << endl ;
	}

	return 0 ;
}
