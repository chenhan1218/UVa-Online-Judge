#include <iostream>
using namespace std ;

#include <fstream>
using std::ofstream ;

int main()
{
	long long int Factorial[ 32 ] = { 0 } ;
	Factorial[ 2 ] = 6 ;
	Factorial[ 3 ] = 28 ;
	Factorial[ 5 ] = 496 ;
	Factorial[ 7 ] = 8128 ;
	Factorial[ 13 ] = 8191 ;
	Factorial[ 13 ] *= 4096 ;
	Factorial[ 17 ] = 131071 ;
	Factorial[ 17 ] *= 65536 ;
	Factorial[ 19 ] = 524287 ;
	Factorial[ 19 ] *= 262144 ;
	Factorial[ 31 ] = 2147483647 ;
	Factorial[ 31 ] *= 1073741824 ;

	int n ;

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}

		if( n == 2 || n == 3 || n == 5 || n == 7 
			|| n == 13  || n == 17 || n == 19 || n == 31 )
		{
			cout << "Perfect: " << Factorial[ n ] << "!" << endl ;
		}
		else if( n == 11 || n == 23 || n == 29 )
		{
			cout << "Given number is prime. But, NO perfect number is available." << endl ;
		}
		else
		{
			cout << "Given number is NOT prime! NO perfect number is available." << endl ;
		}
	}

	return 0 ;
}
