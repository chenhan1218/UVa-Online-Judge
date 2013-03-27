#include <iostream>
using namespace std ;

int main()
{
	int cases , Amplitude , Frequency ;
	cin >> cases ;

	char **output = new char *[ 10 ] ;

	output[ 1 ] = "1" ;
	output[ 2 ] = "1\n22\n1" ;
	output[ 3 ] = "1\n22\n333\n22\n1" ;
	output[ 4 ] = "1\n22\n333\n4444\n333\n22\n1" ;
	output[ 5 ] = "1\n22\n333\n4444\n55555\n4444\n333\n22\n1" ;
	output[ 6 ] = "1\n22\n333\n4444\n55555\n666666\n55555\n4444\n333\n22\n1" ;
	output[ 7 ] = "1\n22\n333\n4444\n55555\n666666\n7777777\n666666\n55555\n4444\n333\n22\n1" ;
	output[ 8 ] = "1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1" ;
	output[ 9 ] = "1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n999999999\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1" ;

	for( int i = 1 ; i <= cases ; i++ )
	{
		cin.get() ;
		cin >> Amplitude >> Frequency ;

		for( int j = 1 ; j <= Frequency ; j++ )
		{
			if( i != 1 || j != 1)
			{
				cout << endl ;
			}
			cout << output[ Amplitude ] << endl ;
		}
	}

	return 0 ;
}
