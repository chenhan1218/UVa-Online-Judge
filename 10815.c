#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removePunct( char *str )
{
	int		i = 0 ;
	for( i = 0 ; str[ i ] != '\0' ; i++ )
	{
		if( isalpha( str[ i ] ) == 0 )
		{
			str[ i ] = ' ' ;
		}
		else
		{
			str[ i ] = tolower( str[ i ] ) ;
		}
	}
}

int main()
{
	char	dictionary[ 5000 ][ 205 ] = { 0 } ;
	char	buffer[ 205 ] ;
	char	*word = 0 ;
	int		numWords = 0 ;
	int		i = 0 ;
	
	while( scanf("%s",buffer) != EOF )
	{
		removePunct( buffer ) ;
		
		word = strtok( buffer, " " ) ;
		while( word != NULL )
		{
			for( i = 0 ; i < numWords ; i++ )
			{
				if( strcmp(dictionary[i],word) == 0 )
				{
					break ;
				}
			}
			
			if( i == numWords )
			{
				strcpy( dictionary[ i ], word ) ;
				numWords++ ;
			}
			
			word = strtok( NULL, " " ) ;
		}
	}
	
	/* sort the dictionary */
	qsort( dictionary,numWords, sizeof(char)*205, strcmp ) ;
	
	for( i = 0 ; i < numWords ; i++ )
	{
		printf("%s\n",dictionary[ i ]) ;
	}
	
	return 0 ;
}
