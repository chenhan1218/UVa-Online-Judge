#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std ;

int main()
{
	int		n = 0 ;
	
	while( cin >> n && n != 0 )
	{
		int		floating[ 10 ] = { 0 } ;
		int		integer = 0 ;
		char	buffer ;
		int		digit = 0 ;
		vector<long long int>	value( 80, 0 ) ;
		value[ 0 ] = 1 ;
		
		for( int i = 0 ; i < n ; i++ )
		{
			cin >> integer >> buffer >> digit ;
			floating[ digit ] += 1 ;
		}
		
		for( int i = 0 ; i < 8 ; i++ )
		{
			vector<long long int>	tmp( value.size(), 0 ) ;
			for( int j = 0 ; j < 10 ; j++ )
			{
				for( vector<int>::size_type ix = 0 ; ix <= i*9 ; ++ix )
				{
					tmp[ ix + j ] += value[ ix ] * floating[ j ] ;
				}
			}
			
			value.swap( tmp ) ;
		}
		
		for( vector<long long int>::size_type ix = 0 ; ix < value.size() ; ++ix )
		{
			value[ ix ] *= ix/10 ;
		}	
		
		cout << accumulate( value.begin(), value.end(), (long long int)0 ) << endl ;
	}
	
	return 0 ;
}
