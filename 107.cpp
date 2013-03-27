//	216
//	->36 36 36 36 36 
//	->6 6 6 6 6  6 6 6 6 6  6 6 6 6 6  6 6 6 6 6  6 6 6 6 6
//	->...........
//
//	We can find that 216=(N+1)^k, 125=N^k
//	We have to find N, k.(Here N=5, k=3)

#include <iostream>
#include <iomanip>
using namespace std ;

void findNk( long long heightInitial, long long numberCats, long long *N, long long *k )
{
	long long	temp1 = 0 ;
	long long	temp2 = 0 ;
	long long	i = 0 ;
	long long	j = 0 ;

	for( *N = 1 ; *N <= numberCats ; (*N)++ )
	{
		if( heightInitial % ( *N + 1 ) == 0 && numberCats % *N == 0 )
		{
			temp1 = heightInitial / ( *N + 1 ) ;
			temp2 =  numberCats / *N ;
			
			*k = 1 ;
			while( temp1 != 1 || temp2 != 1 )
			{
				if( temp1 % ( *N + 1 ) != 0 || temp2 % *N != 0 )
				{
					break ;
				}
				else
				{
					temp1 /= *N + 1 ;
					temp2 /= *N ;
					(*k)++ ;
				}
			}

			if( temp1 == 1 && temp2 == 1 ) // Find N,k successly.
			{
				return ;
			}
		}
	}

	*N = 0 ;
	*k = 0 ;
}

int main()
{
	long long	heightInitial = 0 ;
	long long	numberCats ;

	long long	dealing_heightInitial , dealing_numberCats ;

	long long	N = 0 ;
	long long	k = 0 ;
	long long	notWorking = 0 ;
	long long	heightStack = 0 ;
	long long	i = 0 ; // loop counter
	int			exponent_height , exponent_cats ;

	while( cin >> heightInitial >> numberCats )
	{
		if( heightInitial == 0 && numberCats == 0 )
		{
			break ;
		}

		findNk( heightInitial, numberCats, &N, &k ) ;

		// If k >= 1, notWorking = 1 + N + N^2 + ... N^(k-1)
		// If k == 0, notWorking = 0.
		if( k == 0 )
		{
			notWorking = 0 ;
		}
		else
		{
			notWorking = 1 ;
			for( i = 1 ; i <= k - 1 ; i++ )
			{
				notWorking = notWorking * N + 1 ;
			}
		}

		heightStack = ( N + 1 ) * heightInitial - N * numberCats ;

		cout << notWorking << " " << heightStack << endl ;
	}

	return 0 ;
}
