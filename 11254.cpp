/* http://www.mathpages.com/home/kmath107.htm

Partitions into Consecutive Integers

For any positive integer N, let f(N) denote the number of ways in
which n can be expressed as the sum of consecutive positive integers.
For example, since 9 can be expressed as 2+3+4 and as 4+5 and as 9,
we have f(9)=3.

The sum of the integers from 1 to n is n(n+1)/2, so we're looking 
for the number of ways in which a given integer N can be expressed 
in the form 
                  N = n(n+1)/2 - m(m+1)/2                   (1)

for a positive integer n and non-negative integer m.  Solving this 
for m gives
                        ____________________
                  -1 + / 1 - 4[2N - n(n+1)]
          m   =   ---------------------------
                                2

which implies that the quantity inside the square root must be a 
square integer.  Thus there is an integer u such that

           4n^2 + 4n + 1 - 8N - u^2  =  0

Clearly u must be odd.  Solving this for n gives
                             _________
                       -1 + / 8N + u^2
                n  =   ----------------
                                2

Again, this requires that the quantity inside the square root is a 
square integer, so we have an integer v such that

            8N  =  v^2 - u^2  =  (v-u)(v+u)

and since u is odd, v must also be odd.  Thus we can write this in 
the form
               2N  =  [(v-u)/2] [(v+u)/2]

So we are looking for ways of factoring 2N into two factors, A=(v-u)/2 
and B=(v+u)/2 with odd integers u,v.  We have v=A+B and u=B-A, so A 
and B must have opposite parity, i.e., one is odd and one is even.  
Thus, the integers A,B give a solution if and only if 2N = AB and one 
of A,B is odd and the other is even.  Clearly this occurs for any odd 
divisor d of N, which let's us take A=d and B=2N/d (or vice versa, 
which ever give B > A).  Consequently, the number of ways of expressing 
N as a sum of consecutive positive integers is equal to the number of 
odd divisors of N.

For example, there are three odd divisors of N=9, namely 1, 3, and 9, 
so we have f(9) = 3, corresponding to the three solutions

          A   B     v   u     n   m       expression
         --- ---   --- ---   --- ---     -------------
          1   18    19  17     9  8        9
          3    6     9   3     4  1        2+3+4
          2    9    11   7     5  3        4+5
      
Incidentally, if we let F(N) denote the number of ways of expressing 
N  as the sum of consecutive integers, without requiring that they be
positive integers, then clearly F(N) = 2f(N), because for any sum of
consecutive integers extending from -m to n the total is again given
by equation (1), and for each solution that ranges from m+1 to n
there corresponds an equivalent solution ranging from -m to n.

Return to MathPages Main Menu 
*/

#include <iostream>
#include <vector>
using namespace std ;

#define MaxPrime 31700

int			previous[ MaxPrime + 1 ] = { 0 } ;
int			next[ MaxPrime + 1 ] = { 0 } ;

void initial( long long int n )
{
	long long int	i = 0 ; // loop counter

	previous[ 2 ] = -1 ;
	next[ 2 ] = 3 ;
	previous[ 3 ] = 2 ;
	next[ 3 ] = 5 ;
	for( i = 3 ; i <= n ; i += 2 )
	{
		previous[ i ] = i - 2 ;
		next[ i ] = i + 2 ;
	}
}

void remove( int x )
{
	next[ previous[ x ] ] = next[ x ] ;
	previous[ next[ x ] ] = previous[ x ] ;

	previous[ x ] = 0 ;
	next[ x ] = 0 ;
}

void cal( long long int n )
{
	long long int	numPrimes = 0 ;
	long long int	prime = 0 ;
	long long int	fact = 0 ;
	long long int	mult = 0 ;

	initial( n ) ;

	for( prime = 3 ; prime * prime <= n ; prime = next[ prime ] )
	{
		for( fact = prime ; prime * fact <= n ; fact = next[ fact ] )
		{
			for( mult = prime * fact ; mult <= n ; mult *= prime )
			{
				remove( mult ) ;
			}
		}
	}
}

vector<long long int> oddDivisors( long long int n )
{
	long long int	prime = 0 ;
	vector<long long int>	v ;
	
	while( n % 2 == 0 )
	{
		n /= 2 ;
	}
	
	for( prime = 3 ; prime * prime <= n ; prime = next[ prime ] )
	{
		if( n % prime == 0 )
		{
			v.push_back( prime ) ;
			while( n % prime == 0 )
			{
				n /= prime ;
			}
		}
	}
	
	if( n != 1 )
		v.push_back( n ) ;
	
	return v ;
}

void find_ab( long long int n, vector<long long int> &v, long long int iter, long long int divisor, long long int &b )
{
	int		i = 0 ; // loop counter
	int		power = 0 ;
	
	if( iter == v.size() )
	{
		if( n*2/divisor > divisor )
		{
			if( b < divisor )
			{
				b = divisor ;
			}
		}
		else
		{
			if( b < n*2/divisor )
			{
				b = n*2/divisor ;
			}
		}
		
		return ;
	}
	
	for( power = 1 ; n % power == 0 ; power *= v[ iter ] )
	{
		find_ab( n, v, iter+1, divisor * power, b ) ;
	}
}

int main()
{
	long long int		n = 0 ;
	long long int		a = 0 ;
	long long int		b = 0 ;
	long long int		A = 0 ;
	long long int		B = 0 ;
	vector<long long int>	v ;
	
	cal( MaxPrime ) ;
	
	while( cin >> n && n != -1 )
	{
		v = oddDivisors( n ) ;
		b = 1 ;
		find_ab( n, v, 0, 1, b ) ;
		
		a = n * 2 / b ;
		B = ( a + b - 1 ) / 2 ;
		A = ( a - b + 1 ) / 2 ;
		cout << n << " = " << A << " + ... + " << B << endl ;
	}
	
	return 0 ;
}
