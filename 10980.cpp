//============================================================================
// Name        : 10980.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <climits>
using namespace std;

typedef pair<int, int> priceTag;

int main() {
	const int MAX_K = 100;
	int cent;
	int dollar;
	char c;
	int caseIdx = 0;
	while (cin >> dollar >> c >> cent) {
		caseIdx++;
		set<priceTag> item2cent;
		map<int, int> lowest;
		int m, n;

		item2cent.insert(priceTag(1, dollar * 100 + cent));
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> n >> dollar >> c >> cent;
			item2cent.insert(priceTag(n, dollar * 100 + cent));
		}

		lowest[0] = 0;
		for (int k = 1; k <= MAX_K; k++) {
			lowest[k] = INT_MAX;
			for (set<priceTag>::const_iterator iter = item2cent.begin();
					iter != item2cent.end(); ++iter) {
				n = (*iter).first;
				cent = (*iter).second;
				lowest[k] = min(lowest[k], lowest[max(k - n, 0)] + cent);
			}
		}

		string str;
		getline(cin, str);
		getline(cin, str);
		istringstream iss(str);
		int k = 0;

		cout << "Case " << caseIdx << ":" << endl;
		while (iss >> k) {
			cout << "Buy " << k << " for $" << lowest[k] / 100 << "." << setw(2)
					<< setfill('0') << lowest[k] % 100 << endl;
		}
	}

	return 0;
}
