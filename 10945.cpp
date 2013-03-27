#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std ;

bool notAlpha( char c )
{
	return isalpha( c ) == 0 ;
}

int main()
{
	string	sentence ;
	
	while( getline( cin, sentence ) && sentence != "DONE" )
	{
		sentence.erase( remove_if( sentence.begin(), sentence.end(), notAlpha ), sentence.end() ) ;
		for( int i = 0 ; i < sentence.size() ; i++ )
			sentence[ i ] = toupper( sentence[ i ] ) ;
		
		string	rev( sentence.rbegin(), sentence.rend() ) ;
		
		if( sentence == rev )
		{
			cout << "You won't be eaten!" << endl ;
		}
		else
		{
			cout << "Uh oh.." << endl ;
		}
	}
	
	return 0 ;
}
