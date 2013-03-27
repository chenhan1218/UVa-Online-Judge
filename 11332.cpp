#include <iostream>
using namespace std ;

long long int f( long long int a )
{
	long long int	ret = 0 ;
	do
	{
		ret += a%10 ;
		a /= 10 ;
	} while( a != 0 ) ;
	
	return ret ;
}

int main()
{
	long long int	n = 0 ;
	
	while( cin >> n && n != 0 )
	{
		while( n >= 10 )
		{
			n = f( n ) ;
		}
		
		cout << n << endl ;
	}
	
	return 0 ;
}
