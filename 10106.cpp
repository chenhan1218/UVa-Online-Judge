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
		while( b.value[ 0 ] == '0' && b.value.length() > 1 ) b.value.erase( 0, 1 ) ;
		return is;
	}

	public:
		string value;

		mybigint() {
			value.assign( "0" ) ;
		}

		const mybigint &operator=( unsigned int x ) {
			value.assign( 1, '0' + x % 10 ) ;
			x /= 10 ;
			while( x != 0 )
			{
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
			int		carryIn = 0 ;
			int		i = 0 ; // loop counter
			int		j = 0 ; // loop counter

			if( value.length() < x.value.length() )
			{
				sum.value = string( x.value.length() - value.length(), '0' ) + value ;
			}
			else
			{
				sum.value = value ;
			}

			// add x.value into returnValue
			for( 	i = x.value.length() - 1, j = sum.value.length() - 1 ; 
					i >= 0 ; 
					i--, j-- )
			{
				buffer = ( sum.value[ j ] - '0' ) + ( x.value[ i ] - '0' ) + carryIn ;
				if( buffer >= 10 )
				{
					sum.value[ j ] = buffer - 10 + '0' ;
					carryIn = 1 ;
				}
				else
				{
					sum.value[ j ] = buffer + '0' ;
					carryIn = 0 ;
				}
			}

			if( carryIn > 0 )
			{
				while( j >= 0 )
				{
					if( sum.value[ j ] == '9' )
					{
						sum.value[ j ] = '0' ;
					}
					else
					{
						sum.value[ j ] += 1 ;
						break ;
					}
					j-- ;
				}
				if( j < 0 )
				{
					sum.value.insert( 0, 1, '1' ) ;
				}
			}
			return sum ;
		}

		mybigint& operator+=( const mybigint &x ){
			*this = *this + x ;
			return *this ;
		}

		mybigint operator+(unsigned int x) {
			mybigint mybigintX ;
			mybigintX = x ;
			mybigintX = *this + mybigintX ;
			return mybigintX ;
		}

		mybigint operator*(const mybigint& x) {
			mybigint	multiValue[ 10 ] ;
			mybigint	multiply ;
			int		i = 0 ;

			multiValue[ 0 ] = 0 ;
			for( i = 1 ; i < 10 ; i++ )
			{
				multiValue[ i ] = multiValue[ i - 1 ] + *this ;
			}

			multiply = 0 ;
			for( i = 0 ; i < x.value.length() ; i++ ) {
				// mult multiply with 10
				if( multiply.value[ 0 ] != '0' )
				{
					multiply.value.insert( multiply.value.length(), 1, '0' ) ;
				}
				multiply = multiply + multiValue[ x.value[ i ] - '0' ] ;
			}
			return multiply;
		}

		mybigint &operator*=(const mybigint& x) {
			*this = *this * x ;
			return *this ;
		}

		mybigint operator*(unsigned int x) {
			mybigint mybigintX ;
			mybigintX = x ;
			return *this * mybigintX ;
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
		input.insert( input.length(), 1, '\0') ;
		while( input[ 0 ] == '0' && input[ 1 ] != '\0' )	input.erase( 0, 1 ) ;
		memset(b.v, 0, sizeof(b.v));
		for( i=input.length() - Ndigit - 1, b.size = 0 ; i>=0; i-=Ndigit, (b.size) += 1 )
		{
			b.v[ b.size ] = atoi( input.c_str() + i ) ;
			input[ i ] = '\0' ;
		}
		if( i + Ndigit != 0 )
		{
			b.v[ b.size ] = atoi( input.c_str() ) ;
			(b.size) += 1 ;
		}
		return is;
	}

	public:
		unsigned int v[200];
		int size;
		static const unsigned int N, Ndigit;
		bigint(int x) {
			memset(v, 0, sizeof(v));
			v[0] = x % N , size = 1 , x /= N ;
			while( x != 0 ) v[ size ] = x % N, size++, x /= N ;
		}
		bigint() {
			memset(v, 0, sizeof(v));
			size = 1;
		}

		bigint& operator=( const bigint& x ){
			memset(v, 0, sizeof(v));
			copy( x.v, x.v + x.size, v ) ;
			size = x.size ;
			return *this ;
		}

		bigint& operator=( unsigned int x ){
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
				if( carry >= N )
				{sum.v[ i ] = carry - N , carry = 1 ;}
				else {sum.v[ i ] = carry, carry = 0 ;}
			}
			if( carry > 0 ) { sum.v[ i ] = carry, i += 1 ;}
			sum.size = i;
			return sum ;
		}

		bigint& operator+=(const bigint& x) {
			*this = *this + x ;
			return *this;
		}

		bigint operator*(unsigned int x) {
			bigint multiply = 0 ;
			if( x == 0 ) return multiply ;
			int i = 0 ;
			long long int carry = 0;
			for(i=0; i<size; i++) {
				carry += (long long int)v[i] * x;
				multiply.v[i] = carry%N;
				carry /= N;
			}
			while(carry>0) multiply.v[i] = carry%N, carry /= N, i++ ;
			multiply.size = i ;
			return multiply;
		}

		bigint& operator*=(unsigned int x) {
			*this = *this * x ;
			return *this;
		}

		bigint operator*(const bigint& x) {
			bigint multiply = 0 ;
			int i = 0 ;
			for(i=x.size - 1; i>=0 ; i--) {
				multiply *= N ;
				multiply += *this * x.v[ i ] ;
			}
			return multiply ;
		}

		bigint& operator*=(const bigint& x) {
			*this = *this * x ;
			return *this;
		}
};

const unsigned int bigint::N = 1000000000;
const unsigned int bigint::Ndigit=9;

int
main()
{
	bigint	x ;
	bigint	y ;

	mybigint a ;
	mybigint b ;

	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> x >> y )
	{
		cout << x * y << endl ;
	}

	return 0 ;
}

