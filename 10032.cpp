#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std ;

int main()
{
	int		n = 0 ;
	int		num = 0 ;
	int		smaller = 0 ;
	int		larger = 0 ;
	int		cases = 0 ;
	bool	firstCase = 1 ;

	cin >> cases ;

	while( cases > 0 )
	{
		cases-- ;
		
		bitset<45001>	b[101] ;
		int		sum = 0 ;
		cin >> n ;
		
		b[0][0] = 1;
		
		for( int i = 0 ; i < n ; i++ )
		{
			cin >> num ;
			sum += num ;
			
			for( int j = i+1 ; j >= 1 ; j-- )
			{
				b[ j ] = b[ j ] | ( b[ j-1 ]<<num ) ;
			}
		}
		
		smaller = sum/2 ;
		larger = sum - smaller ;
		while( b[ n/2 ][ smaller ] == 0 && b[ n/2 ][ larger ] == 0 )
		{
			smaller-- ;
			larger++ ;
		}
		
		if( firstCase == 0 )
		{
			cout << endl ;
		}
		else
		{
			firstCase = 0 ;
		}
		cout << smaller << " " << larger << endl ;
	}
	
	return 0 ;
}
