#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int		n = 0 ;
	int		t = 0 ;
	int		caseNum = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	char	str[ 10000 ][ 11 ] = { 0 } ;
	
	scanf("%d",&t ) ;
	
	for( caseNum = 1 ; caseNum <= t ; caseNum++ )
	{
		scanf("%d",&n) ;
		for( i = 0 ; i < n ; i++ )
		{
			scanf("%s", str[ i ] ) ;
		}
		
		qsort( str, n, sizeof(str[0]), strcmp ) ;
		
		for( i = 0 ; i+1 < n ; i++ )
		{
			if( strncmp( str[ i ], str[ i+1 ], strlen(str[ i ]) ) == 0  )
			{
				break ;
			}
		}
		
		if( i+1 < n )
		{
			printf("NO\n") ;
		}
		else
		{
			printf("YES\n") ;
		}
	}
	
	return 0 ;
}
