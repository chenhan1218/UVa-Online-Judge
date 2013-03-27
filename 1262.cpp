//============================================================================
// Name        : 1262.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	while (t > 0) {
		t--;

		const int ROWS = 6;
		const int COLS = 5;
		const int GRIDS = 2;
		set<char> s[GRIDS][COLS];
		char ch[COLS][ROWS];
		char c;
		int feasibleCharsCount[COLS];
		int feasiblePasswordCount = 0;
		int k = 0;
		cin >> k;

		for (int gridIdx = 0; gridIdx < GRIDS; gridIdx++) {
			for (int row = 0; row < ROWS; row++) {
				for (int col = 0; col < COLS; col++) {
					cin >> c;
					s[gridIdx][col].insert(c);
				}
			}
		}

		for (int col = 0; col < COLS; col++) {
			feasibleCharsCount[col] = set_intersection(s[0][col].begin(),
					s[0][col].end(), s[1][col].begin(), s[1][col].end(),
					ch[col]) - ch[col];
			if (col == 0) {
				feasiblePasswordCount = feasibleCharsCount[col];
			} else {
				feasiblePasswordCount *= feasibleCharsCount[col];
			}
		}

		if (k <= feasiblePasswordCount) {
			k--;
			for (int col = 0; col < COLS; col++) {
				int idx = k / (feasiblePasswordCount / feasibleCharsCount[col]);
				cout << ch[col][idx];

				k %= (feasiblePasswordCount / feasibleCharsCount[col]);
				feasiblePasswordCount /= feasibleCharsCount[col];
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
