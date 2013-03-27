#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removePunct( char *str )
{
	int		i = 0 ;
	for( i = 0 ; str[ i ] != '\0' ; i++ )
	{
		if( isalpha( str[ i ] ) == 0 &&  str[ i ] != '-' )
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
	char	buffer[ 205 ] = { 0 };
	char	pre_buffer[ 205 ] = { 0 };
	int		len[ 35 ] = { 0 } ;
	char	*word = 0 ;
	int		i = 0 ;
	
	strcpy( pre_buffer, "" ) ;
	
	/* read in the article */
	while( 1 )
	{
		gets(buffer) ;
		if( strlen( buffer ) == 0 )
		{
			break ;
		}
		
		for( i = 0 ; i <= 30 ; i++ )
		{
			len[ i ] = 0 ;
		}
		
		while( buffer[ 0 ] != '#' )
		{
			strcat( pre_buffer, buffer ) ;
			strcpy( buffer, pre_buffer ) ;
			strcpy( pre_buffer, "" ) ;
			
			for( i = 0 ; buffer[ i ] != '\0' ; i++ )
			{
				if( buffer[ i ] == '\'' )
				{
					strcpy(buffer+i, buffer+i+1) ;
					i-- ;
				}
			}
			
			for( i = 0 ; buffer[ i+1 ] != '\0' ; i++ )
			{
				if( buffer[ i ] == '-' )
				{
					strcpy(buffer+i, buffer+i+1) ;
					i-- ;
				}
			}
			
			/* remove punctuation from the string and lower the alphabetical letters */
			removePunct( buffer ) ;
			
			/* extract words from a string */
			word = strtok( buffer, " " ) ;
			while( word != NULL )
			{
				if( word[ strlen(word)-1 ] != '-' )
				{
					len[ strlen(word) ] ++ ;
				}
				else
				{
					strcpy( pre_buffer, word ) ;
				}
				
				word = strtok( NULL, " " ) ;
			}
			
			gets(buffer) ;
		}
		
		for( i = 0 ; i <= 30 ; i++ )
		{
			if( len[ i ] != 0 )
			{
				printf("%d %d\n",i,len[i]) ;
			}
		}
		printf("\n");
	}
	
	return 0 ;
}
