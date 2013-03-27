#include <iostream>
#include <vector>
using namespace std ;

vector< vector<long long int> > mul( const vector< vector<long long int> > &a, const vector< vector<long long int> > &b, long long int module )
{
	if( b.empty() == true ) return vector< vector<long long int> >( 0 ) ;
	vector< vector<long long int> > v( a.size(), vector<long long int>( b[ 0 ].size(), 0 ) ) ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	for( i = 0 ; i < v.size() ; i++ )
	{
		for( j = 0 ; j < v[ i ].size() ; j++ )
		{
			for( k = 0 ; k < a[ i ].size() ; k++ )
			{
				v[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ] ;
			}
			
			v[ i ][ j ] %= module ;
		}
	}
	
	return v ;
}

vector< vector<long long int> > pow( const vector< vector<long long int> > &a, long long int p, long long int module )
{
	vector< vector<long long int> > v( a.size(), vector<long long int>( a.size(), 0 ) ) ;
	int		i = 0 ;
	for( i = 0 ; i < a.size() ; i++ )
		v[ i ][ i ] = 1 % module ;
	
	if( p == 0 )
		return v ;
	else if( p == 1 )
		return a ;
	
	v = pow( a, p / 2, module ) ;
	v = mul( v, v, module ) ;
	if( p % 2 == 1 )
	{
		v = mul( v, a, module ) ;
	}
	
	return v ;
}

int main()
{
	vector< vector<long long int> > v ;
	long long int ans ;
	int		m = 0 ;
	int		n = 0 ;
	int		i = 0 ;
	
	while( cin >> n >> m )
	{
		v = vector< vector<long long int> >( 2, vector<long long int>( 2, 0 ) ) ;
		v[ 0 ][ 1 ] = 1 ;
		v[ 1 ][ 0 ] = 1 ;
		v[ 1 ][ 1 ] = 1 ;
		
		v = pow( v, n, 1L<<m ) ;
		
		ans = v[ 0 ][ 0 ] * 0 + v[ 0 ][ 1 ] * 1 ;
		cout << ans << endl ;
	}
	
	return 0 ;
}

/* AC but slower version
#include <iostream>
using namespace std ;

int main()
{
	int exponent_2[ 20 ] = { 0 } ;
	exponent_2[ 0 ] = 1 ;
	for( int i = 1 ; i < 20 ; i++ )
	{
		exponent_2[ i ] = exponent_2[ i - 1 ] * 2 ;
	}

	int Fabonacci_length[ 20 ] = { 0 } ;
	Fabonacci_length[ 0 ] = 1 ;
	Fabonacci_length[ 1 ] = 3 ;
	for( int i = 2 ; i < 20 ; i++ )
	{
		Fabonacci_length[ i ] = Fabonacci_length[ i - 1 ] * 2 ;
	}

	int **Fabonacci = new int *[ 20 ] ;
	Fabonacci[ 0 ] = new int [ 1 ] ;
	Fabonacci[ 0 ][ 0 ] = 0 ;
	for( int i = 1 ; i < 20 ; i++ )
	{
		Fabonacci[ i ] = new int [ Fabonacci_length[ i ] ] ;

		Fabonacci[ i ][ 0 ] = 0 ;
		Fabonacci[ i ][ 1 ] = 1 ;

		for( int j = 2 ; j < Fabonacci_length[ i ] ; j++ )
		{
			Fabonacci[ i ][ j ] = ( Fabonacci[ i ][ j - 1 ] + Fabonacci[ i ][ j - 2 ] ) % exponent_2[ i ] ;
		}
	}

	int n , m ;

	while( cin >> n >> m )
	{
		if( m == 0 )
		{
			cout << "0" << endl ;
		}
		else
		{
			cout << Fabonacci[ m ][ n % Fabonacci_length[ m ] ] << endl ;
		}
	}

	return 0 ;
}
*/
