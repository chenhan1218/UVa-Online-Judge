#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long int n = 0 ;
	
	while( scanf("%ld",&n)==1 && n >= 0 )
	{
		printf("%ld\n",1+n*(n+1)/2);
	}
	
	return 0;
}

