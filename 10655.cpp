#include <iostream>
#include <vector>
using namespace std ;

/*
linear algebra
a_n = a^n + b^n

a_n    =   a+b   -ab     a_n-1
                      *   
a_n-1      1     0       a_n-2

a_n+1    =  | a+b   -ab |^n    a_1
            |           |   *   
a_n         | 1     0   |      a_0
*/

void print( const vector< vector<long long int> > &mat )
{
	for( int i = 0 ; i < mat.size() ; i++ )
	{
		for( int j = 0 ; j < mat[ i ].size() ; j++ )
		{
			cout << mat[ i ][ j ] << "\t" ;
		}
		cout << endl ;
	}
	cout << endl ;
}

vector< vector<long long int> > matMul( const vector< vector<long long int> > &a, 
const vector< vector<long long int> > &b )
{
	vector< vector<long long int> >	ans( a.size(), vector<long long int>( b[0].size() ) ) ;
	
	for( int i = 0 ; i < ans.size() ; i++ )
	{
		for( int j = 0 ; j < ans[ i ].size() ; j++ )
		{
			for( int k = 0 ; k < a[ i ].size() ; k++ )
			{
				ans[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ] ;
			}
		}
	}
	
	return ans ;
}

vector< vector<long long int> > matPower( const vector< vector<long long int> > &mat, unsigned int n )
{
	vector< vector<long long int> >	ans( mat.size(), vector<long long int>( mat.size() ) ) ;
	ans[ 0 ][ 0 ] = 1 ;
	ans[ 1 ][ 1 ] = 1 ;
	
	if( n == 0 )
	{
		return ans ;
	}
	else if( n == 1 )
	{
		return mat ;
	}
	else
	{
		ans = matPower( mat, n/2 ) ;
		ans = matMul( ans, ans ) ;
		
		if( n % 2 == 1 )
		{
			ans = matMul( ans, mat ) ;
		}
		
		return ans ;
	}
}

int main()
{
	vector< vector<long long int> >	mat( 2, vector<long long int>( 2 ) ) ;
	int		p = 0 ;
	int		q = 0 ;
	int		n = 0 ;
	
	while( cin >> p >> q >> n )
	{
		mat[ 0 ][ 0 ] = p ;
		mat[ 0 ][ 1 ] = -q ;
		mat[ 1 ][ 0 ] = 1 ;
		mat[ 1 ][ 1 ] = 0 ;
		
		mat = matPower( mat, n ) ; // mat = mat^n 
		//print( mat ) ;
		
		cout << mat[ 1 ][ 0 ] * p + mat[ 1 ][ 1 ] * 2 << endl ;
	}
	
	return 0 ;
}
