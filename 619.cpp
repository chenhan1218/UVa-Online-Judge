#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std ;

//
// need to include <sstream>, <iomanip>, <cstdlib>, <algorithm>, <string>
//
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
			int		i = 0 ;
			while( input.size() > 1 && input[ 0 ] == '0' ) 
				input.erase( 0, 1 ) ;
			v.clear() ;
			while( input.size() >= Ndigit ) {
				v.push_back( atoi( input.substr( input.size() - Ndigit ).c_str() ) ) ;
				input = input.substr( 0, input.size() - Ndigit ) ;
			}
			if( input.size() != 0 ) {
				v.push_back( atoi( input.c_str() ) ) ;
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
			bigint sum = *this ;
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
			bigint	temp = *this ;
			while( x != 0 )
			{
				if( x % 2 == 1 )
					mul += temp ;
				x /= 2 ;
				temp += temp ;
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

bigint mypow( bigint n, long long int p )
{
	bigint	temp = 0 ;
	if( p == 0 )
	{
		return bigint( 1 ) ;
	}
	else if( p == 1 )
	{
		return n ;
	}
	else
	{
		temp = mypow( n, p/2 ) ;
		temp *= temp ;
		if( p % 2 == 1 )
		{
			temp *= n ;
		}
		
		return temp ;
	}
}

string addCommas( string input )
{
	string	number ;
	while( input.length() >= 3 )
	{
		number = input.substr( input.length() - 3 ) + "," + number ;
		input = input.substr( 0, input.length() - 3 ) ;
	}
		
	if( input.length() > 0 )
	{
		number = input + "," + number ;
	}
	
	return number.substr( 0, number.length() - 1 ) ;
}

int main()
{
	bigint	p[ 31 ] = { 0 } ;
	string	input ;
	string	word ;
	bigint	number ;
	bigint	temp ;
	int		len = 0 ;
	int		i = 0 ;
	
	p[ 0 ] = 0 ;
	for( i = 1 ; i <= 30 ; i++ )
	{
		p[ i ] = p[ i - 1 ] + mypow( bigint(26), i ) ;
		//cout << p[ i ] << endl ;
	}
	
	while( cin >> input && input != "*" )
	{
		if( isdigit( input[ 0 ] ) != 0 ) // input is a number
		{
			len = lower_bound( p, p + 30, bigint( input ), bigint::cmp ) - p ;
			temp = bigint( input ) - p[ len-1 ] - 1 ;
			word = "" ;
			for( i = 0 ; i < len ; i++ )
			{
				word = string( 1, 'a' + (temp % 26).v[ 0 ] ) + word ;
				temp = temp / 26 ;
			}
			
			number = bigint( input ) ;
		}
		else // input is a string
		{
			word = input ;
			
			number = p[ input.length() - 1 ] ;
			for( i = 0 ; i < input.size() ; i++ )
			{
				number += mypow( bigint(26), input.size() - 1 - i ) * ( input[ i ] - 'a' ) ;
			}
			
			number += 1 ;
		}
		
		cout << setw( 22 ) << left << word ;
		cout << addCommas( number.toString() ) << endl ;
	}
	
	return 0 ;
}
