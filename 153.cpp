#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std ;

long long int permutation( string a )
{
	long long int	ans = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	ans = 1 ;
	j = 1 ;
	for( i = 1 ; i < a.size() ; i++ )
	{
		if( a[ i ] == a[ i - 1 ] )
			j++ ;
		else
			j = 1 ;
		
		ans = ans * ( i + 1 ) / j ;
	}
	
	return ans ;
}

int main()
{
	string	input ;
	string	sorted ;
	long long int	order = 0 ;
	long long int	place = 0 ;
	int		i = 0 ;
	
	while( cin >> input && input != "#" )
	{
		sorted = input ;
		sort( sorted.begin(), sorted.end() ) ;
		
		place = 0 ;
		order = 1 ;
		while( input.size() > 1 )
		{
			for( i = 0 ; i < sorted.size() ; i++ )
			{
				if( i == 0 || sorted[ i ] != sorted[ i - 1 ] )
				{
					if( sorted[ i ] != input[ 0 ] )
					{
						order += permutation( sorted.substr( 0, i ) + sorted.substr( i+ 1 ) ) ;
					}
					else
					{
						input = input.substr( 1 ) ;
						sorted = sorted.substr( 0, i ) + sorted.substr( i+ 1 ) ;
						break ;
					}
				}
			}
		}
		
		cout << setw( 10 ) << right << order << endl ;
	}
	
	return 0 ;
}
