#include <iostream>
using namespace::std;

int main()
{
	long int i , j ;

	long int temp ;
	long int counter ;
	long int largest = 0 ;
	int shit = 0 ;

	while( cin >> i >> j )
	{
		shit = 0 ;
		if( j < i )
		{
			shit = i ;
			i = j ;
			j = shit ;

			shit = 1 ;
		}

		largest = 0 ;

		for( int k = i ; k <= j ; k++ )
		{
			temp = k ;
			counter = 1 ;

			while( temp != 1 )
			{
				if( temp & 0x0001 )
					temp = 3 * temp + 1 ;
				else
					temp >>= 1  ;

				counter++;
			}

			if( largest < counter )
				largest = counter ;
		}

		if( shit == 0 )
			cout << i << " " << j << " " << largest << endl ;
		else
			cout << j << " " << i << " " << largest << endl ;
	}

	return 0 ;
}
