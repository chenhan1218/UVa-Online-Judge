#include <iostream>
#include <stack>
#include <string>
using namespace std ;

int main()
{
	stack<char>	s ;
	string	input ;
	int		t = 0 ;
	int		i = 0 ;

	getline( cin, input ) ;
	t = atoi( input.c_str() ) ;
	while( t > 0 )
	{
		t-- ;
		getline( cin, input ) ;

		while( s.size() > 0 )
			s.pop() ;

		for( i = 0 ; i < input.size() ; i++ )
		{
			if( input[ i ] == '(' || input[ i ] == '[' )
			{
				s.push( input[ i ] ) ;
			}
			else if( input[ i ] == ')' )
			{
				if( s.size() == 0 || s.top() != '(' )
					break ;
				else
					s.pop() ;
			}
			else
			{
				if( s.size() == 0 || s.top() != '[' )
					break ;
				else
					s.pop() ;
			}
		}

		if( i < input.size() || s.size() > 0 )
		{
			cout << "No" << endl ;
		}
		else
		{
			cout << "Yes" << endl ;
		}
	}

	return 0 ;
}

