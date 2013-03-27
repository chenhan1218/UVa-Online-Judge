#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;

#define MaxN 100

double	win[ MaxN + 1 ] = { 0 } ;
double	lose[ MaxN + 1 ] = { 0 } ;

int	winstate( string a, string b )
{
	if( a == "rock" )
	{
		if( b == "scissors" )
			return 1 ;
		else if( b == "paper" )
			return -1 ;
		else
			return 0 ;
	}
	else if( a == "paper" )
	{
		if( b == "rock" )
			return 1 ;
		else if( b == "scissors" )
			return -1 ;
		else
			return 0 ;
	}
	else
	{
		if( b == "paper" )
			return 1 ;
		else if( b == "rock" )
			return -1 ;
		else
			return 0 ;
	}
}

int main()
{
	int		n = 0 ;
	int		k = 0 ;
	int		p1 = 0 ;
	int		p2 = 0 ;
	string	m1 ;
	string	m2 ;
	bool	firstCase = true ;
	int		i = 0 ;
	int		j = 0 ;

	while( cin >> n >> k )
	{
		fill_n( win+1, n, 0 ) ;
		fill_n( lose+1, n, 0 ) ;

		for( i = 0 ; i < k * n * (n-1) / 2 ; i++ )
		{
			cin >> p1 >> m1 >> p2 >> m2 ;

			switch( winstate( m1, m2 ) )
			{
				case 1:
					win[ p1 ] ++ ;
					lose[ p2 ] ++ ;
					break ;
				case -1:
					win[ p2 ] ++ ;
					lose[ p1 ] ++ ;
					break ;
			}
		}

		if( firstCase == true )
			firstCase = false ;
		else
			cout << endl ;

		for( i = 1 ; i <= n ; i++ )
		{
			if( win[ i ] + lose[ i ] == 0 )
				cout << "-" << endl ;
			else
				cout << fixed << setprecision( 3 ) 
						<< win[ i ] / ( win[ i ] + lose[ i ] ) << endl ;
		}
	}

	return 0 ;
}

