#include <iostream>
#include <string>
#include <algorithm>
using namespace std ;

#define MaxN 1000

int main()
{
	string	input ;
	int		n = 0 ;
	int		i = 0 ;

	while( cin >> n >> input )
	{
		for( i = 0 ; i < n ; i++ )
		{
			reverse( input.begin() + input.size() / n * i, 
				input.begin() + input.size() / n * (i+1) ) ;
		}
		
		cout << input << endl ;
	}
	
	return 0 ;
}
