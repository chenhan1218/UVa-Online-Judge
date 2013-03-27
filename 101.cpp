#include <iostream>
#include <iomanip>
using namespace std ;

#define True 1
#define False 0
#define MaxN 25
#define MaxCharacters 5

class Blocks
{
	public :
		Blocks() ;
		static Blocks*	blocksWorld ;
		static Blocks*	block ;
		static int		n ;
		static void		initial() ;
		static void		moveOnto( int a, int b ) ;
		static void		moveOver( int a, int b ) ;
		static void		pileOnto( int a, int b ) ;
		static void		pileOver( int a, int b ) ;
		static void		print() ;
		static void		returning( int a ) ;
		int		number ;
		Blocks*	previous ;
		Blocks*	next ;
};

Blocks::Blocks()
{
	number = 0 ;
	previous = NULL ;
	next = NULL ;
}

void 
Blocks::initial()
{
	int		i = 0 ; // loop counter

	for( i = 0 ; i < n ; i++ )
	{
		blocksWorld[ i ].next = block + i ;
		block[ i ].previous = blocksWorld + i ;
		block[ i ].next = NULL ;
		block[ i ].number = i ;
	}
}

void
Blocks::moveOnto( int a, int b )
{
	returning( a ) ;
	if( block[ b ].next != NULL )
	{
		returning( block[ b ].next->number ) ;
	}

	blocksWorld[ a ].next = NULL ;
	block[ a ].previous = block + b ;
	block[ b ].next = block + a ;
}

void
Blocks::moveOver( int a, int b )
{
	Blocks*	ptr = NULL  ;

	returning( a ) ;
	ptr = &block[ b ] ;
	while( ptr->next != NULL )
	{
		ptr = ptr->next ;
	}

	blocksWorld[ a ].next = NULL ;
	block[ a ].previous = ptr ;
	ptr->next = block + a ;
}

void
Blocks::pileOnto( int a, int b )
{
	if( block[ b ].next != NULL )
	{
		returning( block[ b ].next->number ) ;
	}

	if( block[ a ].previous != NULL )
	{
		block[ a ].previous->next = NULL ;
	}
	block[ b ].next = block + a ;
	block[ a ].previous = block + b ;
}

void
Blocks::pileOver( int a, int b )
{
	Blocks*	ptr = NULL  ;

	ptr = &block[ b ] ;
	while( ptr->next != NULL )
	{
		ptr = ptr->next ;
	}

	if( block[ a ].previous != NULL )
	{
		block[ a ].previous->next = NULL ;
	}
	ptr->next = block + a ;
	block[ a ].previous = ptr ;
}

void
Blocks::returning( int a )
{
	if( block[ a ].previous != NULL )
	{
		block[ a ].previous->next = NULL ;
	}

	blocksWorld[ a ].next = block + a ;
	block[ a ].previous = blocksWorld + a ;
	if( block[ a ].next != NULL )
	{
		block[ a ].next->previous = NULL ;
		returning( block[ a ].next->number ) ;
	}

	block[ a ].next = NULL ;
}

void
Blocks::print()
{
	int		i = 0 ; // loop counter
	Blocks*	ptr = NULL ;

	for( i = 0 ; i < n ; i++ )
	{
		cout << i << ":" ;

		ptr = blocksWorld[ i ].next ;
		while( ptr != NULL )
		{
			cout << " " << ptr->number ;
			ptr = ptr->next ;
		}

		cout << endl ;
	}
}

// static data member must be initialized once at file scope.
Blocks	*Blocks::blocksWorld = new Blocks[ MaxN ] ;
Blocks	*Blocks::block = new Blocks[ MaxN ] ;
int		Blocks::n ;
void		Blocks::initial() ;
void		Blocks::moveOnto( int a, int b ) ;
void		Blocks::moveOver( int a, int b ) ;
void		Blocks::pileOnto( int a, int b ) ;
void		Blocks::pileOver( int a, int b ) ;
void		Blocks::print() ;

int
main()
{
	char	command1[ MaxCharacters + 1 ] ;
	char	command2[ MaxCharacters + 1 ] ;
	int		a = 0 ;
	int		b = 0 ;
	Blocks*	ptr ;
	bool	illegal = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> Blocks::n )
	{
		Blocks::initial() ;

		while( cin >> command1 )
		{
			if( command1[ 0 ] == 'q' )
			{
				break ;
			}

			cin >> a >> command2 >> b ;

			// Any command in which a = b or in which a and b are in the 
			// same stack of blocks is an illegal command.
			if( a == b )
			{
				continue ;
			}

			ptr = Blocks::block[ a ].next ;
			while( ptr != NULL )
			{
				if( ptr->number == b )
				{
					illegal = True ;
					break ;
				}

				ptr = ptr->next ;
			}
			ptr = Blocks::block[ b ].next ;
			while( ptr != NULL )
			{
				if( ptr->number == a )
				{
					illegal = True ;
					break ;
				}

				ptr = ptr->next ;
			}

			if( illegal == True )
			{
				illegal = False ;
				continue ;
			}

			if( command1[ 0 ] == 'm' )
			{
				if( command2[ 1 ] == 'n' )
				{
					// move a onto b
					Blocks::moveOnto( a, b ) ;
				}
				else
				{
					// move a over b
					Blocks::moveOver( a, b ) ;
				}
			}
			else
			{
				if( command2[ 1 ] == 'n' )
				{
					// pile a onto b
					Blocks::pileOnto( a, b ) ;
				}
				else
				{
					// pile a over b
					Blocks::pileOver( a, b ) ;
				}
			}
		}

		Blocks::print() ;
	}

	return 0 ;
}
