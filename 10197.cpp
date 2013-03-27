#include <iostream>
using namespace std ;

#include <cstring>

int main()
{
	char Conjugation[ 3 ][ 6 ][ 5 ] = {
		"o", "as", "a", "amos", "ais", "am",
		"o", "es", "e", "emos", "eis", "em",
		"o", "es", "e", "imos", "is", "em"} ;
	
	char v1[ 35 ], v2[ 35 ] ;
	char root_v1[ 35 ] ;
	
	char Pronoun[ 6 ][ 12 ] = {	"eu        " ,
								"tu        " ,
                                "ele/ela   " ,
                                "nos       " ,
                                "vos       " ,
                                "eles/elas " } ;

	Pronoun[ 3 ][ 1 ] = (char)243 ;
	Pronoun[ 4 ][ 1 ] = (char)243 ;
	
	int leng_v1 ;
	int loop_times = 0 ;
	
	while( cin >> v1 >> v2)
	{
		loop_times++ ;
		
		leng_v1 = strlen( v1 ) ;
		
		if( loop_times != 1 )
		{
			cout << endl ;
		}
		
		if( leng_v1 >= 2 )
		{
			for( int i = 0 ; i < leng_v1 - 2 ; i++ )
			{
				root_v1[ i ] = v1[ i ] ;
			}
			root_v1[ leng_v1 - 2 ] = '\0' ;
				
			if( v1[ strlen( v1 ) - 2 ] == 'a' && v1[ strlen( v1 ) - 1 ] == 'r')
			{
				cout << v1 << " (to " << v2 << ")" << endl ;
				cout << Pronoun[ 0 ] << root_v1 << Conjugation[ 0 ][ 0 ] << endl ;
				cout << Pronoun[ 1 ] << root_v1 << Conjugation[ 0 ][ 1 ] << endl ;
				cout << Pronoun[ 2 ] << root_v1 << Conjugation[ 0 ][ 2 ] << endl ;
				cout << Pronoun[ 3 ] << root_v1 << Conjugation[ 0 ][ 3 ] << endl ;
				cout << Pronoun[ 4 ] << root_v1 << Conjugation[ 0 ][ 4 ] << endl ;
				cout << Pronoun[ 5 ] << root_v1 << Conjugation[ 0 ][ 5 ] << endl ;
			}
			else if( v1[ strlen( v1 ) - 2 ] == 'e' && v1[ strlen( v1 ) - 1 ] == 'r')
			{
				cout << v1 << " (to " << v2 << ")" << endl ;
				cout << Pronoun[ 0 ] << root_v1 << Conjugation[ 1 ][ 0 ] << endl ;
				cout << Pronoun[ 1 ] << root_v1 << Conjugation[ 1 ][ 1 ] << endl ;
				cout << Pronoun[ 2 ] << root_v1 << Conjugation[ 1 ][ 2 ] << endl ;
				cout << Pronoun[ 3 ] << root_v1 << Conjugation[ 1 ][ 3 ] << endl ;
				cout << Pronoun[ 4 ] << root_v1 << Conjugation[ 1 ][ 4 ] << endl ;
				cout << Pronoun[ 5 ] << root_v1 << Conjugation[ 1 ][ 5 ] << endl ;
			}
			else if( v1[ strlen( v1 ) - 2 ] == 'i' && v1[ strlen( v1 ) - 1 ] == 'r')
			{
				cout << v1 << " (to " << v2 << ")" << endl ;
				cout << Pronoun[ 0 ] << root_v1 << Conjugation[ 2 ][ 0 ] << endl ;
				cout << Pronoun[ 1 ] << root_v1 << Conjugation[ 2 ][ 1 ] << endl ;
				cout << Pronoun[ 2 ] << root_v1 << Conjugation[ 2 ][ 2 ] << endl ;
				cout << Pronoun[ 3 ] << root_v1 << Conjugation[ 2 ][ 3 ] << endl ;
				cout << Pronoun[ 4 ] << root_v1 << Conjugation[ 2 ][ 4 ] << endl ;
				cout << Pronoun[ 5 ] << root_v1 << Conjugation[ 2 ][ 5 ] << endl ;
			}
			else
			{
				cout << v1 << " (to " << v2 << ")" << endl ;
				cout << "Unknown conjugation" << endl ;
			}
		}
		else
		{
			cout << v1 << " (to " << v2 << ")" << endl ;
			cout << "Unknown conjugation" << endl ;
		}
	}

	return 0 ;
}
