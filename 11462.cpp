#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

int main()
{
	vector<int>	num( 100 ) ;
	int		n = 0 ;

	while( cin >> n )
	{
		if( n == 0 )
			break ;
		
		fill( num.begin(), num.end(), 0 ) ;
		int		data ;
		for( int i = 0 ; i < n ; i++ )
		{
			cin >> data ;
			num[ data ]++ ;
		}
		
		bool	firstNum = true ;
		for( vector<int>::size_type ix = 0 ; ix != num.size() ; ix++ )
		{
			for( int j = 0 ; j < num[ ix ] ; j++ )
			{
				if( firstNum == true )
					firstNum = false ;
				else
					cout << " " ;

				cout << ix ;
			}
		}
		cout << endl ;
	}
	
	return 0 ;
}
