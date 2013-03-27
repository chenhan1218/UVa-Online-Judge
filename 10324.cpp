#include <iostream>
#include <string>
using namespace std;

int		numOfZero[ 1000000 + 1 ] = { 0 } ;

int main()
{
	string	buffer ;
	int		n = 0 ;
	int		casenum = 0 ;
	
	while( cin >> buffer )
	{
		casenum++ ;
		for( int index = 1 ; index <= buffer.size() ; index++ )
		{
			numOfZero[ index ] = numOfZero[ index - 1 ] ;
			if( buffer[ index-1 ] == '0' )
				numOfZero[ index ] ++ ;
		}

		cout << "Case " << casenum << ":" << endl ;
		cin >> n ;
		for( int loop = 1 ; loop <= n ; loop++ )
		{
			int		i = 0 ;
			int		j = 0 ;
			cin >> i >> j ;
			if( i > j )
				swap( i, j ) ; // make sure that i <= j
			
			if( numOfZero[ j+1 ] - numOfZero[ i ] == j-i+1 || 
				numOfZero[ j+1 ] - numOfZero[ i ] == 0 )
			{
				cout << "Yes" << endl ;
			}
			else
			{
				cout << "No" << endl ;
			}
		}
	}
	
	return 0 ;
}
