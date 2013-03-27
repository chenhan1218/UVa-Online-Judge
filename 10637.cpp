#include <iostream>
#include <vector>
using namespace std;

vector<int>	part ;

long long int gcd( long long int a, long long int b )
{
	while( b != 0 )
	{
		a %= b ;
		swap( a, b ) ;
	}
	return a ;
}

void dfs( int remain, int depth, int t )
{
	int		i = 0 ;
	int		j = 0 ;
	if( depth != t )
	{
		if( depth == 0 )
		{
			for( i = 1 ; i <= remain/(t-depth) ; i++ )
			{
				part.push_back( i ) ;
				dfs( remain - i, depth + 1, t ) ;
				part.pop_back() ;
			}
		}
		else
		{
			for( i = part[ depth - 1 ] ; i <= remain/(t-depth) ; i++ )
			{
				for( j = 0 ; j < depth ; j++ )
				{
					if( gcd( i, part[ j ] ) != 1 )
						break ;
				}
				if( j < depth )
					continue ;
				
				part.push_back( i ) ;
				dfs( remain - i, depth + 1, t ) ;
				part.pop_back() ;
			}
		}
	}
	else // find a solution
	{
		if( remain != 0 )
			return ;
		
		cout << part[ 0 ] ;
		for( i = 1 ; i < part.size() ; i++ )
		{
			cout << " " << part[ i ] ;
		}
		cout << endl ;
	}
}

int main()
{
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		s = 0 ;
	int		t = 0 ;
	int		i = 0 ;
	
	cin >> casenum ;
	for( runningCase = 1 ; runningCase <= casenum ; runningCase++ )
	{
		cout << "Case " << runningCase << ":" << endl ;
		
		cin >> s >> t ;
		part.clear() ;
		dfs( s, 0, t ) ;
	}
	
	return 0 ;
}
