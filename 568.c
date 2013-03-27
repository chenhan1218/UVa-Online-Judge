#include <stdio.h>

int main()
{
	int		n = 0 ;
	
	while( scanf("%d",&n) == 1 )
	{
		int		needSkipNum2 = 0 ;
		int		needSkipNum5 = 0 ;
		int		ans = 0 ;
		int		tmp = 0 ;
		int 	i = 0 ;
		
		tmp=n;
		while( tmp > 0 )
		{
			needSkipNum5 += tmp / 5;
			tmp /= 5 ;
		}
		
		needSkipNum2 = needSkipNum5;
		ans = 1;
		
		for( i = 1 ; i <= n ; i++ )
		{
			tmp = i ;
			while( needSkipNum2 > 0 && tmp % 2 == 0 )
			{
				needSkipNum2-- ;
				tmp /= 2 ;
			}
			
			while( needSkipNum5 > 0 && tmp % 5 == 0 )
			{
				needSkipNum5-- ;
				tmp /= 5 ;
			}
			
			ans = ( ans * tmp ) % 10 ;
		}
		
		printf("%5d -> %d\n",n,ans);
	}
	
	return 0 ;
}
