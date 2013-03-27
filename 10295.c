#include <stdio.h>
#include <string.h>

int main()
{
	char		dictionary[ 1000 ][ 20 ] = { 0 } ;
	int			dollar[ 1000 ] = { 0 } ;
	int		m = 0 ;
	int		n = 0 ;
	char	description[ 20 ] = { 0 } ;
	int		salary = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	scanf("%d%d",&m,&n) ;
	
	for( i = 0 ; i < m ; i++ )
	{
		scanf("%s",dictionary[ i ]) ;
		scanf("%d",&dollar[ i ]) ;
	}
	
	for( i = 0 ; i < n ; i++ )
	{
		salary = 0 ; /* set salary = 0 at the begin and sum up the dollars in the following */
		while( 1 )
		{
			scanf("%s",description) ;
			if( strcmp(description,".") == 0 ) /* if the description is equal to "." */
			{
				break ;
			}
			
			/* check if the description is equal to the words in the dictionary */
			for( j = 0 ; j < m ; j++ )
			{
				if( strcmp(description,dictionary[ j ]) == 0 )
				{
					salary += dollar[ j ] ;
				}
			}
		}
		
		printf("%d\n",salary) ;
	}
	
	return 0 ;
}
