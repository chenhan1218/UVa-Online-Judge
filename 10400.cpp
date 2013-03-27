#include <iostream>
#include <string>
#include <bitset>
using namespace std ;

#define MaxP 100

bitset<32000*2+1>	visited[ MaxP ] ;
int		p = 0 ;
int		seq[ MaxP ] = { 0 } ;
int		target = 0 ;
string	result ;

string itoa( long long int a )
{
	string	str ;
	do
	{
		str.insert( 0, 1, '0' + a%10 ) ;
		a /= 10 ;
	} while( a != 0 ) ;
	
	return str ;
}

void dfs( int d, int value, string str )
{
	if( d == p )
	{
		if( value == target )
		{
			result = str ;
		}
	}
	else
	{
		if( value <= 32000 && value >= -32000 && visited[ d ][ value + 32000 ] == 0 )
		{
			visited[ d ][ value + 32000 ] = 1 ;
			
			if( result == "" )
				dfs( d+1, value + seq[ d ], str + '+' + itoa( seq[ d ] ) ) ;
			if( result == "" )
				dfs( d+1, value - seq[ d ], str + '-' + itoa( seq[ d ] ) ) ;
			if( result == "" )
				dfs( d+1, value * seq[ d ], str + '*' + itoa( seq[ d ] ) ) ;
			if( result == "" && value % seq[ d ] == 0 )
				dfs( d+1, value / seq[ d ], str + '/' + itoa( seq[ d ] ) ) ;
		}
	}
}

int main()
{
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	cin >> casenum ;
	for( runningCase = 0 ; runningCase < casenum ; runningCase++ )
	{
		cin >> p ;
		for( i = 0 ; i < p ; i++ )
		{
			cin >> seq[ i ] ;
		}
		cin >> target ;
		
		result = "" ;
		for( i = 0 ; i < MaxP ; i++ )
		{
			visited[ i ].reset() ;
		}
		visited[ 0 ][ seq[ 0 ] + 32000 ] = 1 ;
		dfs( 1, seq[ 0 ], itoa( seq[ 0 ] ) ) ;
		
		if( result == "" )
		{
			cout << "NO EXPRESSION" << endl ;
		}
		else
		{
			cout << result << "=" << target << endl ;
		}
	}
	
	return 0 ;
}

// AC but low rank version
/*
#include <iostream>
#include <string>
#include <map>
using namespace std ;

#define MaxP 100

map<int,bool>	visited[ MaxP ] ;
int		p = 0 ;
int		seq[ MaxP ] = { 0 } ;
int		target = 0 ;
string	result ;

string itoa( long long int a )
{
	string	str ;
	do
	{
		str.insert( 0, 1, '0' + a%10 ) ;
		a /= 10 ;
	} while( a != 0 ) ;
	
	return str ;
}

void dfs( int d, int value, string str )
{
	if( d == p )
	{
		if( value == target )
		{
			result = str ;
		}
	}
	else
	{
		if( value <= 32000 && value >= -32000 && visited[ d ][ value ] == false )
		{
			visited[ d ][ value ] = true ;
			
			if( result == "" )
				dfs( d+1, value + seq[ d ], str + '+' + itoa( seq[ d ] ) ) ;
			if( result == "" )
				dfs( d+1, value - seq[ d ], str + '-' + itoa( seq[ d ] ) ) ;
			if( result == "" )
				dfs( d+1, value * seq[ d ], str + '*' + itoa( seq[ d ] ) ) ;
			if( result == "" && value % seq[ d ] == 0 )
				dfs( d+1, value / seq[ d ], str + '/' + itoa( seq[ d ] ) ) ;
		}
	}
}

int main()
{
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	cin >> casenum ;
	for( runningCase = 0 ; runningCase < casenum ; runningCase++ )
	{
		cin >> p ;
		for( i = 0 ; i < p ; i++ )
		{
			cin >> seq[ i ] ;
		}
		cin >> target ;
		
		result = "" ;
		for( i = 0 ; i < MaxP ; i++ )
		{
			visited[ i ].clear() ;
		}
		visited[ 0 ][ seq[ 0 ] ] = true ;
		dfs( 1, seq[ 0 ], itoa( seq[ 0 ] ) ) ;
		
		if( result == "" )
		{
			cout << "NO EXPRESSION" << endl ;
		}
		else
		{
			cout << result << "=" << target << endl ;
		}
	}
	
	return 0 ;
}
*/

