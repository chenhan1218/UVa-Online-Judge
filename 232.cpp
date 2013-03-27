/*
#include <iostream>
#include <iomanip>
using namespace std ;

char matrix[11][11];
int num[10][10];

int main()
{
	int x,y;
	int i,j,k;
	int count;
	int cases=0;
	while(cin >> x >> y )
	{
		cases++;
		for(i=0;i<11;i++)
			for(j=0;j<11;j++)
				matrix[i][j]=0;
		for(i=0;i<x;i++)
			cin >> matrix[ i ] ;
		count=0;
		cout << "puzzle #" << cases << ":" << endl ;
		cout << "Across" << endl ;
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			{
				if(matrix[i][j]!='*')
				{
					if(i==0||j==0||matrix[i-1][j]=='*'||matrix[i][j-1]=='*')
					{
						count++;
						num[i][j]=count;
					}
					if(j==0||matrix[i][j-1]=='*')
					{
                        cout << setw( 3 ) << count << "." ;
						for(k=j;;k++)
						{
							if(matrix[i][k]==0||matrix[i][k]=='*')
								break;
							cout << matrix[i][k];
						}
						cout << endl ;
					}
				}
			}
		}
		cout << "Down" << endl ;
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			{
				if(matrix[i][j]!='*')
				{
					if(i==0||matrix[i-1][j]=='*')
					{
                        cout << setw( 3 ) << num[i][j] << "." ;
						for(k=i;;k++)
						{
							if(matrix[k][j]==0||matrix[k][j]=='*')
								break;
							cout << matrix[k][j] ;
						}
						cout << endl ;
					}
				}
			}
		}
		cout << endl ;
	}
	
	return 0 ;
}

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std ;

#define MaxR 10
#define MaxC 10

int		r = 0 ;
int		c = 0 ;
int		number = 0 ;
string	grid[ MaxC ] ;
string	across ;
string	down ;

void crossword( int row, int column )
{
	int		i = 0 ; // loop counter

	if( grid[ row ][ column ] == '*' )
		return ;

	if( ( row > 0 && grid[ row - 1 ][ column ] != '*' ) && 
		( column > 0 && grid[ row ][ column - 1 ] != '*' ) )
		return ;

	number++ ;

	if( column == 0 || grid[ row ][ column - 1 ] == '*' )
	{
		ostringstream s ;
		s << setw( 3 ) << number << "." ;
		for( i = column ; i < c && grid[ row ][ i ] != '*' ; i++ )
			s << grid[ row ][ i ] ;
		s << endl ;

		across += s.str() ;
	}

	if( row == 0 || grid[ row - 1 ][ column ] == '*' )
	{
		ostringstream s ;
		s << setw( 3 ) << number << "." ;
		for( i = row ; i < r && grid[ i ][ column ] != '*' ; i++ )
			s << grid[ i ][ column ] ;
		s << endl ;

		down += s.str() ;
	}
}

int main()
{
	int		puzzleNum = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> r >> c )
	{
		puzzleNum++ ;

		number = 0 ;
		across.clear() ;
		down.clear() ;

		for( i = 0 ; i < r ; i++ )
			cin >> grid[ i ] ;

		for( i = 0 ; i < r ; i++ )
		{
			for( j = 0 ; j < c ; j++ )
			{
				crossword( i, j ) ;
			}
		}

		if( puzzleNum > 1 )
			cout << endl ;

		cout << "puzzle #" << puzzleNum << ":" << endl ;
		cout << "Across" << endl ;
		cout << across ;
		cout << "Down" << endl ;
		cout << down ;
	}

	return 0 ;
}


