#include <iostream>
using namespace std ;

int main()
{
	int N, L , S;
	int permutation[ 51 ] = { 0 } ;
	int place[ 51 ] = { 0 } ;
	int swap_times[ 51 ] = { 0 } ;
	cin >> N;
	
	for( int i = 1 ; i <= N ; i++ )
	{
		cin >> L ;
		if( L == 0 )
		{
			cout << "Optimal train swapping takes 0 swaps." << endl ;
		}
		else
		{
			for( int j = 1 ; j <= L ; j++ )
			{
				cin >> permutation[ j ] ;
				place[ permutation[ j ] ] = j ;
				swap_times[ j ] = 0 ;
			}

			S = 0 ;
			for( int j = 1 ; j <= L ; j++ )
			{
				S += place[ j ] + swap_times[ j ] - j ;
				for( int k = 1 ; k < place[ j ] ; k++ )
				{
					swap_times[ permutation[ k ] ] += 1 ;
				}
			}

			cout << "Optimal train swapping takes " << S << " swaps." << endl ;
		}
	}

	return 0 ;
}
