#include <iostream>
#include <iomanip>
using namespace std ;

#include <cmath>

int main()
{
	long long	size = 0 ;
	long long	remainingBytes = 0 ;
	long long	previous[ 6 ] ;
	long long	totalTime = 0 ;
	long long	sumPrevious = 0 ;
	double		remainingSecond = 0 ;
	long long	set = 0 ;
	long long	i = 0 ; // loop counter ;

	while( cin >> size )
	{
		if( size == 0 )
		{
			break ;
		}

		set++ ;
		totalTime = 0 ;

		cout << "Output for data set " << set << ", " << size << " bytes:" << endl ;

		remainingBytes = size ;
		while( remainingBytes > 0 )
		{
			for( i = 1 ; remainingBytes > 0 && i <= 5 ; i++ )
			{
				cin >> previous[ i ] ;
				remainingBytes -= previous[ i ] ;
			}

			if( i > 5 ) // now we read in 5 transfer data.
			{
				sumPrevious = previous[ 1 ] + previous[ 2 ] + previous[ 3 ] + 
					previous[ 4 ] + previous[ 5 ] ;
				if( sumPrevious == 0 )
				{
					cout << "   Time remaining: stalled" << endl ;
				}
				else
				{
					remainingSecond = remainingBytes / ( sumPrevious / 5.0 ) ;
					cout 	<< "   Time remaining: " 
							<< ceil( remainingSecond ) 
							<< " seconds" << endl ;
				}
			}

			totalTime += i - 1 ;
		}

		cout << "Total time: " << totalTime << " seconds" << endl << endl ;
	}

	return 0 ;
}
