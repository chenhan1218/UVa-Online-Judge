#include <iostream>
using namespace std ;

#include <cmath>

int main()
{
	char input , buffer ;
	int ascii_a = static_cast<int>( 'a' ) 
		, ascii_A = static_cast<int>( 'A' ) 
		, ascii_e = static_cast<int>( 'e' ) 
		, ascii_E = static_cast<int>( 'E' ) 
		, ascii_i = static_cast<int>( 'i' ) 
		, ascii_I = static_cast<int>( 'I' ) 
		, ascii_o = static_cast<int>( 'o' ) 
		, ascii_O = static_cast<int>( 'O' ) 
		, ascii_u = static_cast<int>( 'u' ) 
		, ascii_U = static_cast<int>( 'U' ) 
		, ascii_z = static_cast<int>( 'z' ) 
		, ascii_Z = static_cast<int>( 'Z' ) ;

	int rule_now = 0 , ascii_input ;

	while( cin.get( input ) )
	{
		ascii_input = static_cast<int>( input ) ;

		if( rule_now == 1 )
		{
			if( ascii_input <= ascii_z && ascii_input >= ascii_a )
			{
				cout << input ;
			}
			else if( ascii_input <= ascii_Z && ascii_input >= ascii_A )
			{
				cout << input ;
			}
			else
			{
				cout << "ay" << input ;
				rule_now = 0 ;
			}
		}
		else if( rule_now == 2 )
		{
			if( ascii_input <= ascii_z && ascii_input >= ascii_a )
			{
				cout << input ;
			}
			else if( ascii_input <= ascii_Z && ascii_input >= ascii_A )
			{
				cout << input ;
			}
			else
			{
				cout << buffer << "ay" << input ;
				rule_now = 0 ;
			}
		}
		else
		{
			if( ascii_input <= ascii_z && ascii_input >= ascii_a )
			{
				if( ascii_input == ascii_a || ascii_input == ascii_e 
					|| ascii_input == ascii_i || ascii_input == ascii_o 
					|| ascii_input == ascii_u  )
				{
					cout << input ;
					rule_now = 1 ;
				}
				else
				{
					buffer = input ;
					rule_now = 2 ;
				}
			}
			else if( ascii_input <= ascii_Z && ascii_input >= ascii_A )
			{
				if( ascii_input == ascii_A || ascii_input == ascii_E 
					|| ascii_input == ascii_I || ascii_input == ascii_O 
					|| ascii_input == ascii_U  )
				{
					cout << input ;
					rule_now = 1 ;
				}
				else
				{
					buffer = input ;
					rule_now = 2 ;
				}
			}
			else
			{
				cout << input ;
			}
		}
	}

	return 0 ;
}
