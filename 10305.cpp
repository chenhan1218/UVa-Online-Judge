#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std ;

const int	MaxN = 100 ;
bool	follow[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;

int main()
{
	int		n = 0 ;
	int		m = 0 ;
	int		ref[ MaxN + 1 ] = { 0 } ;
	vector<int>	remain ;
	queue<int>	q ;
	vector<int>	resultSeq ;
	
	while( cin >> n >> m )
	{
		if( n == 0 && m == 0 )
			break ;
		
		fill( ref + 1, ref + n + 1, 0 ) ;
		for( int i = 1 ; i <= n ; i++ )
		{
			fill( follow[ i ] + 1, follow[ i ] + n + 1, false ) ;
		}
		
		int	a = 0 ;
		int	b = 0 ;
		for( int i = 1 ; i <= m ; i++ )
		{
			cin >> a >> b ;
			if( follow[ a ][ b ] == false )
			{
				follow[ a ][ b ] = true ;
				ref[ b ]++ ;
			}
		}
		
		remain.clear() ;
		for( int i = 1 ; i <= n ; i++ )
		{
			if( ref[ i ] == 0 )
			{
				q.push( i ) ;
			}
			else
			{
				remain.push_back( i ) ;
			}
		}
		
		resultSeq.clear() ;
		while( q.size() != 0 )
		{
			resultSeq.push_back( q.front() ) ;
			
			for( int i = 0 ; i < remain.size() ; i++ )
			{
				if( follow[ q.front() ][ remain[ i ] ] == true )
				{
					follow[ q.front() ][ remain[ i ] ] = false ;
					ref[ remain[ i ] ]-- ;
					
					if( ref[ remain[ i ] ] == 0 )
					{
						q.push( remain[ i ] ) ;
						remain.erase( remain.begin() + i ) ;
						i-- ;
					}
				}
			}
			
			q.pop() ;
		}
		
		for( int i = 0 ; i < resultSeq.size() ; i++ )
		{
			if( i != 0 )
				cout << " " ;
			cout << resultSeq[ i ] ;
		}
		cout << endl ;
	}
	
	return 0 ;
}
