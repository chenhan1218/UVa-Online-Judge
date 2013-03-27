//============================================================================
// Name        : 11450.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	while (t > 0) {
		t--;

		int m, c;
		int k = 0;
		int price = 0;
		cin >> m >> c;
		set<int> money;
		money.insert(0);
		for (int garmentIdx = 1; garmentIdx <= c; ++garmentIdx) {
			cin >> k;
			set<int> addedMoney;
			for (int model = 1; model <= k; model++) {
				cin >> price;
				for (set<int>::const_iterator iter = money.begin();
						iter != money.end(); ++iter) {
					if (*iter + price <= m) {
						addedMoney.insert(*iter + price);
					}
				}
			}
			money.swap(addedMoney);
		}

		if (money.empty()) {
			cout << "no solution" << endl;
		} else {
			cout << *(money.rbegin()) << endl;
		}
	}
	return 0;
}
