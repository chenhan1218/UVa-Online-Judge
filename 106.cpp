#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

#define MaxN 1000000

class Pythagorean
{
	public:
		Pythagorean(){
			a = 0 ;
			b = 0 ;
			c = 0 ;
		}
		Pythagorean( long long int ia, long long int ib, long long int ic ){
			a = ia ;
			b = ib ;
			c = ic ;
		}
		long long int		a ;
		long long int		b ;
		long long int		c ;
		static bool cmp( const Pythagorean &p, const Pythagorean &q ){
			return p.c < q.c ;
		}
};

long long int gcd( long long int a, long long int b )
{
	while( b != 0)
	{
		a %= b;
		swap( a, b ) ;
	}
	
	return a ;
}

int main()
{
	long long int	m = 0 ;
	long long int	n = 0 ;
	long long int	triples = 0 ;
	long long int	i = 0 ; // loop counter
	long long int	j = 0 ; // loop counter
	bool			isComponent[ MaxN + 1 ] = { 0 } ;
	vector<Pythagorean>	v ;
	
	//generate primitive Pythagorean
	for( m = 1 ; m*m <= MaxN ; m++ )
	{
		for( n = 1 ; n < m && m*m+n*n <= MaxN ; n++ )
		{
			if( gcd( m, n ) == 1 && ( m % 2 == 0 || n % 2 == 0 ) )
			{
				v.push_back( Pythagorean( m*m-n*n, 2*m*n, m*m+n*n ) ) ;
			}
		}
	}
	
	sort( v.begin(), v.end(), Pythagorean::cmp ) ;
	
	/*
	for( i = 0 ; i < v.size() ; i++ )
	{
		cout << v[ i ].a << "\t" << v[ i ].b << "\t" << v[ i ].c << "\t" << endl ;
	}
	cout << v.size() << endl ;
	*/
	
	while( cin >> n )
	{
		triples = upper_bound( v.begin(), v.end(), Pythagorean( 0, 0, n ), Pythagorean::cmp ) - 
				v.begin() ;
		cout << triples ;
		
		fill( isComponent, isComponent + n + 1, false ) ;
		for( i = 0 ; i < triples ; i++ )
		{
			for( j = 1 ; j * v[ i ].c <= n ; j++ )
			{
				isComponent[ j * v[ i ].a ] = true ;
				isComponent[ j * v[ i ].b ] = true ;
				isComponent[ j * v[ i ].c ] = true ;
			}
		}
		
		cout << " " << count( isComponent + 1, isComponent + n + 1, false ) << endl ;
	}
}
