#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t ;

	cin >> t ;
	for( int caseidx = 1 ; caseidx <= t ; caseidx++ ) {
		int buffer[3];
		cin >> buffer[0] >> buffer[1] >> buffer[2] ;
		sort(buffer, buffer+3) ;

		cout << "Case " << caseidx << ": " << buffer[1] << endl ;
	}
	return 0 ;
}
