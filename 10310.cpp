#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std ;

class notEscape
{
public:
	pair<long long int,long long int>	gopher ;
	pair<long long int,long long int>	dog	;
	notEscape( const pair<long long int,long long int> &g, const pair<long long int,long long int> &d ) 
	: gopher(g), dog(d){
	}
	bool operator()( const pair<long long int,long long int> &p ) const {
		if( dist2( p, dog ) < 4*dist2( p, gopher ) )
		{
			return true ;
		}
		else
		{
			return false ;
		}
	}
	static long long int dist2( const pair<long long int,long long int> &a, const pair<long long int,long long int> &b ){
		return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) ;
	}
};

long long int getValue()
{
	long long int 	v = 0 ;
	char	c ;
	long long int	buffer ;
	
	cin >> v >> c >> buffer ;
	
	if( v >= 0 )
	{
		v = 1000 * v + buffer ;
	}
	else
	{
		v = 1000 * v - buffer ;
	}
	
	return v ;
}

string 	tostr( long long int a )
{
	ostringstream	os ;
	
	if( a < 0 )
	{
		os << "-" ;
		a = -a ;
	}
	
	os << a/1000 << "." << setw(3) << setfill('0') << a%1000 ;
	return os.str() ;
}

int main()
{
	int		n = 0 ;
	
	cout << fixed << setprecision( 3 ) ;

	while( cin >> n )
	{
		pair<long long int,long long int>	gopher ;
		pair<long long int,long long int>	dog	;
		
		gopher.first = getValue() ;
		gopher.second = getValue() ;
		dog.first = getValue() ;
		dog.second = getValue() ;
		
		vector< pair<long long int,long long int> >	points( n ) ;
		
		for( int i = 0 ; i < n ; i++ )
		{
			points[ i ].first = getValue() ;
			points[ i ].second = getValue() ;
		}
		
		points.erase( remove_if( points.begin(), points.end(), notEscape( gopher, dog ) ), 
			points.end() ) ;
		
		if( points.empty() == true )
		{
			cout << "The gopher cannot escape." << endl ;
		}
		else
		{
			cout << "The gopher can escape through the hole at (" 
				<< tostr( points[ 0 ].first ) 
				<< "," 
				<< tostr( points[ 0 ].second ) 
				<< ")." << endl ;
		}
	}
	
	return 0 ;
}

