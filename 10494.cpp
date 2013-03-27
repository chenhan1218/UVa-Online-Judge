#include <iostream>
#include <iomanip>
using namespace std ;

#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>

//
// need to include <string>
//
class mybigint {
	friend ostream &operator<<(ostream& os, const mybigint& b) {
		os << b.value ;
		return os;
	}
	friend istream &operator>>(istream& is, mybigint& b) {
		is >> b.value ;
		while( b.value[ 0 ] == '0' && b.value.length() > 1 )
			b.value.erase( 0, 1 ) ;
		return is;
	}

	public:
		string value;

		mybigint() {
			value.assign( "0" ) ;
		}

		int compare(const mybigint& x) const {
			if( value.length() != x.value.length() ) {
				return value.length() - x.value.length() ;
			}
			else {
				return value.compare( x.value ) ;
			}
		}

		const mybigint &operator=( int x ) {
			value.assign( 1, '0' + x % 10 ) ;
			x /= 10 ;
			while( x != 0 ) {
				value.insert( 0, 1, x % 10 + '0' ) ;
				x /= 10 ;
			}
			return *this ;
		}

		const mybigint &operator=( const mybigint &x ) {
			value = x.value ;
			return *this ;
		}

		mybigint operator+(const mybigint &x) {
			mybigint	sum ;
			int		buffer = 0 ;
			int		carry = 0 ;
			int		i = 0, j = 0 ; // loop counter

			sum.value.clear() ;
			for( 	i = value.length() - 1, j = x.value.length() - 1 ; 
					i >= 0 && j >= 0 ; i--, j-- ) {
				carry = ( value[ i ] - '0' ) + ( x.value[ j ] - '0' ) + carry ;
				if( carry >= 10 ) {
					sum.value.push_back( '0' + carry - 10 ) ;
					carry = 1 ;
				}
				else {
					sum.value.push_back( '0' + carry ) ;
					carry = 0 ;
				}
			}

			if( i >= 0 ) {
				for( ; i >= 0 ; i-- ) {
					carry = ( value[ i ] - '0' ) + carry ;
					if( carry >= 10 ) {
						sum.value.push_back( '0' + carry - 10 ) ;
						carry = 1 ;
					}
					else {
						sum.value.push_back( '0' + carry ) ;
						carry = 0 ;
					}
				}
			}
			if( j >= 0 ) {
				for( ; j >= 0 ; j-- ) {
					carry = ( x.value[ j ] - '0' ) + carry ;
					if( carry >= 10 ) {
						sum.value.push_back( '0' + carry - 10 ) ;
						carry = 1 ;
					}
					else {
						sum.value.push_back( '0' + carry ) ;
						carry = 0 ;
					}
				}
			}

			return sum ;
		}

		mybigint& operator+=( const mybigint &x ){
			*this = *this + x ;
			return *this ;
		}

		mybigint operator+( int x) {
			mybigint mybigintX ;
			mybigintX = x ;
			mybigintX = *this + mybigintX ;
			return mybigintX ;
		}

		mybigint operator*(const mybigint& x) {
			mybigint	multiValue[ 10 ] ;
			mybigint	mul ;
			int		i = 0 ;

			multiValue[ 0 ] = 0 ;
			for( i = 1 ; i < 10 ; i++ ) {
				multiValue[ i ] = multiValue[ i - 1 ] + *this ;
			}

			mul = 0 ;
			for( i = 0 ; i < x.value.length() ; i++ ) {
				// mult mul with 10
				if( mul.value[ 0 ] != '0' ) {
					mul.value.insert( mul.value.length(), 1, '0' ) ;
				}
				mul = mul + multiValue[ x.value[ i ] - '0' ] ;
			}
			return mul;
		}

		mybigint &operator*=(const mybigint& x) {
			*this = *this * x ;
			return *this ;
		}

		mybigint operator*(int x) {
			mybigint mybigintX ;
			mybigintX = x ;
			return *this * mybigintX ;
		}

		mybigint operator-(const mybigint& x ) {
			mybigint substract ;
			substract.value.clear() ;
			int i = 0, j = 0, carry = 0 ;
			for( i = x.value.length() - 1, j = value.length() - 1 ; i >= 0 ; i--, j-- ) {
				carry = value[ j ] - x.value[ i ] + carry ;
				if( carry < 0 ) substract.value.insert( 0, 1, '0' + carry + 10 ), carry = -1 ;
				else substract.value.insert( 0, 1, '0' + carry ), carry = 0 ;
			}
			for( ; j >= 0 ; j-- ) {
				carry = value[ j ] + carry ;
				if( carry < 0 ) substract.value.insert( 0, 1, '0' + carry + 10 ), carry = -1 ;
				else substract.value.insert( 0, 1, '0' + carry ), carry = 0 ;
			}
			while( substract.value[ 0 ] == '0' && substract.value.length() > 1 ) 
				substract.value.erase( 0, 1 ) ;
			return substract ;
		}

