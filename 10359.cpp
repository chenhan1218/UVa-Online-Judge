/*
#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxN 250

class bigint {
	public:
		unsigned int v[1000];
		int size;
		static const unsigned int N, Ndigit;
		bigint(int x) {
			memset(v, 0, sizeof(v));
			v[0] = x;
			size = 1;
		}
		bigint() {
			memset(v, 0, sizeof(v));
			size = 0;
		}

		bigint& operator=(unsigned int x) {
			memset(v, 0, sizeof(v));
			v[ 0 ] = x ;
			size = 1;
			return *this;
		}

		bigint& operator=(const bigint& x) {
			memset(v, 0, sizeof(v));
			for(int i=0; i<x.size; i++) {
				v[i] = x.v[i];
			}
			size = x.size;
			return *this;
		}

		bigint& operator+=(const bigint& x) {
			for(int i=0; i<x.size; i++) {
				v[i] += x.v[i];
				if(v[i] >= N) v[i]-=N, v[i+1]++;
			}
			size = max(size, x.size);
			if(v[size]!=0) size++;
			return *this;
		}
		bigint& operator*=(unsigned int x) {
			unsigned long long carry = 0;
			for(int i=0; i<size; i++) {
				carry += ((unsigned long long)v[i])*x;
				v[i] = carry%N;
				carry /= N;
			}
			if(carry>0) v[size++] = carry;
			return *this;
		}
		bigint& operator/=(unsigned int x) {
			unsigned long long r=0;
			for(int i=size-1; i>=0; i--) {
				unsigned long long a=r*N+v[i];
				v[i] = a/x;
				r = a%x;
			}
			if(v[size-1]==0) size--;
			return *this;
		}
};

const unsigned int bigint::N = 1000000000;
const unsigned int bigint::Ndigit=9;

ostream& operator<<(ostream& os, const bigint& b) {
	os << b.v[b.size-1];
	for(int i=b.size-2; i>=0; i--) 
		os << setw(bigint::Ndigit) << setfill('0') << b.v[i];
	return os;
}

int
main()
{
	bigint	possibleTilings[ MaxN + 1 ] ;
	int		n = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	possibleTilings[ 0 ] = 1 ;
	possibleTilings[ 1 ] = 1 ;
	possibleTilings[ 2 ] = 3 ;

	for( i = 3 ; i <= MaxN ; i++ )
	{
		possibleTilings[ i ] += possibleTilings[ i - 2 ] ;
		possibleTilings[ i ] *= 2 ;
		possibleTilings[ i ] += possibleTilings[ i - 1 ] ;
	}

	while( cin >> n )
	{
		cout << possibleTilings[ n ] << endl ;
	}

	return 0 ;
}*/

#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

#define MaxN 250

const int	MaxDigits = 1000000 ;
char	op1[ MaxDigits + 1 ] ;
char	op2[ MaxDigits + 1 ] ;
void addString( string *a, string *b )
{
	int		buffer = 0 ;
	int		carryIn = 0 ;
	int		i = 0 ; // loop counter

	// store the largerer number into op1, the smaller number into op2.
	if( a->length() > b->length() )
	{
		reverse_copy( a->begin(), a->end(), op1 ) ;
		op1[ a->length() ] = '\0' ;
		reverse_copy( b->begin(), b->end(), op2 ) ;
		op2[ b->length() ] = '\0' ;
	}
	else if( a->length() == b->length() && a->compare( *b ) >= 0 )
	{
		reverse_copy( a->begin(), a->end(), op1 ) ;
		op1[ a->length() ] = '\0' ;
		reverse_copy( b->begin(), b->end(), op2 ) ;
		op2[ b->length() ] = '\0' ;
	}
	else
	{
		reverse_copy( b->begin(), b->end(), op1 ) ;
		op1[ b->length() ] = '\0' ;
		reverse_copy( a->begin(), a->end(), op2 ) ;
		op2[ a->length() ] = '\0' ;
	}

	// add op2 into op1
	for( i = 0 ; op2[ i ] != '\0' ; i++ )
	{
		buffer = ( op1[ i ] - '0' ) + ( op2[ i ] - '0' ) + carryIn ;
		if( buffer >= 10 )
		{
			op1[ i ] = buffer - 10 + '0' ;
			carryIn = 1 ;
		}
		else
		{
			op1[ i ] = buffer + '0' ;
			carryIn = 0 ;
		}
	}

	for( ; i < a->length() && carryIn != 0 ; i++ )
	{
		buffer = ( op1[ i ] - '0' ) + carryIn ;
		if( buffer >= 10 )
		{
			op1[ i ] = buffer - 10 + '0' ;
			carryIn = 1 ;
		}
		else
		{
			op1[ i ] = buffer + '0' ;
			carryIn = 0 ;
		}
		i++ ;
	}

	if( i >= a->length() && carryIn > 0 )
	{
		op1[ i ] = carryIn + '0' ;
		op1[ i + 1 ] = '\0' ;
	}

	reverse( op1, op1 + strlen(op1) ) ;
	a->assign( op1 ) ;
}

int
main()
{
	string	possibleTilings[ MaxN + 1 ] ;
	int		n = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	possibleTilings[ 0 ].assign("1") ;
	possibleTilings[ 1 ].assign("1") ;
	possibleTilings[ 2 ].assign("3") ;

	for( i = 3 ; i <= MaxN ; i++ )
	{
		possibleTilings[ i ].assign("0") ;
		addString( &possibleTilings[ i ], &possibleTilings[ i - 2 ] ) ;
		addString( &possibleTilings[ i ], &possibleTilings[ i - 2 ] ) ;
		addString( &possibleTilings[ i ], &possibleTilings[ i - 1 ] ) ;
	}

	while( cin >> n )
	{
		cout << possibleTilings[ n ] << endl ;
	}

	return 0 ;
}

