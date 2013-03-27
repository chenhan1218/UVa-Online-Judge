#include <iostream>
#include <vector>
using namespace std ;

int main()
{
	const int	MaxDimension = 20 ;
	double	conversion[ MaxDimension + 1 ][ MaxDimension + 1 ] = { 0 } ;
	double	profit[ MaxDimension + 1 ][ MaxDimension + 1 ] = { 0 } ;
	double	buffer[ MaxDimension + 1 ][ MaxDimension + 1 ] = { 0 } ;
	vector<int>		seq[ MaxDimension + 1 ][ MaxDimension + 1 ] ;
	vector<int>		seqBuffer[ MaxDimension + 1 ][ MaxDimension + 1 ] ;
	int		n = 0 ;
	
	while( cin >> n )
	{
		for( int i = 1 ; i <= n ; i++ )
		{
			for( int j = 1 ; j <= n ; j++ )
			{
				if( i == j )
				{
					conversion[ i ][ j ] = 1 ;
					profit[ i ][ j ] = 1 ;
					seq[ i ][ j ].assign( 1, i ) ;
				}
				else
				{
					cin >> conversion[ i ][ j ] ;
					profit[ i ][ j ] = 0 ;
					seq[ i ][ j ].clear() ;
				}
			}
		}
		
		bool	isProfit = false ;
		pair<int,int>	result ;
		for( int tran = 1 ; tran <= n && isProfit == false ; tran++ )
		{
			for( int i = 1 ; i <= n && isProfit == false ; i++ )
			{
				for( int j = 1 ; j <= n && isProfit == false ; j++ )
				{
					buffer[ i ][ j ] = 0 ;
					seqBuffer[ i ][ j ].clear() ;
					for( int k = 1 ; k <= n && isProfit == false ; k++ )
					{
						if( profit[ i ][ k ] * conversion[ k ][ j ] > buffer[ i ][ j ] )
						{
							buffer[ i ][ j ] = profit[ i ][ k ] * conversion[ k ][ j ] ;
							seqBuffer[ i ][ j ] = seq[ i ][ k ] ;
						}
					}
					seqBuffer[ i ][ j ].push_back( j ) ;
					
					if( i == j && buffer[ i ][ j ] > 1.01 )
					{
						isProfit = true ;
						result = pair<int,int>(i,j) ;
					}
				}
			}
			
			for( int i = 1 ; i <= n ; i++ )
			{
				for( int j = 1 ; j <= n ; j++ )
				{
					profit[ i ][ j ] = buffer[ i ][ j ] ;
					seq[ i ][ j ].swap( seqBuffer[ i ][ j ] ) ;
				}
			}
		}
		
		if( isProfit == true )
		{
			for( int i = 0 ; i < seq[ result.first ][ result.second ].size() ; i++ )
			{
				if( i != 0 )
					cout << " " ;
				cout << seq[ result.first ][ result.second ][ i ] ;
			}
			cout << endl ;
		}
		else
		{
			cout << "no arbitrage sequence exists" << endl ;
		}
	}
	
	return 0 ;
}