		mybigint& operator-=(const mybigint& x ) {
			*this = *this - x ;
			return *this ;
		}

		void divideBy2() {
			int i = 0, carry = 0 ;
			for( i = 0 ; i < value.length() ; i++ ) {
				carry = value[ i ] - '0' + carry * 10 ;
				value[ i ] = '0' + carry / 2 ;
				carry %= 2 ;
			}
			if( value[ 0 ] == '0' && value.length() > 1 ) value.erase( 0, 1 ) ;
		}

		mybigint operator/(const mybigint& x ) {
			mybigint quotient ;
			mybigint remainder = *this ;
			mybigint quotientPart ;
			quotientPart = 1 ;
			mybigint Xpow2s = x ;

			while( remainder.compare( Xpow2s ) > 0 ) {
				Xpow2s += Xpow2s, quotientPart += quotientPart ;
			}

			while( remainder.compare( x ) >= 0 )
			{
				if( remainder.compare( Xpow2s ) >= 0 ) 
					remainder -= Xpow2s, quotient += quotientPart ;
				Xpow2s.divideBy2(), quotientPart.divideBy2() ;
			}

			return quotient ;
		}

		mybigint operator%(const mybigint& x ) {
			mybigint quotient ;
			mybigint remainder = *this ;
			mybigint quotientPart ;
			quotientPart = 1 ;
			mybigint Xpow2s = x ;

			while( remainder.compare( Xpow2s ) > 0 ) {
				Xpow2s += Xpow2s, quotientPart += quotientPart ;
			}

			while( remainder.compare( x ) >= 0 )
			{
				if( remainder.compare( Xpow2s ) >= 0 ) 
					remainder -= Xpow2s, quotient += quotientPart ;
				Xpow2s.divideBy2(), quotientPart.divideBy2() ;
			}

			return remainder ;
		}
};

//
// need to include <sstream>, <iomanip>, <cstdlib>, <algorithm>
//
class bigint {
	friend ostream& operator<<(ostream& os, const bigint& b) {
		using std::ostringstream ;
		ostringstream buffer ;
		buffer << b.v[b.size-1] ;
		for(int i=b.size-2; i>=0; i--)
			buffer << setw(Ndigit) << setfill('0') << b.v[ i ] ;
		os << buffer.str() ;
		return os;
	}
	friend istream& operator>>(istream& is, bigint& b) {
		string	input ;
		int		i = 0 ;
		is >> input ;
		input.push_back( '\0' ) ;
		while( input[ 0 ] == '0' && input[ 1 ] != '\0' ) 
			input.erase( 0, 1 ) ;
		memset(b.v, 0, sizeof(b.v));
		for( 	i=input.length() - Ndigit - 1, b.size = 0 ; i >= 0 ; 
				i-=Ndigit, (b.size) += 1 ) {
			b.v[ b.size ] = atoi( input.c_str() + i ) ;
			input[ i ] = '\0' ;
		}
		if( i + Ndigit != 0 ) {
			b.v[ b.size ] = atoi( input.c_str() ) ;
			(b.size) += 1 ;
		}
		return is;
	}

	public:
		int v[10000];
		int size;
		static const int N, Ndigit;
		bigint(int x) {
			memset(v, 0, sizeof(v));
			v[0] = x % N , size = 1 , x /= N ;
			while( x != 0 ) v[ size ] = x % N, size++, x /= N ;
		}
		bigint() {
			memset(v, 0, sizeof(v));
			size = 1;
		}

		int compare(const bigint& x ) {
			if( size != x.size ) return size - x.size ;
			for( int i = size - 1 ; i >= 0 ; i-- ) {
				if( v[ i ] != x.v[ i ] ) return v[ i ] - x.v[ i ] ;
			}
			return 0 ;
		}

		bigint& operator=( const bigint& x ) {
			memset(v, 0, sizeof(v));
			copy( x.v, x.v + x.size, v ) ;
			size = x.size ;
			return *this ;
		}

		bigint& operator=( int x ){
			memset(v, 0, sizeof(v));
			v[0] = x % N , size = 1 , x /= N ;
			while( x != 0 ) v[ size ] = x % N, size++, x /= N ;
			return *this ;
		}

