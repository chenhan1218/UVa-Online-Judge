#include <iostream>
using namespace std ;

int main()
{
	int p , q , remainder ;
	long long int left_part_answer, right_part_answer ;
	long long int tem_million = 10000000 ;
	long long int temp = 0 ;

	while( cin >> p >> q )
	{
		if( p < 0 && q < 0 )
		{
			break ;
		}

		left_part_answer = 0 ;
		right_part_answer = 0 ;
		while( q - p >= 10 )
		{
			while( ( remainder = p % 10 ) != 0 )
			{
				right_part_answer += remainder ;
				p++ ;
			}

			while( ( remainder = q % 10 ) != 0 )
			{
				right_part_answer += remainder ;
				q-- ;
			}

			p /= 10 ;
			q /= 10 ;

			temp = ( q - p ) / tem_million ;
			left_part_answer += temp * 45 ;
			temp = ( q - p ) % tem_million ;
			right_part_answer += temp * 45 ;
			if( right_part_answer >= tem_million )
			{
				left_part_answer += right_part_answer / tem_million ;
				right_part_answer = right_part_answer % tem_million ;
			}
		}

		for( int i = p ; i <= q ; i++ )
		{
			if( i != 0 )
			{
				int dealing_i = i ;

				while( dealing_i % 10 == 0 )
				{
					dealing_i /= 10 ;
				}

				right_part_answer += dealing_i % 10 ;
			}
		}
		
		if( right_part_answer >= tem_million )
		{
			left_part_answer += right_part_answer / tem_million ;
			right_part_answer = right_part_answer % tem_million ;
		}

		if( left_part_answer != 0 )
		{
			cout << left_part_answer ;
		}
		
		cout << right_part_answer << endl ;
	}
	return 0 ;
}
