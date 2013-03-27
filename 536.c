#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void post_order( char *preOrder, char *inOrder, int N, char* postOrder )
{
	char	*root = NULL ;
	int		numLeft = 0 ;
	int		numRight = 0 ;

	root = strchr( inOrder, preOrder[ 0 ] ) ;
	numLeft = root - inOrder ;
	numRight = N - 1 - numLeft ;

	/* store root */
	postOrder[ N - 1 ] = *root ;
	/* store left tree */
	if( numLeft > 0 )
	{
		post_order( preOrder + 1, inOrder, numLeft, postOrder ) ;
	}
	/* store right tree */
	if( numRight > 0 )
	{
		post_order( preOrder + 1 + numLeft, inOrder + numLeft + 1, N - numLeft - 1, 
					postOrder + numLeft ) ;
	}
}

int main()
{
	int		N = 0 ;
	char	preOrder[ 26 + 1 ] = { 0 } ;
	char	inOrder[ 26 + 1 ] = { 0 } ;
	char	postOrder[ 26 + 1 ] = { 0 } ;
	int		i = 0 ;
	int		j = 0 ;

	while( scanf("%s%s", preOrder, inOrder ) != EOF )
	{
		N = strlen( preOrder ) ;

		post_order( preOrder, inOrder, N, postOrder ) ;
		postOrder[ N ] = '\0' ;

		printf( "%s\n", postOrder ) ;
	}

	return 0 ;
}
