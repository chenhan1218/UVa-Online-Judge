#include <iostream>
#include <iomanip>
using namespace std ;

int digits[ 1000001 ] = { 0 } ;

int main()
{
	int N ;
	cin >> N ;

	int M , temp ;

	for( int i = 1 ; i <= N ; i++ )
	{
		digits[ 0 ] = 0 ;

		cin >> M ;

		for( int j = 1 ; j <= M ; j++ )
		{
			cin >> digits[ j ] ;

			cin >> temp ;

			digits[ j ] += temp ;
		}

		for( int j = M ; j >= 1 ; j-- )
		{
			if( digits[ j ] >=10 )
			{
				digits[ j ] -= 10 ;
				digits[ j - 1 ] ++ ;
			}
		}

		if( i != 1 )
		{
			cout << endl ;
		}

		for( int j = 1 ; j <= M ; j++ )
		{
			cout << digits[ j ] ;
		}
		cout << endl ;
	}

	return 0 ;
}
