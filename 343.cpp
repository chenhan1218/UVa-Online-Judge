#include <iostream>
#include <iomanip>
using namespace std ;

long long interpretation( int *input, int length, int base )
{
	long long value = 0 ;
	for( int i = 0 ; i < length ; i++ )
	{
		value = value * base + input[ i ] ;
	}
	
	return value ;
}

int char_to_int( char *words, int *numbers )
{
	int temp = 0 ;
	for( int i = 0 ; i < strlen(words) ; i++ )
	{
		temp = (int)words[ i ] - (int)'0' ;
		if( temp >= 0 && temp <= 9 )
		{
			numbers[ i ] = temp ;
		}
		else
		{
			numbers[ i ] = (int)words[ i ] - (int)'A' + 10 ;
		}
	}

	return strlen(words) ;
}

int find_min_base( int *input, int length )
{
	int min_base = 2 ;
	for( int i = 0 ; i < length ; i++ )
	{
		if( input[ i ] + 1 > min_base )
		{
			min_base = input[ i ] + 1 ;
		}
	}

	return min_base ;
}

int main()
{
	const int Length = 100 ;
	char input_X[ Length ], input_Y[ Length ] ;
	int X[ Length ], Y[ Length ] ;
	int len_X = 0, len_Y = 0 ;
	int min_base_X = 0, min_base_Y = 0 ;
	int base_X = 0, base_Y = 0 ;
	int interpretation_X = 0, interpretation_Y = 0 ;
	bool done = 0 ;

	while( cin >> input_X >> input_Y )
	{
		done = 0 ;
		len_X = char_to_int( input_X, X ) ;
		len_Y = char_to_int( input_Y, Y ) ;
		min_base_X = find_min_base( X, len_X ) ;
		min_base_Y = find_min_base( Y, len_Y ) ;

		for( base_X = min_base_X ; base_X <= 36 ; base_X++ )
		{
			interpretation_X = interpretation( X, len_X, base_X ) ;
			for( base_Y = min_base_Y ; base_Y <= 36 ; base_Y++ )
			{
				interpretation_Y = interpretation( Y, len_Y, base_Y ) ;
				if( interpretation_Y >= interpretation_X )
				{
					break ;
				}
			}

			if( interpretation_Y == interpretation_X )
			{
				break ;
			}
		}

		if( interpretation_Y == interpretation_X )
		{
			cout << input_X << " (base " << base_X << ") = " ;
			cout << input_Y << " (base " << base_Y << ")" << endl ;
		}
		else
		{
			cout << input_X << " is not equal to " << input_Y
				 << " in any base 2..36" << endl ;
		}
	}

	return 0 ;
}
