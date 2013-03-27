#include <iostream>
#include <iomanip>
using namespace std ;

int
main()
{
	int		n = 0 ;
	int		p = 0 ;
	int		numberRFP = 0 ;
	char	buffer[ 100 ] ;
	char	bestProposal[ 100 ] ;
	int		bestMet = 0 ;
	double	bestPrice = 0 ;
	char	tempProposal[ 100 ] ;
	int		tempMet = 0 ;
	double	tempPrice = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> n >> p )
	{
		if( n == 0 && p == 0 )
		{
			break ;
		}

		numberRFP++ ;
		cin.get() ; // use get() to absorb '\n'

		if( numberRFP > 1 )
		{
			cout << endl ;
		}

		for( i = 1 ; i <= n ; i++ )
		{
			cin.getline( buffer, 90, '\n' ) ;
		}

		for( i = 1 ; i <= p ; i++ )
		{
			if( i == 1 )
			{
				cin.getline( bestProposal, 90, '\n' ) ;
				cin >> bestPrice >> bestMet ;
				cin.get() ; // use get() to absorb '\n'

				for( j = 1 ; j <= bestMet ; j++ )
				{
					cin.getline( buffer, 90, '\n' ) ;
				}
			}
			else
			{
				cin.getline( tempProposal, 90, '\n' ) ;
				cin >> tempPrice >> tempMet ;
				cin.get() ; // use get() to absorb '\n'

				for( j = 1 ; j <= tempMet ; j++ )
				{
					cin.getline( buffer, 90, '\n' ) ;
				}

				if( tempMet > bestMet )
				{
					strcpy( bestProposal, tempProposal ) ;
					bestMet = tempMet ;
					bestPrice = tempPrice ;
				}
				else if( tempMet == bestMet && tempPrice < bestPrice )
				{
					strcpy( bestProposal, tempProposal ) ;
					bestMet = tempMet ;
					bestPrice = tempPrice ;
				}
			}
		}

		cout << "RFP #" << numberRFP << endl ;
		cout << bestProposal << endl ;
	}

	return 0 ;
}
