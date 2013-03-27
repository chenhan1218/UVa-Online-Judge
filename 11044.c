#include <stdio.h>

int main()
{
	int		t = 0 ;
	int		n = 0 ;
	int		m = 0 ;
	int		i = 0 ;
	
	scanf("%d",&t);
	
	for( i = 0 ; i < t ; i++ )
	{
		scanf("%d",&n);
		scanf("%d",&m);
		
		printf("%d\n",(int)(ceil((n-2)/3.0)*ceil((m-2)/3.0)));
	}
	return 0 ;
}
