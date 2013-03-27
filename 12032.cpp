//============================================================================
// Name        : 12032.cpp
// Author      : swem
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
using namespace std;
const int MAX_RUNGS = 100000;
int rungs[MAX_RUNGS + 1] = { 0 };

int main() {
	int caseCount = 0;

	cin >> caseCount;
	for (int caseIdx = 1; caseIdx <= caseCount; caseIdx++) {
		int n = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> rungs[i];
		}

		int k = 0;
		for (int i = n; i >= 1; i--) {
			if (rungs[i] - rungs[i - 1] >= k) {
				k++;
			}
			k = max(k, rungs[i] - rungs[i - 1]);
		}

		cout << "Case " << caseIdx << ": " << k << endl;
	}

	return 0;
}
