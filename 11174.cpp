#include <iostream>
#include <iomanip>
using namespace std ;

#define mod 1000000007
#define Max_n 40000
#define TRUE 1
#define FALSE 0

class Child
{
	public:
		Child() ;
		int		value ;
		Child*	next ;
};

Child::Child()
{
	value = 0 ;
	next = NULL ;
}

long long	factorial[ Max_n + 1 ] ;
long long	factorialInverse[ Max_n + 1 ] ;
long long 	ways[ Max_n + 1 ] ;	// ways[ i ] mean if i is in the first of the 
								//line, how many different ways could it be.
bool 		beingChild[ Max_n + 1 ] ;
Child*		childList[ Max_n + 1 ] ;
int			descendantNumber[ Max_n + 1 ] ;

long long inverseElement( long long i, long long ModBase )
{
	if( i == 1 )
	{
		return 1 ;
	}

	// Use math equation. a = bq + r
	long long	quotient[ 100 ] = { 0 } ; // There are at most 100 quotients.
	long long 	a = ModBase ;
	long long	b = i ;
	long long	r = 0 ;
	int			j = 0 ; // loop counter

	while( r != 1 )
	{
		quotient[ j ] = a / b ;
		r = a % b ;
		a = b ;
		b = r ;
		j++ ;
	}

	if( j == 1 ) 	// With one operation, we get r = 1,
					// that is a = bq + 1, the inverse element is mod - q
	{
		return ModBase - quotient[ 0 ] ;
	}
	else
	{
		quotient[ j ] = 1 ;
		quotient[ j - 1 ] *= -1 ;
		j = j - 2 ;
		while( j >= 0 )
		{
			quotient[ j ] = quotient[ j + 2 ] - quotient[ j ] * quotient[ j + 1 ] ;
			j-- ;
		}

		if( quotient[ 0 ] < 0 )
		{
			return ModBase + quotient[ 0 ] ;
		}
		else
		{
			return quotient[ 0 ] ;
		}
	}
}

void setFactorial()
{
	long long	i = 0 ; // loop counter
	factorial[ 0 ] = 1 ;
	factorialInverse[ 0 ] = 1 ;

	for( i = 1 ; i <= Max_n ; i++ )
	{
		factorial[ i ] = factorial[ i - 1 ] * i ;
		factorial[ i ] %= mod ;

		factorialInverse[ i ] = inverseElement( factorial[ i ] ,mod ) ;
	}
}

void initial( int n )
{
	int		i = 0 ; // loop counter

	for( i = 1 ; i <= n ; i++ )
	{
		ways[ i ] = 0 ;
		beingChild[ i ] = FALSE ;
		descendantNumber[ i ] = 0 ;
	}
}

void delocate( int n )
{
	int		i = 0 ; // loop counter
	Child*	temp ;

	for( i = 1 ; i <= n ; i++ )
	{
		while( childList[ i ] != NULL )
		{
			temp = childList[ i ] ;
			childList[ i ] = temp->next ;

			delete temp ;
		}
	}
}

long long C( int a, int b )
{
	long long	returnValue = 1 ;
	int			i = 0 ; // loop counter

	if( b > a / 2 )
	{
		b = a - b ;
	}

	for( i = 1 ; i <= b ; i++ )
	{
		returnValue *= a - i + 1 ;
		returnValue %= mod ;

		returnValue *= inverseElement( i, mod ) ;
		returnValue %= mod ;
	}

	return returnValue ;
}

void calculateWays( int i )
{
	Child*	childPtr = childList[ i ] ;

	descendantNumber[ i ] = 0 ;
	ways[ i ] = 1 ;

	while( childPtr != NULL )
	{
		calculateWays( childPtr->value ) ;
		ways[ i ] *= factorialInverse[ descendantNumber[ childPtr->value ] + 1 ] ;
		ways[ i ] %= mod ;
		ways[ i ] *= ways[ childPtr->value ] ;
		ways[ i ] %= mod ;

		descendantNumber[ i ] += descendantNumber[ childPtr->value ] + 1 ;

		childPtr = childPtr->next ;
	}

	ways[ i ] *= factorial[ descendantNumber[ i ] ] ;
	ways[ i ] %= mod ;
}

int
main()
{
	int		T = 0 ;
	int		n = 0 ;
	int		m = 0 ;
	int		a = 0 ;
	int		b = 0 ;
	long long	output = 0 ;
	Child	*temp = NULL ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	setFactorial() ;

	cin >> T ;

	for( i = 1 ; i <= T ; i++ )
	{
		cin >> n >> m ;

		initial( n ) ;

		for( j = 1 ; j <= m ; j++ )
		{
			//two integers a and b denoting that b is the father of a.
			cin >> a >> b ;

			temp = new Child() ;
			temp->next = childList[ b ] ;
			temp->value = a ;
			childList[ b ] = temp ;

			beingChild[ a ] = TRUE ;
		}

		descendantNumber[ 0 ] = 0 ;
		output = 1 ;
		for( j = 1 ; j <= n ; j++ )
		{
			if( beingChild[ j ] == FALSE )
			{
				calculateWays( j ) ;
				output *= factorialInverse[ descendantNumber[ j ] + 1 ] ;
				output %= mod ;
				output *= ways[ j ] ;
				output %= mod ;

				descendantNumber[ 0 ] += descendantNumber[ j ] + 1 ;
			}
		}

		output *= factorial[ descendantNumber[ 0 ] ] ;
		output %= mod ;

		cout << output << endl ;
		//For each test case the output contains a single line denoting the 
		//number of different ways the soldier can stand in a single line.

		delocate( n ) ;
	}

	return 0 ;
}
