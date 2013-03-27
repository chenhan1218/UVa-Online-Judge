#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std ;

int main()
{
	int		nc = 0 ;
	int		casenum = 0 ;
	
	while( cin >> nc && nc != 0 )
	{
		map<int,set<int> >	neighbor ;
		int		a = 0 ;
		int		b = 0 ;
		int		node = 0 ;
		int		ttl = 0 ;
		for( int i = 0 ; i < nc ; i++ )
		{
			cin >> a >> b ;
			
			neighbor[ a ].insert( b ) ;
			neighbor[ b ].insert( a ) ;
		}
		
		while( cin >> node >> ttl )
		{
			if( node == 0 && ttl == 0 )
				break ;
			
			set<int>	visited ;
			queue< pair<int,int> >	q ;
			int		unreachable = 0 ;
			
			q.push( pair<int,int>(node,ttl) ) ;
			while( q.empty() == false )
			{
				int		curNode = q.front().first ;
				int		curTTL = q.front().second ;
				// if the node haven't been visited
				if( visited.find( curNode ) == visited.end() )
				{
					visited.insert( curNode ) ;
					
					if( curTTL > 0 )
					{
						for( set<int>::const_iterator iter = neighbor[ curNode ].begin() ; 
						iter != neighbor[ curNode ].end() ; ++iter )
						{
							q.push( pair<int,int>(*iter,curTTL-1) ) ;
						}
					}
				}
				
				q.pop() ;
			}
			unreachable = neighbor.size() - visited.size() ;
			
			casenum++ ;
			cout << "Case " << casenum << ": " << unreachable << " nodes not reachable from node "
			<< node << " with TTL = " << ttl << "." << endl ;
		}
	}
	
	return 0 ;
}
