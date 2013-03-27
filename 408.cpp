#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
	long long int STEP , MOD , temp , dealing_MOD , dealing_STEP ;

	while( cin >> STEP >> MOD )
	{
		dealing_STEP = STEP ;
		dealing_MOD = MOD ;
		while( dealing_STEP != 0 )
		{
			temp = dealing_MOD % dealing_STEP ;
			dealing_MOD = dealing_STEP ;
			dealing_STEP = temp ;
		}

		if( dealing_MOD == 1 )
		{
			cout << setw( 10 ) << STEP << setw( 10 ) << MOD << "    " << "Good Choice" << endl << endl ;
		}
		else
		{
			cout << setw( 10 ) << STEP << setw( 10 ) << MOD << "    " << "Bad Choice" << endl << endl ;
		}
	}

	return 0 ;
}
