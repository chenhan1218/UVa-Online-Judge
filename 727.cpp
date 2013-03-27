#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <map>
using namespace std ;

map<char,int> m ;

bool precede( char a, char b )
{
	return m[ a ] >= m[ b ] ;
}

int
main()
{
	stack<char>	s ;
	string	buffer ;
	string	postorder ;
	int		testcase = 0 ;
	bool	firstcase = true ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	//define order
	m[ '(' ] = 1 ;
	m[ ')' ] = 2 ;
	m[ '+' ] = 3 ;
	m[ '-' ] = 3 ;
	m[ '*' ] = 4 ;
	m[ '/' ] = 4 ;

	getline( cin, buffer ) ;
	testcase = atoi( buffer.c_str() ) ;
	getline( cin, buffer ) ;

	while( testcase > 0 )
	{
		testcase -- ;
		postorder.clear() ;

		while( getline( cin, buffer ) && buffer.size() > 0 )
		{
			if( isdigit( buffer[ 0 ] ) == true )
			{
				postorder += buffer[ 0 ] ;
			}
			else if( buffer[ 0 ] == '(' )
			{
				s.push( buffer[ 0 ] ) ;
			}
			else
			{
				while( s.empty() == false && precede( s.top(), buffer[ 0 ] ) == true )
				{
					postorder += s.top() ;
					s.pop() ;
				}

				if( buffer[ 0 ] == ')' && 
					s.empty() == false && s.top() == '(' )
				{
					s.pop() ;
				}
				else
				{
					s.push( buffer[ 0 ] ) ;
				}
			}
		}

		while( s.empty() == false )
		{
			postorder += s.top() ;
			s.pop() ;
		}

		if( firstcase == true )
			firstcase = false ;
		else
			cout << endl ;

		cout << postorder << endl ;
	}

	return 0 ;
}
