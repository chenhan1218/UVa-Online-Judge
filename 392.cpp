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
		poly( int x ) {
			cof.assign( 1, x ) ;
		}
		poly( const std::string &s ) {
			int		c = 0 ;
			int		d = 0 ;
			char	bufferChar ;
			*this = poly() ;
			std::istringstream	is( s ) ;
			while( is >> c >> bufferChar >> bufferChar >> d ) {
				cof.reserve( d + 1 ) ;
				cof[ d ] = c ;
			}
		}
		int deg() const{
			return cof.size() - 1 ;
		}
		poly& operator=( int x ){
			cof.assign( 1, x ) ;
			return *this ;
		}
		poly& operator=( const poly &p ){
			cof = p.cof ;
			return *this ;
		}
		bool operator<( const poly &p ) const{
			std::vector<int>	inverse = cof ;
			std::vector<int>	inverseP = p.cof ;
			reverse( inverse.begin(), inverse.end() ) ;
			reverse( inverseP.begin(), inverseP.end() ) ;
			return inverse < inverseP ;
		}
		bool operator==( const poly &p ) const {
			return cof == p.cof ;
		}
		poly operator>>( unsigned int x ) const {
			if( x >= deg() + 1 ) {
				return poly() ;
			}
			else {
				poly ret = *this ;
				ret.cof.erase( ret.cof.begin(), ret.cof.begin() + x ) ;
				return ret ;
			}
		}
		poly operator<<( unsigned int x ) const {
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
			cof.reserve( p.cof.size() ) ;
			for( std::vector<int>::size_type ix = 0 ; ix != p.cof.size() ; ++ix ) {
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
		poly operator*( int x ) const {
			poly	mul = *this ;
			for( std::vector<int>::iterator iter = mul.cof.begin() ; iter != mul.cof.end() ; ++iter ) {
				*iter *= x ;
			}
			return mul ;
		}
		poly operator*( const poly &p ) const {
			poly	mul ;
			for( std::vector<int>::const_reverse_iterator iter = cof.rbegin() ; iter != cof.rend() ; ++iter ) {
				mul = ( mul << 1 ) + ( p * *iter ) ;
			}
			return mul ;
		}
		std::string toString() const {
			std::ostringstream	os ;
			for( std::vector<int>::const_reverse_iterator riter = cof.rbegin() ; riter != cof.rend() ; riter++ ) {
				// print coefficient
				if( riter != cof.rbegin() ) {
					if( *riter != 0 ) {
						os << ( (*riter > 0) ? " + " : " - " ) ;
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
	private:
		std::vector<int>	cof ;
};

int main()
{
	poly	p ;
	int		cof = 0 ;
	while( cin >> cof )
	{
		p = cof ;
		for( int i = 1 ; i <= 8 ; i++ ) {
			cin >> cof ;
			p = ( p << 1 ) + poly( cof ) ;
		}
		
		cout << p << endl ;
	}
	
	return 0 ;
}

/*
#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	int coefficients[ 9 ] ;

	while( cin >> coefficients[ 0 ] )
	{
		for( int i = 1 ; i < 9 ; i++ )
		{
			cin >> coefficients[ i ] ;
		}

		int i = 0 ;
		while( coefficients[ i ] == 0 )
		{
			i++ ;
		}

		if( i > 7 )
		{
			cout << coefficients[ 8 ] ;
		}
		else if( i == 7 )
		{
			if( coefficients[ i ] == 1 )
			{
				cout << "x" ;
			}
			else if( coefficients[ i ] == -1 )
			{
				cout << "-x" ;
			}
			else
			{
				cout << coefficients[ i ] << "x" ;
			}

			// This is constant term. //
			if( coefficients[ 8 ] > 0 )
			{
				cout << " + " << coefficients[ 8 ] ;
			}
			else if( coefficients[ 8 ] < 0 )
			{
				cout << " - " << (-1) * coefficients[ 8 ] ;
			}
		}
		else
		{
			if( coefficients[ i ] == 1 )
			{
				cout << "x^" << 8 - i ;
			}
			else if( coefficients[ i ] == -1 )
			{
				cout << "-x^" << 8 - i ;
			}
			else
			{
				cout << coefficients[ i ] << "x^" << 8 - i ;
			}

			for( int j = i + 1 ; j < 7 ; j++ )
			{
				if( coefficients[ j ] == 1 )
				{
					cout << " + " << "x^" << 8 - j ;
				}
				else if( coefficients[ j ] == -1 )
				{
					cout << " - " << "x^" << 8 - j ;
				}
				else if( coefficients[ j ] > 0 )
				{
					cout << " + " << coefficients[ j ] << "x^" << 8 - j ;
				}
				else if( coefficients[ j ] < 0 )
				{
					cout << " - " << (-1) * coefficients[ j ] << "x^" << 8 - j ;
				}
			}

			if( coefficients[ 7 ] == 1 )
			{
				cout << " + " << "x" ;
			}
			else if( coefficients[ 7 ] == -1 )
			{
				cout << " - " << "x" ;
			}
			else if( coefficients[ 7 ] > 0 )
			{
				cout << " + " << coefficients[ 7 ] << "x" ;
			}
			else if( coefficients[ 7 ] < 0 )
			{
				cout << " - " << (-1) * coefficients[ 7 ] << "x" ;
			}

			// This is constant term.
			if( coefficients[ 8 ] > 0 )
			{
				cout << " + " << coefficients[ 8 ] ;
			}
			else if( coefficients[ 8 ] < 0 )
			{
				cout << " - " << (-1) * coefficients[ 8 ] ;
			}
		}

		cout << endl ;
	}

	return 0 ;
}
*/
