#include <iostream>
#include <map>
using namespace std;

int main() {
	int n = 0;
	while (cin >> n && n != 0) {
		int origin = 0;
		int target = 0;
		map<long long int, int> in;
		map<long long int, int> out;
		for (int i = 0; i < n; i++) {
			cin >> origin >> target;
			in[target]++;
			out[origin]++;
		}

		bool exchangable = true;

		for (map<long long int, int>::const_iterator iter = in.begin();
				iter != in.end(); iter++) {
			if (out[iter->first] != iter->second) {
				exchangable = false;
				break;
			}
		}

		if (exchangable) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
