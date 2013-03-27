#include <iostream>
#include <string>
#include <bitset>
using namespace std ;

int main()
{
	int		t = 0 ;
	string	hex1 ;
	string	hex2 ;
	int		v1 = 0 ;
	int		v2 = 0 ;
	bitset<13>	b1 ;
	bitset<13>	b2 ;
	char	op ;
	int		i = 0 ;
	
	cin >> t ;
	while( t > 0 )
	{
		t-- ;
		cin >> hex1 >> op >> hex2 ;
		sscanf( hex1.c_str(), "%x", &v1 ) ;
		sscanf( hex2.c_str(), "%x", &v2 ) ;
		b1 = bitset<13>( v1 ) ;
		b2 = bitset<13>( v2 ) ;
		
		if( op == '+' )
		{
			cout << b1 << " + " << b2 
				<< " = " << v1 + v2 << endl ;
		}
		else
		{
			cout << b1 << " - " << b2 
				<< " = " << v1 - v2 << endl ;
		}
	}
	
	return 0 ;
}

