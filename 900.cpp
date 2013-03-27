#include <iostream>
using namespace std ;

int main()
{
	int length ;
	long long patterns[ 52 ] = { 0 } ;
	patterns[ 1 ] = 1 ;
	patterns[ 2 ] = 2 ;
	
	for( length = 3 ; length <= 51 ; length++ )
	{
		patterns[ length ] = patterns[ length - 1 ] + patterns[ length - 2 ] ;
	}
	
	while( cin >> length )
	{
		if( length == 0 )
		{
			break ;
		}
		
		cout << patterns[ length ] << endl ;
	}

	return 0 ;
}
