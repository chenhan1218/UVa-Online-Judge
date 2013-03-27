#include <iostream>
#include <cmath>
using namespace std ;

int main()
{
	long long int	n = 0 ;
	long long int	root = 0 ;
	
	while( cin >> n && n != 0 )
	{
		root = (long long int)ceil( sqrt( n ) ) ;
		
		if( root*root - n < root )
		{
			if( root % 2 == 0 )
			{
				cout << root << " " << root*root - n + 1 << endl ;
			}
			else
			{
				cout << root*root - n + 1 << " " << root << endl ;
			}
		}
		else
		{
			if( root % 2 == 0 )
			{
				cout << root*2 - 1 - (root*root - n) << " " << root << endl ;
			}
			else
			{
				cout << root << " " << root*2 - 1 - (root*root - n) << endl ;
			}
		}
	}
	
	return 0 ;
}
