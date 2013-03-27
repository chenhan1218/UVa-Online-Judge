//============================================================================
// Name        : 11242.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
using namespace std;

int main() {
	int f, r;
	while (cin >> f >> r) {
		vector<double> fs(f);
		vector<double> rs(r);
		for (int i = 0; i < f; i++) {
			cin >> fs[i];
		}
		for (int i = 0; i < r; i++) {
			cin >> rs[i];
		}

		set<double> s;
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < r; j++) {
				s.insert(rs[j] / fs[i]);
			}
		}

		double prev = 0;
		double maxSpread = 0;
		for (set<double>::const_iterator iter = s.begin(); iter != s.end();
				iter++) {
			if (iter != s.begin()) {
				maxSpread = max(maxSpread, *iter / prev);
			}
			prev = *iter;
		}

		cout << fixed << setprecision(2) << maxSpread << endl;
	}
	return 0;
}
