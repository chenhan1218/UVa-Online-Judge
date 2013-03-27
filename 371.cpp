#include <iostream>
using namespace std ;

int cycle( long long input )
{
	int i = 0 ;
	do
	{
		if( input % 2 == 0 )
		{
			input /= 2 ;
		}
		else
		{
			input = input * 3 + 1 ;
		}
		
		i++ ;
	}while( input != 1 ) ;
	
	return i ;
}

int main()
{
	long long L, H , V, S, temp, i;
	while( cin >> L >> H )
	{
		if( L == 0 && H == 0 )
		{
			break ;
		}
		
		if( L > H )
		{
			temp = L ;
			L = H ;
			H = temp ;
		}
		
		V = L ;
		S = 0 ;
		for( i = L ; i <= H ; i++ )
		{
			temp = (long long )cycle( i ) ;
			
			if( temp > S )
			{
				V = i ;
				S = temp ;
			}
		}
		
		cout << "Between " << L << " and " << H << ", "
			<< V << " generates the longest sequence of " << S << " values." << endl ;
	}

	return 0 ;
}
