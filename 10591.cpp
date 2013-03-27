#include <iostream>
#include <set>
using namespace std ;

const int	MaxBuffer = 1000 ;
bool	isHappyStore[ MaxBuffer ] = { 0 } ;

int squareSum( int a )
{
	int	ans = 0 ;
	while( a != 0 )
	{
		ans += ( a % 10 ) * ( a % 10 ) ;
		a /= 10 ;
	}
	
	return ans ;
}

bool isHappy( int a )
{
	if( a >= MaxBuffer )
		a = squareSum( a ) ;
	
	return isHappyStore[ a ] ;
}

int main()
{
	int		testcase = 0 ;
	
	for( int i = 1 ; i < MaxBuffer ; i++ )
	{
		set<int>	s ;
		int		process = i ;
		while( process != 1 )
		{
			if( (s.insert( process )).second == false )
				break ;
			process = squareSum( process ) ;
		}
		
		if( process == 1 )
			isHappyStore[ i ] = true ;
		else
			isHappyStore[ i ] = false ;
	}
	
	cin >> testcase ;
	for( int i = 1 ; i <= testcase ; i++ )
	{
		int		n = 0 ;
		cin >> n ;
		
		cout << "Case #" << i << ": " << n ;
		if( isHappy( n ) == true )
			cout << " is a Happy number." << endl ;
		else
			cout << " is an Unhappy number." << endl ;
	}
	
	return 0 ;
}
