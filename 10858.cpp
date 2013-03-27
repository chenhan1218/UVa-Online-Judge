/*
#include <iostream>
#include <vector>
using namespace std ;

vector<int>	factor ;

void factorization( int min, int n, int originN )
{
	int		i = 0 ;
	if( n == 1 )
	{
		if( factor.size() > 0 )
		{
			cout << factor[ 0 ] ;
			for( i = 1 ; i < factor.size() ; i++ )
				cout << " " << factor[ i ] ;
			cout << endl ;
		}
	}
	else
	{
		for( i = min ; i * i <= n ; i++ )
		{
			if( n % i == 0 )
			{
				factor.push_back( i ) ;
				factorization( i, n / i, originN ) ;
				factor.erase( factor.end() - 1 ) ;
			}
		}
		
		if( n >= min && n != originN )
		{
			factor.push_back( n ) ;
			factorization( n, 1, originN ) ;
			factor.erase( factor.end() - 1 ) ;
		}
	}
}

int main()
{
	int		n = 0 ;
	
	while( cin >> n && n != 0 )
	{
		factorization( 2, n, n ) ;
	}
	
	return 0 ;
}

*/
#include <iostream>
#include <vector>
using namespace std ;

vector<int>	factor ;
vector< vector<int> >	collection ;

void factorization( int min, int n, int originN )
{
	int		i = 0 ;
	if( n == 1 )
	{
		if( factor.size() > 0 )
		{
			collection.push_back( factor ) ;
		}
	}
	else
	{
		for( i = min ; i * i <= n ; i++ )
		{
			if( n % i == 0 )
			{
				factor.push_back( i ) ;
				factorization( i, n / i, originN ) ;
				factor.erase( factor.end() - 1 ) ;
			}
		}
		
		if( n >= min && n != originN )
		{
			factor.push_back( n ) ;
			factorization( n, 1, originN ) ;
			factor.erase( factor.end() - 1 ) ;
		}
	}
}

int main()
{
	int		n = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	while( cin >> n && n != 0 )
	{
		collection.clear() ;
		factorization( 2, n, n ) ;
		cout << collection.size() << endl ;
		for( i = 0 ; i < collection.size() ; i++ )
		{
			cout << collection[ i ][ 0 ] ;
			for( j = 1 ; j < collection[ i ].size() ; j++ )
				cout << " " << collection[ i ][ j ] ;
			cout << endl ;
		}
	}
	
	return 0 ;
}
