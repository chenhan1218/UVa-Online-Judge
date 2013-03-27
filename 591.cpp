#include <iostream>
using namespace std ;

int main()
{
	int n ;
	int h[ 101 ] ;

	long long int total ;
	long long int average ;

	long long setnumber = 0 ;

	while( cin >> n )
	{
		if( n == 0 )
		{
			break ;
		}

		setnumber++ ;
		total = 0 ;

		for( int i = 1 ; i <= n ; i++ )
		{
			cin >> h[ i ] ;
			total += h[ i ] ;
		}

		average = total / n ;
		total = 0 ;

		for( int i = 1 ; i <= n ; i++ )
		{
			if( h[ i ] > average )
			{
				total += h[ i ] - average ;
			}
		}

		cout << "Set #" << setnumber << endl ;
		cout << "The minimum number of moves is " << total << "." << endl << endl ;
	}

	return 0 ;
}
