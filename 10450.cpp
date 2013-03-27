#include <iostream>
using namespace std ;

int main()
{
	long long int Fibonacci[ 51 ] = { 0 } ;
	Fibonacci[ 1 ] = 2 ;
	Fibonacci[ 2 ] = 3 ;
	for( int i = 3 ; i <= 50 ; i++ )
	{
		Fibonacci[ i ] = Fibonacci[ i - 1 ] + Fibonacci[ i - 2 ] ;
	}

	int scenarios ;
	int input ;

	cin >> scenarios ;

	for( int cases = 1 ; cases <= scenarios ; cases++ )
	{
		cin >> input ;

		cout << "Scenario #" << cases << ":" << endl << Fibonacci[ input ] << endl << endl ;
	}

	return 0 ;
}
