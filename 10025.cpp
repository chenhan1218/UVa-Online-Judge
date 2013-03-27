#include <iostream>
#include <vector>
using namespace std ;

int main()
{
	vector<int>	produce( 1, 1 ) ;
	int		testcase = 0 ;
	int		n = 0 ;
	int		k = 0 ;
	
	for( n = 2 ; produce.back() < 1000000000; n++ )
	{
		produce.push_back( produce.back() + n ) ;
	}
	for( int i = 0 ; i < 4 ; i++ )
	{
		produce.push_back( produce.back() + n ) ;
		n++ ;
	}
	
	cin >> testcase ;
	for( int runningcase = 1 ; runningcase <= testcase ; runningcase++ )
	{
		cin >> k ;
		
		if( k < 0 ) // the negative case is the same as the positive
		{
			k = -k ;
		}
		
		// make n large enough to reach k
		n = lower_bound( produce.begin(), produce.end(), k ) - produce.begin() + 1 ;
		
		// make oddicity of n suitable with k
		while( produce[ n - 1 ] % 2 != k % 2 )
		{
			n++ ;
		}
		
		//Print a blank line between the outputs for two consecutive test cases.
		if( runningcase > 1 )
		{
			cout << endl ;
		}
		cout << n << endl ;
	}
	
	return 0 ;
}
