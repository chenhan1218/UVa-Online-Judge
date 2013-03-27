#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, q;
	int caseIdx = 0;

	while (cin >> n >> q) {
		if (n == 0 && q == 0) {
			break;
		}

		caseIdx++;
		vector<int> marble(n);
		int query = 0;
		for (int i = 0; i < n; i++) {
			cin >> marble[i];
		}

		sort(marble.begin(), marble.end());

		cout << "CASE# " << caseIdx << ":" << endl;
		for (int i = 0; i < q; i++) {
			cin >> query;
			if (binary_search(marble.begin(), marble.end(), query)) {
				cout << query << " found at "
						<< lower_bound(marble.begin(), marble.end(), query)
								- marble.begin() + 1 << endl;
			} else {
				cout << query << " not found" << endl;
			}
		}
	}

	return 0;
}
