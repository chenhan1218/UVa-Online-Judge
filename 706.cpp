#include <iostream>
using namespace std ;

#include <cstring>

char output[ 10 ][ 7 ] ;

void initial_output_element()
{
	output[ 0 ][ 0 ] = '-' ;
	output[ 0 ][ 1 ] = '|' ;
	output[ 0 ][ 2 ] = '|' ;
	output[ 0 ][ 3 ] = ' ' ;
	output[ 0 ][ 4 ] = '|' ;
	output[ 0 ][ 5 ] = '|' ;
	output[ 0 ][ 6 ] = '-' ;

	output[ 1 ][ 0 ] = ' ' ;
	output[ 1 ][ 1 ] = ' ' ;
	output[ 1 ][ 2 ] = '|' ;
	output[ 1 ][ 3 ] = ' ' ;
	output[ 1 ][ 4 ] = ' ' ;
	output[ 1 ][ 5 ] = '|' ;
	output[ 1 ][ 6 ] = ' ' ;

	output[ 2 ][ 0 ] = '-' ;
	output[ 2 ][ 1 ] = ' ' ;
	output[ 2 ][ 2 ] = '|' ;
	output[ 2 ][ 3 ] = '-' ;
	output[ 2 ][ 4 ] = '|' ;
	output[ 2 ][ 5 ] = ' ' ;
	output[ 2 ][ 6 ] = '-' ;

	output[ 3 ][ 0 ] = '-' ;
	output[ 3 ][ 1 ] = ' ' ;
	output[ 3 ][ 2 ] = '|' ;
	output[ 3 ][ 3 ] = '-' ;
	output[ 3 ][ 4 ] = ' ' ;
	output[ 3 ][ 5 ] = '|' ;
	output[ 3 ][ 6 ] = '-' ;

	output[ 4 ][ 0 ] = ' ' ;
	output[ 4 ][ 1 ] = '|' ;
	output[ 4 ][ 2 ] = '|' ;
	output[ 4 ][ 3 ] = '-' ;
	output[ 4 ][ 4 ] = ' ' ;
	output[ 4 ][ 5 ] = '|' ;
	output[ 4 ][ 6 ] = ' ' ;

	output[ 5 ][ 0 ] = '-' ;
	output[ 5 ][ 1 ] = '|' ;
	output[ 5 ][ 2 ] = ' ' ;
	output[ 5 ][ 3 ] = '-' ;
	output[ 5 ][ 4 ] = ' ' ;
	output[ 5 ][ 5 ] = '|' ;
	output[ 5 ][ 6 ] = '-' ;

	output[ 6 ][ 0 ] = '-' ;
	output[ 6 ][ 1 ] = '|' ;
	output[ 6 ][ 2 ] = ' ' ;
	output[ 6 ][ 3 ] = '-' ;
	output[ 6 ][ 4 ] = '|' ;
	output[ 6 ][ 5 ] = '|' ;
	output[ 6 ][ 6 ] = '-' ;

	output[ 7 ][ 0 ] = '-' ;
	output[ 7 ][ 1 ] = ' ' ;
	output[ 7 ][ 2 ] = '|' ;
	output[ 7 ][ 3 ] = ' ' ;
	output[ 7 ][ 4 ] = ' ' ;
	output[ 7 ][ 5 ] = '|' ;
	output[ 7 ][ 6 ] = ' ' ;

	output[ 8 ][ 0 ] = '-' ;
	output[ 8 ][ 1 ] = '|' ;
	output[ 8 ][ 2 ] = '|' ;
	output[ 8 ][ 3 ] = '-' ;
	output[ 8 ][ 4 ] = '|' ;
	output[ 8 ][ 5 ] = '|' ;
	output[ 8 ][ 6 ] = '-' ;

	output[ 9 ][ 0 ] = '-' ;
	output[ 9 ][ 1 ] = '|' ;
	output[ 9 ][ 2 ] = '|' ;
	output[ 9 ][ 3 ] = '-' ;
	output[ 9 ][ 4 ] = ' ' ;
	output[ 9 ][ 5 ] = '|' ;
	output[ 9 ][ 6 ] = '-' ;
}

