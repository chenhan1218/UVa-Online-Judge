#include <iostream>
#include <queue>
#include <vector>
using namespace std ;

int main()
{
	int		n = 0 ;
	priority_queue< long long int, vector<long long int>, greater<long long int> >	q ;
	long long int	buffer = 0 ;
	long long int	a = 0 ;
	long long int	b = 0 ;
	long long int	cost = 0 ;
	int		i = 0 ;
	
	while( cin >> n && n != 0 )
	{
		while( q.empty() == false )
		{
			q.pop() ;
		}
		
		for( i = 0 ; i < n ; i++ )
		{
			cin >> buffer ;
			q.push( buffer ) ;
		}
		
		cost = 0 ;
		while( q.size() >= 2 )
		{
			a = q.top() ;
			q.pop() ;
			b = q.top() ;
			q.pop() ;
			cost += a+b ;
			q.push( a+b ) ;
		}
		
		cout << cost << endl ;
	}
	
	return 0 ;
}