/* still a slow version
#include <iostream>
#include <map>
#include <string>
using namespace std ;

#define MaxP 100

string itoa( long long int a )
{
	string	str ;
	do
	{
		str.insert( 0, 1, '0' + a%10 ) ;
		a /= 10 ;
	} while( a != 0 ) ;
	
	return str ;
}

int main()
{
	map<int,string>	expression ;
	map<int,string>	temp ;
	int		p = 0 ;
	int		seq[ MaxP ] = { 0 } ;
	int		target = 0 ;
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	cin >> casenum ;
	for( runningCase = 0 ; runningCase < casenum ; runningCase++ )
	{
		cin >> p ;
		for( i = 0 ; i < p ; i++ )
		{
cout << i << "\t" ;
			cin >> seq[ i ] ;
			cout << seq[ i ] << endl ;
			
			if( i == 0 )
			{
				expression.clear() ;
				expression[ seq[ 0 ] ] = itoa( seq[ 0 ] ) ;
			}
			else
			{
				temp.clear() ;
				
				// here all the seq[ i ] are positive. If seq[ i ] may be negtive, these code should be rewrite.
				for( j = -32000 ; j+seq[ i ] <= 32000 ; j++ )
				{
					if( expression[ j ] != "" )
						temp[ j + seq[ i ] ] = expression[ j ] + "+" + itoa( seq[ i ] ) ;
				}
				
				for( j = seq[ i ]-32000 ; j <= 32000 ; j++ )
				{
					if( expression[ j ] != "" )
						temp[ j - seq[ i ] ] = expression[ j ] + "-" + itoa( seq[ i ] ) ;
				}

				for( j = -1 ; j*seq[ i ] >= -32000 ; j-- )
				{
					if( expression[ j ] != "" )
						temp[ j*seq[ i ] ] = expression[ j ] + "*" + itoa( seq[ i ] ) ;
				}
				for( j = 0 ; j*seq[ i ] <= 32000 ; j++ )
				{
					if( expression[ j ] != "" )
						temp[ j*seq[ i ] ] = expression[ j ] + "*" + itoa( seq[ i ] ) ;
				}
				
				for( j = -seq[ i ] ; j >= -32000 ; j -= seq[ i ] )
				{
					if( expression[ j ] != "" )
						temp[ j/seq[ i ] ] = expression[ j ] + "/" + itoa( seq[ i ] ) ;
				}
				for( j = 0 ; j <= 32000 ; j += seq[ i ] )
				{
					if( expression[ j ] != "" )
						temp[ j/seq[ i ] ] = expression[ j ] + "/" + itoa( seq[ i ] ) ;
				}
				
				expression = temp ;
			}
		}
		
		cin >> target ;
		
		if( expression[ target ] == "" )
		{
			cout << "NO EXPRESSION" << endl ;
		}
		else
		{
			cout << expression[ target ] << "=" << target << endl ;
		}
	}
	
	return 0 ;
}
*/

/* TLE
#include <iostream>
#include <map>
#include <string>
using namespace std ;

#define MaxP 100

string itoa( long long int a )
{
	string	str ;
	do
	{
		str.insert( 0, 1, '0' + a%10 ) ;
		a /= 10 ;
	} while( a != 0 ) ;
	
	return str ;
}

int main()
{
	map<int,string>	expression[ MaxP ] ;
	int		p = 0 ;
	int		seq[ MaxP ] = { 0 } ;
	int		target = 0 ;
	int		casenum = 0 ;
	int		runningCase = 0 ;
	int		i = 0 ;
	
	cin >> casenum ;
	for( runningCase = 0 ; runningCase < casenum ; runningCase++ )
	{
		cin >> p ;
		for( i = 0 ; i < p ; i++ )
		{
		cout << i << endl ;
			cin >> seq[ i ] ;
			
			if( i == 0 )
			{
				expression[ 0 ].clear() ;
				if( seq[ 0 ] <= 32000 && seq[ 0 ] >= -32000 )
				{
					expression[ 0 ][ seq[ 0 ] ] = itoa( seq[ 0 ] ) ;
				}
			}
			else
			{
				expression[ i ].clear() ;
				for( map<int,string>::iterator iter = expression[ i - 1 ].begin() ;
						iter != expression[ i - 1 ].end() ; iter++ )
				{
					if( iter->first + seq[ i ] <= 32000 && iter->first + seq[ i ] >= -32000 )
					{
						expression[ i ][ iter->first + seq[ i ] ] = iter->second + "+" + itoa( seq[ i ] ) ;
					}
					if( iter->first - seq[ i ] <= 32000 && iter->first - seq[ i ] >= -32000 )
					{
						expression[ i ][ iter->first - seq[ i ] ] = iter->second + "-" + itoa( seq[ i ] ) ;
					}
					if( iter->first * seq[ i ] <= 32000 && iter->first * seq[ i ] >= -32000 )
					{
						expression[ i ][ iter->first * seq[ i ] ] = iter->second + "*" + itoa( seq[ i ] ) ;
					}
					if( iter->first % seq[ i ] == 0 && iter->first / seq[ i ] <= 32000 && iter->first / seq[ i ] >= -32000 )
					{
						expression[ i ][ iter->first / seq[ i ] ] = iter->second + "/" + itoa( seq[ i ] ) ;
					}
				}
			}
		}
		
		cin >> target ;
		
		if( expression[ p - 1 ].find( target ) == expression[ p - 1 ].end() )
		{
			cout << "NO EXPRESSION" << endl ;
		}
		else
		{
			cout << ( expression[ p - 1 ].find( target ) )->second << "=" << target << endl ;
		}
	}
	
	return 0 ;
}
*/
