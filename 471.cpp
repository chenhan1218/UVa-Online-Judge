#include <iostream>
#include <string>
using namespace std ;

string itoa( long long int a )
{
	string	str ;
	
	do
	{
		str += '0' + a%10 ;
		a /= 10 ;
	} while( a != 0 ) ;
	
	return str ;
}

bool isRepeat( string a )
{
	int		i = 0 ;
	for( i = 0 ; i < a.size() ; i++ )
	{
		if( a.find( a[ i ], i+1 ) != string::npos )
		{
			return true ;
		}
	}
	
	return false ;
}

int main()
{
	long long int	n = 0 ;
	long long int	numerator = 0 ;
	long long int	_9999999999 = 0 ;
	int		cases = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	_9999999999 = 99999 ;
	_9999999999 = _9999999999 * 100000 + 99999 ;
	
	cin >> cases ;
	for( i = 0 ; i < cases ; i++ )
	{
		if( i != 0 )
		{
			cout << endl ;
		}
		
		cin >> n ;
		for( j = 1, numerator = n ; numerator <= _9999999999 ; j++, numerator += n )
		{
			if( isRepeat( itoa( j ) ) == false && isRepeat( itoa( numerator ) ) == false )
			{
				cout << numerator << " / " << j << " = " << n << endl ;
			}
		}
	}
	
	return 0 ;
}