		bigint operator+(const bigint& x) {
			bigint sum = 0 ;
			long long int carry = 0 ;
			int i = 0 ;
			for( i = 0; i < x.size || i < size ; i++) {
				carry += v[ i ] + x.v[i] ;
				if( carry >= N ) sum.v[ i ] = carry - N , carry = 1 ;
				else sum.v[ i ] = carry, carry = 0 ;
			}
			if( carry > 0 ) sum.v[ i ] = carry, i += 1 ;
			sum.size = i;
			return sum ;
		}

		bigint& operator+=(const bigint& x) {
			*this = *this + x ;
			return *this;
		}

		bigint operator*(int x) const {
			bigint mul = 0 ;
			if( x == 0 ) return mul ;
			long long int i = 0, carry = 0 ;
			for(i=0; i<size; i++) {
				carry += (long long int)v[i] * x ;
				mul.v[i] = carry % N ;
				carry /= N ;
			}
			while( carry>0 ) mul.v[i] = carry % N, carry /= N, i++ ;
			mul.size = i ;
			return mul;
		}

		bigint& operator*=(int x) {
			*this = *this * x ;
			return *this;
		}

		bigint operator*(const bigint& x) const {
			bigint mul = 0 ;
			int i = 0 ;
			if( x.size <= size ) {
				for(i=x.size - 1; i>=0 ; i--) {
					mul *= N ;
					mul += *this * x.v[ i ] ;
				}
			}
			else {
				for(i=size - 1; i>=0 ; i--) {
					mul *= N ;
					mul += x * v[ i ] ;
				}
			}
			return mul ;
		}

		bigint& operator*=(const bigint& x) {
			*this = *this * x ;
			return *this;
		}

		bigint operator-(const bigint& x ) {
			bigint sub ;
			long long int i = 0, carry = 0 ;
			for( i = 0 ; i < x.size ; i++ ) {
				carry = v[ i ] - x.v[ i ] + carry ;
				if( carry < 0 ) sub.v[ i ] = carry + N, carry = -1 ;
				else sub.v[ i ] = carry, carry = 0 ;
			}
			for( ; i < size ; i++ ) {
				carry = v[ i ] + carry ;
				if( carry < 0 ) sub.v[ i ] = carry + N, carry = -1 ;
				else sub.v[ i ] = carry, carry = 0 ;
			}
			sub.size = size ;
			while( sub.v[ sub.size - 1 ] == 0 && sub.size > 1 )
				sub.size -= 1 ;
			return sub ;
		}

		bigint& operator-=(const bigint& x ) {
			*this = *this - x ;
			return *this ;
		}

		void divideBy2() {
			long long int i = 0, carry = 0 ;
			for( i = size - 1 ; i >= 0 ; i-- ) {
				carry = v[ i ] + carry * N ;
				v[ i ] = carry / 2 ;
				carry %= 2 ;
			}
			if( v[ size - 1 ] == 0 && size > 1 ) size-- ;
		}

		bigint operator/(const bigint& x ) {
			bigint quotient ;
			bigint remainder = *this ;
			bigint quotientPart( 1 ) ;
			bigint Xpow2s = x ;

			while( remainder.compare( Xpow2s ) > 0 ) {
				Xpow2s += Xpow2s, quotientPart += quotientPart ;
			}

			while( remainder.compare( x ) >= 0 )
			{
				if( remainder.compare( Xpow2s ) >= 0 ) 
					remainder -= Xpow2s, quotient += quotientPart ;
				Xpow2s.divideBy2(), quotientPart.divideBy2() ;
			}

			return quotient ;
		}

		bigint operator%(const bigint& x ) {
			bigint quotient ;
			bigint remainder = *this ;
			bigint quotientPart( 1 ) ;
			bigint Xpow2s = x ;

			while( remainder.compare( Xpow2s ) > 0 ) {
				Xpow2s += Xpow2s, quotientPart += quotientPart ;
			}

			while( remainder.compare( x ) >= 0 )
			{
				if( remainder.compare( Xpow2s ) >= 0 ) 
					remainder -= Xpow2s, quotient += quotientPart ;
				Xpow2s.divideBy2(), quotientPart.divideBy2() ;
			}

			return remainder ;
		}
};

const int bigint::N = 1000000000;
const int bigint::Ndigit=9;

int
main()
{
	bigint a ;
	bigint b ;
	char	op ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> a >> op >> b )
	{
		if( op == '/' )
		{
			cout << a / b << endl ;
		}
		else
		{
			cout << a % b << endl ;
		}
	}

	return 0 ;
}

