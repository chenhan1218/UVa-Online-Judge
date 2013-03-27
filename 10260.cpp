#include <iostream>
using namespace std ;

int main()
{
	char input ;
	int before ;

	while( cin.get( input ) )
	{
		if( input == '\n' )
		{
			cout << endl ;
			before = 0 ;
		}
		else
		{
			switch( input )
			{
				case 'B' :
					if( before != 1 )
					{
						cout << "1" ;
						before = 1 ;
					}
					break ;
				case 'F' :
					if( before != 1 )
					{
						cout << "1" ;
						before = 1 ;
					}
					break ;
				case 'P' :
					if( before != 1 )
					{
						cout << "1" ;
						before = 1 ;
					}
					break ;
				case 'V' :
					if( before != 1 )
					{
						cout << "1" ;
						before = 1 ;
					}
					break ;

				case 'C' :
					if( before != 2 )
					{
						cout << "2" ;
						before = 2 ;
					}
					break ;
				case 'G' :
					if( before != 2 )
					{
						cout << "2" ;
						before = 2 ;
					}
					break ;
				case 'J' :
					if( before != 2 )
					{
						cout << "2" ;
						before = 2 ;
					}
					break ;
				case 'K' :
					if( before != 2 )
					{
						cout << "2" ;
						before = 2 ;
					}
					break ;
				case 'Q' :
					if( before != 2 )
					{
						cout << "2" ;
						before = 2 ;
					}
					break ;
				case 'S' :
					if( before != 2 )
					{
						cout << "2" ;
						before = 2 ;
					}
					break ;
				case 'X' :
					if( before != 2 )
					{
						cout << "2" ;
						before = 2 ;
					}
					break ;
				case 'Z' :
					if( before != 2 )
					{
						cout << "2" ;
						before = 2 ;
					}
					break ;

				case 'D' :
					if( before != 3 )
					{
						cout << "3" ;
						before = 3 ;
					}
					break ;
				case 'T' :
					if( before != 3 )
					{
						cout << "3" ;
						before = 3 ;
					}
					break ;

				case 'L' :
					if( before != 4 )
					{
						cout << "4" ;
						before = 4 ;
					}
					break ;

				case 'M' :
					if( before != 5 )
					{
						cout << "5" ;
						before = 5 ;
					}
					break ;
				case 'N' :
					if( before != 5 )
					{
						cout << "5" ;
						before = 5 ;
					}
					break ;

				case 'R' :
					if( before != 6 )
					{
						cout << "6" ;
						before = 6 ;
					}
					break ;

				default :
					before = 0 ;
					break ;
			}
		}
	}

	return 0 ;
}
