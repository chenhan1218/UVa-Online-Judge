#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <string>
using namespace std ;
#define Maxliter 1000

bool visited[ Maxliter + 1 ][ Maxliter + 1 ] = { 0 } ;

class state
{
	public:
		state() {
			a = 0 ;
			b = 0 ;
			step = "" ;
		}
		int	a ;
		int	b ;
		string	step ;
};

string	bfs( int a, int b, int c )
{
	int		i, j ;
	for( i = 0 ; i <= Maxliter ; i++ )
	{
		fill_n( visited[ i ], Maxliter + 1, false ) ;
	}
	state temp ;

	queue<state> q ;
	q.push( temp ) ;

	while( q.front().b != c )
	{
		if( visited[ q.front().a ][ q.front().b ] == false )
		{
//cout << q.front().a << "\t" << q.front().b << "\t" << q.front().c << "\t" << q.front().step << "\t" << endl ;
			visited[ q.front().a ][ q.front().b ] = true ;

			temp = q.front() ;
			temp.a = 0 ;
			temp.step += "empty A\n" ;
			q.push( temp ) ;

			temp = q.front() ;
			temp.b = 0 ;
			temp.step += "empty B\n" ;
			q.push( temp ) ;

			temp = q.front() ;
			temp.a = a ;
			temp.step += "fill A\n" ;
			q.push( temp ) ;

			temp = q.front() ;
			temp.b = b ;
			temp.step += "fill B\n" ;
			q.push( temp ) ;

			temp = q.front() ;
			if( temp.a + temp.b <= b )
			{
				temp.b = temp.a + temp.b ;
				temp.a = 0 ;
			}
			else
			{
				temp.a -= b - temp.b ;
				temp.b = b ;
			}
			temp.step += "pour A B\n" ;
			q.push( temp ) ;

			temp = q.front() ;
			if( temp.a + temp.b <= a )
			{
				temp.a = temp.a + temp.b ;
				temp.b = 0 ;
			}
			else
			{
				temp.b -= a - temp.a ;
				temp.a = a ;
			}
			temp.step += "pour B A\n" ;
			q.push( temp ) ;
		}

		q.pop() ;
	}

	return q.front().step ;
}

int gcd( int a, int b )
{
	if( a > b ) swap( a, b ) ;
	while( a != 0 )
	{
		swap( a, b ) ;
		a %= b ;
	}
	return b ;
}

int main()
{
	int a,b,c ;

	while( cin >> a >> b >> c )
	{
		cout << bfs( a, b, c ) << "success" << endl ;
	}

	return 0 ;
}

/*
#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

void findSolution()
{
}

int
main()
{
	int		ca = 0 ;
	int		cb = 0 ;
	int		n = 0 ;
	int		a = 0 ;
	int		b = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter
	string	fillb ;
	string	filla ;
	int		timesB = 0 ;
	int		timesA = 0 ;

	while( cin >> ca >> cb >> n )
	{
		fillb = "" ;
		filla = "" ;
		timesB = 0 ;
		timesA = 0 ;

		a = 0 ;
		b = 0 ;
		while( b != n )
		{
			timesB++ ;
			if( b == 0 )
			{
				fillb += "fill B\n" ;
				b = cb ;
			}
			else if( a == ca )
			{
				fillb += "empty A\n" ;
				a = 0 ;
			}
			else if( b >= ca - a )
			{
				fillb += "pour B A\n" ;
				b -= ca - a ;
				a = ca ;
			}
			else
			{
				fillb += "pour B A\n" ;
				a += b ;
				b = 0 ;
			}
		}

		if( a >= n )
		{
			a = 0 ;
			b = 0 ;
			while( a != n )
			{
				timesA++ ;
				if( a == 0 )
				{
					filla += "fill A\n" ;
					a = ca ;
				}
				else if( b == cb )
				{
					filla += "empty B\n" ;
					b = 0 ;
				}
				else if( a >= cb - b )
				{
					filla += "pour A B\n" ;
					a -= cb - b ;
					b = cb ;
				}
				else
				{
					filla += "pour A B\n" ;
					b += a ;
					a = 0 ;
				}
			}
		}

		if( timesA != 0 && timesA < timesB )
		{
			cout << filla ;
		}
		else
		{
			cout << fillb ;
		}

		cout << "success" << endl ;
	}

	return 0 ;
}*/

