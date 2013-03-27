#include <iostream>
using namespace std ;

int main()
{
	int		testcase = 0 ;
	int		d = 0 ;
	int		i = 0 ;
	int		p = 0 ; // position
	
	cin >> testcase ;
	while( testcase > 0 )
	{
		testcase-- ;
		
		scanf("%d%d", &d, &i ) ;
		p = 1 ;
		i -- ;
		for( int depth = 2 ; depth <= d ; depth++ )
		{
			if( i % 2 == 0 )
			{
				p = p*2 ;
			}
			else
			{
				p = p*2 + 1 ;
			}
			
			i /= 2 ;
		}
		
		printf("%d\n",p) ;
	}
	
	return 0 ;
}
