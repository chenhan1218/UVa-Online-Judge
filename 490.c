#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	char	str[100][105];
	int		numStr = 0 ;
	int		maxLen = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	while( gets(str[i]) )
	{
		if ( str[ i ][ 0 ] == 0 )
		{
			break ;
		}
		
		numStr++ ;
		i++ ;
	}
	
	for( i = 0 ; i < numStr ; i++ )
	{
		maxLen = max( maxLen, strlen(str[i]) );
	}
	
	for( i = 0 ; i < numStr ; i++ )
	{
		while( maxLen > strlen(str[i]) )
		{
			strcat( str[ i ], " " );
		}
	}
	
	for( i = 0 ; i < maxLen ; i++ )
	{
		for( j = numStr-1 ; j >= 0  ; j-- )
		{
			printf("%c",str[j][i] ) ;
		}
		printf("\n");
	}
	
	return 0 ;
}