void LC_Display( char *input , int length_input , int s )
{
	int n[ 10 ] = { 0 } ;

	for( int j = 0 ; j < length_input ; j++ )
	{
		switch( input[ j ] )
		{
			case '0' :
				n[ j ] = 0 ;
				break ;

			case '1' :
				n[ j ] = 1 ;
				break ;

			case '2' :
				n[ j ] = 2 ;
				break ;

			case '3' :
				n[ j ] = 3 ;
				break ;

			case '4' :
				n[ j ] = 4 ;
				break ;

			case '5' :
				n[ j ] = 5 ;
				break ;

			case '6' :
				n[ j ] = 6 ;
				break ;

			case '7' :
				n[ j ] = 7 ;
				break ;

			case '8' :
				n[ j ] = 8 ;
				break ;

			case '9' :
				n[ j ] = 9 ;
				break ;
		}
	}

	/* Print the first line. */
	for( int j = 0 ; j < length_input ; j++ )
	{
		// In order to separate each digit, we print a blank.
		if( j >= 1 )
		{
			cout << " " ;
		}

		// Following is a row of one digit.
		cout << " " ;
		for( int b = 1 ; b <= s ; b++ )
		{
			cout << output[ n[ j ] ][ 0 ] ;
		}
		cout << " " ;
		// End of a row of one digit.
	}
	cout << endl ;

	/* Print the second section. */
	for( int a = 1 ; a <= s ; a++ )
	{
		for( int j = 0 ; j < length_input ; j++ )
		{
			// In order to separate each digit, we print a blank.
			if( j >= 1 )
			{
				cout << " " ;
			}

			// Following is a row of one digit.
			cout << output[ n[ j ] ][ 1 ] ;
			for( int b = 1 ; b <= s ; b++ )
			{
				cout << " " ;
			}
			cout << output[ n[ j ] ][ 2 ] ;
		}
		cout << endl ;
	}

	/* Print the third section. */
	for( int j = 0 ; j < length_input ; j++ )
	{
		// In order to separate each digit, we print a blank.
		if( j >= 1 )
		{
			cout << " " ;
		}

		// Following is a row of one digit.
		cout << " " ;
		for( int b = 1 ; b <= s ; b++ )
		{
			cout << output[ n[ j ] ][ 3 ] ;
		}
		cout << " " ;
	}
	cout << endl ;

	/* Print the fourth section. */
	for( int a = 1 ; a <= s ; a++ )
	{
		for( int j = 0 ; j < length_input ; j++ )
		{
			// In order to separate each digit, we print a blank.
			if( j >= 1 )
			{
				cout << " " ;
			}

			// Following is a row of one digit.
			cout << output[ n[ j ] ][ 4 ] ;
			for( int b = 1 ; b <= s ; b++ )
			{
				cout << " " ;
			}
			cout << output[ n[ j ] ][ 5 ] ;
		}
		cout << endl ;
	}

	/* Print the fifth section. */
	for( int j = 0 ; j < length_input ; j++ )
	{
		// In order to separate each digit, we print a blank.
		if( j >= 1 )
		{
			cout << " " ;
		}

		// Following is a row of one digit.
		cout << " " ;
		for( int b = 1 ; b <= s ; b++ )
		{
			cout << output[ n[ j ] ][ 6 ] ;
		}
		cout << " " ;
	}
	cout << endl ;
}

int main()
{
	initial_output_element() ;

	int s ;
	char input[ 10 ] ;

	while( cin >> s >> input )
	{
		if( s == 0 )
		{
			break ;
		}
		
		LC_Display( input , strlen( input ) , s ) ;
		cout << endl ; // Output a blank line after each number.
	}

	return 0 ;
}
