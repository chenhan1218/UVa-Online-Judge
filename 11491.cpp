#include <iostream>
#include <list>
using namespace std ;

int main()
{
	int		n = 0 ;
	int		d = 0 ;
	string	numStr ;
	
	cin.sync_with_stdio( false ) ;
	cout.sync_with_stdio( false ) ;
	
	while( cin >> n >> d >> numStr )
	{
		list<char>	num( numStr.begin(), numStr.end() ) ;
		list<char>::iterator	iterLeft = num.begin() ;
		list<char>::iterator	iterRight = iterLeft ;
		iterRight++ ;
		
		for( int i = 0 ; i < d ; i++ )
		{
			for( ; iterRight != num.end() ; iterLeft++, iterRight++ )
			{
				if( *iterLeft < *iterRight )
					break ;
			}
			
			iterRight = num.erase( iterLeft ) ;
			if( iterRight == num.begin() )
				iterRight++ ;
			iterLeft = iterRight ;
			iterLeft-- ;
		}
		
		numStr.assign( num.begin(), num.end() ) ;
		cout << numStr << endl ;
	}
	
	return 0 ;
}
/*
#include <iostream>
using namespace std ;

int main()
{
	int		n = 0 ;
	int		d = 0 ;
	string	num ;
	
	while( cin >> n >> d >> num )
	{
		int	index = 0 ;
		for( int i = 0 ; i < d ; i++ )
		{
			for( ; index < n - d ; index++ )
			{
				if( num[ index ] < num[ index + 1 ] )
					break ;
			}
			
			num.erase( index, 1 ) ;
			index = max( 0, index - 1 ) ;
		}
		
		cout << num << endl ;
	}
	
	return 0 ;
}
*/
