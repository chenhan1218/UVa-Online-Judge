#include <stdio.h>
#include <string.h>

int	numSelect = 0 ;
int	numOccur[ 26 ] = { 0 } ;
int	selected[ 26 ] = { 0 };

void combinations( int numRemain, int r, int depth )
{
	int		i = 0 ;
	int		j = 0 ;
	
	/* ensure that the number of selected does not exceed the bound and do not too small */
	if( depth == 26 )
	{
		if( numSelect == r )
		{
			for( i = 0 ; i < 26 ; i++ )
			{
				for( j = 0 ; j < selected[ i ] ; j++ )
				{
					printf("%c",'a'+i) ;
				}
			}
			printf("\n") ;
		}
	}
	else
	{
		if( numSelect <= r && numSelect + numRemain >= r )
		{
			for( i = numOccur[ depth ] ; i >= 0 ; i-- )
			{
				numSelect += i ;
				selected[ depth ] = i ;
				combinations( numRemain-numOccur[ depth ], r, depth+1 ) ;
				selected[ depth ] = 0 ;
				numSelect -= i ;
			}
		}
	}
}

int main()
{
	char	str[ 40 ] = { 0 } ;
	int		r = 0 ;
	int		i = 0 ;
	
	while( scanf("%s%d",str,&r) != EOF )
	{
		for( i = 0 ; i < 26 ; i++ )
		{
			numOccur[ i ] = 0 ;
		}
		
		for( i = 0 ; i < strlen(str) ; i++ )
		{
			numOccur[ str[ i ] - 'a' ] ++ ;
		}
		
		combinations( strlen(str), r, 0 ) ;
	}
	
	return 0 ;
}
