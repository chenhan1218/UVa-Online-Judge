#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	str[ 120000 ][ 50 ] = { 0 } ;
int		isCompound[ 120000 ] = { 0 } ;

int main()
{
	char	buffer[ 200 ] = { 0 } ;
	char	*ptr = 0 ;
	int		numWord = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	while( scanf("%s",str[ numWord ]) != EOF )
	{
		numWord++ ;
	}
	
	for( i = 0 ; i < numWord ; i++ )
	{
		/* check if str[ i ] is the prefix of str[ j ]*/
		for( j = i+1 ; j < numWord ; j++ )
		{
			if( isCompound[ j ] == 1 )
			{
				continue ;
			}
			else if( strncmp( str[ i ], str[ j ], strlen(str[i]) ) == 0 )
			{
				ptr = bsearch( str[ j ] + strlen(str[i]), str, numWord, 50, strcmp ) ;
				
				if( ptr != NULL )
				{
					isCompound[ j ] = 1 ;
				}
			}
			else
			{
				break ;
			}
		}
	}

	for( i = 0 ; i < numWord ; i++ )
	{
		if( isCompound[ i ] == 1 )
		{
			printf( "%s\n", str[ i ] ) ;
		}
	}
	
	return 0 ;
}
