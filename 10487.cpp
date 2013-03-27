#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std ;

int main() {
	int caseidx = 0 ;
	long long int n,m;

	while( cin >> n ) {
		if( n == 0 ) {
			break ;
		}

		caseidx++ ;

		vector<long long int> integer ;
		set<long long int> sumset ;
		long long int buffer;
		long long int input = 0 ;
		long long int answer = 0 ;
		for( int i = 0 ; i < n ; i++ ) {
			cin >> buffer ;
			integer.push_back( buffer ) ;
		}

		vector<long long int>::const_iterator iter1 = integer.begin() ;
		for( int i = 0 ; i < n ; i++ ) {
			vector<long long int>::const_iterator iter2 = iter1 ;
			iter2++ ;
			while( iter2 != integer.end() ) {
				sumset.insert( *iter1 + *iter2 ) ;
				iter2++ ;
			}
			iter1++ ;
		}


		cout << "Case " << caseidx << ":" << endl ;

		vector<long long int> sumvec( sumset.begin(), sumset.end() ) ;
		cin >> m ;
		for( int i = 0 ; i < m ; i++ ) {
			cin >> input ;
			vector<long long int>::iterator iter = lower_bound( sumvec.begin(), sumvec.end(), input ) ;
			if( iter == sumvec.begin() ) {
				answer = *iter ;
			}
			else if( iter == sumvec.end() ) {
				answer = *(iter-1) ;
			}
			else {
				if( (input - *(iter-1)) < (*iter - input) ) {
					answer = *(iter-1) ;
				}
				else {
					answer = *iter ;
				}
			}

			cout << "Closest sum to " << input << " is " << answer << "." << endl ;
		}
	}
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std ;

	long long int integer[10000] ;
	long long int sumset[10000000] ;
int main() {
	int caseidx = 0 ;
	long long int n,m;

	while( cin >> n ) {
		if( n == 0 ) {
			break ;
		}

		caseidx++ ;

		long long int input = 0 ;
		long long int answer = 0 ;
		for( int i = 0 ; i < n ; i++ ) {
			cin >> integer[i] ;
			for( int j = 0 ; j < i ; j++ ) {
				sumset[ i*(i-1)/2 + j ] = integer[ j ] + integer[ i ] ;
			}
		}

		sort( sumset, sumset + n*(n-1)/2 ) ;

		cout << "Case " << caseidx << ":" << endl ;

		cin >> m ;
		for( int i = 0 ; i < m ; i++ ) {
			cin >> input ;
			long long int *iter = lower_bound( sumset, sumset+(n-1)*n/2, input ) ;
			if( iter == sumset ) {
				answer = *iter ;
			} else if ( iter == sumset + (n-1)*n/2 ) {
				answer = *(iter-1) ;
			}
			else {
				if( (input - *(iter-1)) < (*iter - input) ) {
					answer = *(iter-1) ;
				}
				else {
					answer = *iter ;
				}
			}

			cout << "Closest sum to " << input << " is " << answer << "." << endl ;
		}
	}
	return 0;
}
*/

