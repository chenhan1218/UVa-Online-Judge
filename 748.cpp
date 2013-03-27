#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std ;

class bigint {
	friend ostream& operator<<(ostream& os, const bigint& b) {
		os << b.toString() ;
		return os;
	}
	friend istream& operator>>(istream& is, bigint& b) {
		string	input ;
		is >> input ;
		b = bigint( input ) ;
		return is;
	}

	public:
		vector<long long int> v;
		static const long long int N ;
		static const long long int Ndigit;
		bigint( long long int x) {
			do {
				v.push_back( x % N ) ;
				x /= N ;
			} while( x != 0 ) ;
		}
		bigint() {
			v = vector<long long int>( 1, 0 ) ;
		}
		
		bigint( string input ) {
			*this = bigint( 0 ) ;
			for( int i = 0 ; i < input.length() ; i++ ) {
				*this = *this *10 + input[ i ] - '0' ;
			}
		}

		int compare(const bigint& x ) const{
			if( v.size() != x.v.size() ) return v.size() - x.v.size() ;
			for( int i = v.size() - 1 ; i >= 0 ; i-- ) {
				if( v[ i ] != x.v[ i ] ) return v[ i ] - x.v[ i ] ;
			}
			return 0 ;
		}

		int compare( long long int x ) const{
			return compare( bigint( x ) ) ;
		}
		
		static bool cmp( const bigint &a, const bigint &b ) {
			return a.compare( b ) < 0 ;
		}

		bigint& operator=( const bigint& x ) {
			v = x.v ;
			return *this ;
		}

		bigint& operator=( long long int x ){
			*this = bigint( x ) ;
			return *this ;
		}

		bigint operator+(const bigint& x) const {
			bigint sum = 0 ;
			int i = 0 ;
			if( v.size() >= x.v.size() ) {
				sum.v = v ;
				for( i = 0; i < x.v.size() ; i++ ) {
					sum.v[ i ] += x.v[ i ] ;
				}
			}
			else {
				sum.v = x.v ;
				for( i = 0; i < v.size() ; i++ ) {
					sum.v[ i ] += v[ i ] ;
				}
			}

			for( i = 0 ; i < sum.v.size() - 1 ; i++ ) {
				if( sum.v[ i ] >= N ) {
					sum.v[ i + 1 ] += sum.v[ i ] / N ;
					sum.v[ i ] %= N ;
				}
			}

			i = sum.v.size() - 1 ;
			while( sum.v[ i ] >= N ) {
				sum.v.push_back( sum.v[ i ] / N ) ;
				sum.v[ i ] %= N ;
				i++ ;
			}

			return sum ;
		}

		bigint& operator+=(const bigint& x) {
			*this = *this + x ;
			return *this;
		}

		bigint operator*(int x) const {
			bigint	mul = 0 ;
			long long int	carry = 0 ;
			int		i = 0 ;
			if( x == 0 ) return mul ;
			mul.v.clear() ;
			for( i = 0 ; i < v.size() ; i++ ) {
				carry += v[ i ] * x ;
				mul.v.push_back( carry % N ) ;
				carry /= N ;
			}
			while( carry != 0 )
			{
				mul.v.push_back( carry % N ) ;
				carry /= N ;
			}

			return mul;
		}

		bigint& operator*=(int x) {
			*this = *this * x ;
			return *this;
		}

		bigint operator*(const bigint& x) const {
			bigint mul = 0 ;
			int i = 0 ;
			mul.v.clear() ;
			for( i = x.v.size() - 1; i >= 0 ; i--) {
				mul *= N ;
				mul += *this * x.v[ i ] ;
			}

			return mul ;
		}

		bigint& operator*=(const bigint& x) {
			*this = *this * x ;
			return *this;
		}

		bigint operator-(const bigint& x ) const {
			bigint sub ;
			sub.v.clear() ;
			long long int i = 0, carry = 0 ;
			for( i = 0 ; i < x.v.size() ; i++ ) {
				carry += v[ i ] - x.v[ i ] ;
				if( carry < 0 ) sub.v.push_back( carry + N ), carry = -1 ;
				else sub.v.push_back( carry ), carry = 0 ;
			}
			for( ; i < v.size() ; i++ ) {
				carry = v[ i ] + carry ;
				if( carry < 0 ) sub.v.push_back( carry + N ), carry = -1 ;
				else sub.v.push_back( carry ), carry = 0 ;
			}
			while( sub.v.size() > 1 && sub.v.back() == 0 )
				sub.v.pop_back() ;

			return sub ;
		}

		bigint& operator-=(const bigint& x ) {
			*this = *this - x ;
			return *this ;
		}

		void divideBy2() {
			long long int i = 0, carry = 0 ;
			for( i = v.size() - 1 ; i >= 0 ; i-- ) {
				carry = v[ i ] + carry * N ;
				v[ i ] = carry / 2 ;
				carry %= 2 ;
			}
			if( v.size() > 1 && v.back() == 0 ) v.pop_back() ;
		}

		bigint operator/(const bigint& x ) const {
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

		string toString() const{
			ostringstream buffer ;
			buffer << v.back() ;
			for(int i = v.size()-2; i>=0; i--)
				buffer << setw(Ndigit) << setfill('0') << v[ i ] ;
			return buffer.str() ;
		}
};

const long long int bigint::N = 1000000000;
const long long int bigint::Ndigit=9;

bigint pow( bigint a, int p )
{
	bigint	temp ;
	if( p == 0 )
		return bigint( 1 ) ;
	else if( p == 1 )
		return a ;
	
	temp = pow( a, p / 2 ) ;
	temp *= temp ;
	if( p % 2 == 1 )
		temp *= a ;
	
	return temp ;
}

string	itoa( long long int a )
{
	string	str ;
	do
	{
		str.insert( 0, 1, '0' + a%10 ) ;
		a /= 10 ;
	} while( a != 0 ) ;
	
	return str ;
}

int main()
{
	string	r ;
	int		decimalPlace = 0 ;
	bigint	bigR ;
	string	ans ;
	int		n = 0 ;
	int		i = 0 ;
	
	while( cin >> r >> n )
	{
		if( r.find( '.' ) != string::npos )
		{
			decimalPlace = r.size() - r.find( '.' ) - 1 ;
			r.erase( r.find( '.' ), 1 ) ;
		}
		else
		{
			decimalPlace = 0 ;
		}
		
		bigR = bigint( r ) ;
		
		ans = pow( bigR, n ).toString() ;
		
		if( ans.size() < n * decimalPlace )
		{
			ans.insert( 0, n * decimalPlace - ans.size(), '0' ) ;
		}
		
		ans.insert( ans.size() - n * decimalPlace, 1, '.' ) ;
		
		// erase Leading zeros
		while( ans[ 0 ] == '0' )
		{
			ans.erase( 0, 1 ) ;
		}
		// erase insignificant trailing zeros
		while( ans[ ans.length() - 1 ] == '0' )
		{
			ans.erase( ans.end() - 1 ) ;
		}
		
		if( ans[ ans.length() - 1 ] == '.' )
			ans.erase( ans.end() - 1 ) ;
		
		cout << ans << endl ;
	}
	
	return 0 ;
}
