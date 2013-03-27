#include <iostream>
#include <vector>
using namespace std ;

int main()
{
	int		n = 0 ;
	int		k = 0 ;
	vector<long long int>	remainder ;
	
	while( cin >> n >> k && ( n != -1 && k != -1 ) )
	{		
		int		cof = 0 ;
		int		mul = 1 ;

		if( k == 0 )
		{
			for( int deg = 0 ; deg <= n ; deg++ )
			{
				cin >> cof ;
			}
			cout << 0 << endl ;
			continue ;
		}

		remainder.assign( k, 0 ) ;
		for( int deg = 0 ; deg <= n ; deg++ )
		{
			cin >> cof ;
			remainder[ deg % k ] += mul * cof ;
			if( deg % k == k-1 )
				mul *= -1 ;
		}
		
		while( remainder.size() > 1 && remainder.back() == 0 )
			remainder.erase( remainder.end() - 1 ) ;
		cout << remainder[ 0 ] ;
		for( int deg = 1 ; deg < remainder.size() ; deg++ )
		{
			cout << " " << remainder[ deg ] ;
		}
		cout << endl ;
	}
	
	return 0 ;
}

/*
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <string>
using namespace std ;

class poly
{
	friend std::ostream& operator<<(std::ostream& os, const poly &p) {
		os << p.toString() ;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, poly &p) {
		std::string	input ;
		is >> input ;
		p = poly( input ) ;
		return is;
	}
	
	public:
		poly() {
			cof.assign( 1, 0 ) ;
		}
		poly( long long int x ) {
			cof.assign( 1, x ) ;
		}
		poly( const std::string &s ) {
			long long int		c = 0 ;
			long long int		d = 0 ;
			char	bufferChar ;
			*this = poly() ;
			std::istringstream	is( s ) ;
			while( is >> c >> bufferChar >> bufferChar >> d ) {
				cof.resize( max( cof.size(), (std::vector<long long int>::size_type)d + 1 ) ) ;
				cof[ d ] = c ;
			}
		}
		long long int deg() const{
			return cof.size() - 1 ;
		}
		poly& operator=( long long int x ){
			cof.assign( 1, x ) ;
			return *this ;
		}
		poly& operator=( const poly &p ){
			cof = p.cof ;
			return *this ;
		}
		bool operator<( const poly &p ) const{
			if( cof.size() != p.cof.size() )
				return cof.size() < p.cof.size() ;
			
			std::vector<long long int>	inverse = cof ;
			std::vector<long long int>	inverseP = p.cof ;
			reverse( inverse.begin(), inverse.end() ) ;
			reverse( inverseP.begin(), inverseP.end() ) ;
			return inverse < inverseP ;
		}
		bool operator==( const poly &p ) const {
			return cof == p.cof ;
		}
		poly operator>>( unsigned long long int x ) const {
			if( x >= deg() + 1 ) {
				return poly() ;
			}
			else {
				poly ret = *this ;
				ret.cof.erase( ret.cof.begin(), ret.cof.begin() + x ) ;
				return ret ;
			}
		}
		poly operator<<( unsigned long long int x ) const {
			if( *this == poly() ) {
				return poly() ;
			}
			else {
				poly ret = *this ;
				ret.cof.insert( ret.cof.begin(), x, 0 ) ;
				return ret ;
			}
		}
		poly& operator+=( const poly &p ){
			cof.resize( max( cof.size(), p.cof.size() ) ) ;
			for( std::vector<long long int>::size_type ix = 0 ; ix != p.cof.size() ; ++ix ) {
				cof[ ix ] += p.cof[ ix ] ;
			}
			while( cof.size() > 1 && cof.back() == 0 )
				cof.resize( cof.size() - 1 ) ;
			return *this ;
		}
		poly operator+( const poly &p ) const {
			poly ret = *this ;
			ret += p ;
			return ret ;
		}
		poly operator*( long long int x ) const {
			poly	mul = *this ;
			for( std::vector<long long int>::iterator iter = mul.cof.begin() ; iter != mul.cof.end() ; ++iter ) {
				*iter *= x ;
			}
			return mul ;
		}
		poly operator*( const poly &p ) const {
			poly	mul ;
			for( std::vector<long long int>::const_reverse_iterator iter = cof.rbegin() ; iter != cof.rend() ; ++iter ) {
				mul = ( mul << 1 ) + ( p * *iter ) ;
			}
			return mul ;
		}
		std::string toString() const {
			std::ostringstream	os ;
			for( std::vector<long long int>::const_reverse_iterator riter = cof.rbegin() ; riter != cof.rend() ; riter++ ) {
				// print coefficient
				if( riter != cof.rbegin() ) {
					if( *riter != 0 ) {
						os << ( (*riter > 0) ? "+" : "-" ) ;
						if( abs(*riter) != 1 || ( riter == (cof.rend() - 1) ) ) {
							os << abs(*riter) ;
						}
					}
				}
				else {
					if( abs(*riter) == 1 && riter != cof.rend() - 1 )
					{
						if( *riter < 0 )
							os << "-" ;
					}
					else {
						os << *riter ;
					}
				}
				
				// print power of indeterminate
				if( *riter != 0 && riter != cof.rend() - 1 )
					os << "x" ;
				if( *riter != 0 && riter < cof.rend() - 2 )
					os << "^" << cof.rend() - 1 - riter ;
			}
			return os.str() ;
		}
	public:
		std::vector<long long int>	cof ;
};

long long int	gcd( long long int a, long long int b )
{
	while( b != 0 )
	{
		a %= b ;
		swap( a, b ) ;
	}
	
	return a ;
}

poly	reduce( poly a )
{
	long long int	divisor = a.cof.back() ;
	// let gcd ofcoefficient of a are 1
	for( std::vector<long long int>::reverse_iterator riter = a.cof.rbegin() + 1 ;
		riter != a.cof.rend() ; ++riter )
	{
		if( *riter != 0 )
			divisor = gcd( divisor, *riter ) ;
	}
	
	for( std::vector<long long int>::iterator iter = a.cof.begin() ;
		iter != a.cof.end() ; ++iter )
	{
		*iter /= divisor ;
	}
	
	return a ;
}

poly	remainder( poly a, poly b )
{
	b = reduce( b ) ;
	while( a.deg() >= b.deg() )
	{
		if( a == poly() )
			break ;
		a = a * ( b.cof.back() / gcd( a.cof.back(), b.cof.back() ) ) ;
		a = a + ( ( b * ( -1 * a.cof.back() / b.cof.back() ) ) << ( a.deg() - b.deg() ) ) ;
		//a = reduce( a ) ;
	}
	
	return a ;
}

int main()
{
	int		n = 0 ;
	int		k = 0 ;
	poly	p ;
	poly	divisor ;
	poly	rem ;
	
	while( cin >> n >> k && ( n != -1 && k != -1 ) )
	{
		p = poly() ;
		divisor = ( poly( 1 ) << k ) + poly( 1 ) ;
		int		cof = 0 ;
		for( int i = 0 ; i <= n ; i++ )
		{
			cin >> cof ;
			p = p + (poly( cof ) << i) ;
		}
		
		rem = remainder( p, divisor ) ;
		
		cout << rem.cof[ 0 ] ;
		for( std::vector<long long int>::iterator riter = rem.cof.begin() + 1; 
			riter != rem.cof.end() ; riter++ )
		{
			cout << " " << *riter ;
		}
		cout << endl ;
	}
	
	return 0 ;
}
*/
