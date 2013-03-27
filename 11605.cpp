#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	const int MAX_DIMENSIONS = 100;
	long double probSwitched[MAX_DIMENSIONS + 1][MAX_DIMENSIONS + 1] = { 0 };
	int cases = 0;

	for (int dimension = 1; dimension <= MAX_DIMENSIONS; dimension++) {
		for (int idx = 1; idx <= dimension; idx++) {
			probSwitched[dimension][idx] = (2 * idx * (dimension - idx + 1) - 1)
					/ (long double) dimension / (long double) dimension;
		}
	}

	cin >> cases;
	for (int caseCount = 1; caseCount <= cases; caseCount++) {
		int n, m, p, k;
		cin >> n >> m >> p >> k;
		long double expect = 0;

		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= m; b++) {
				for (int c = 1; c <= p; c++) {
					long double probSwitchedCell = probSwitched[n][a]
							* probSwitched[m][b] * probSwitched[p][c];
					// [unSwitched+(1-unSwitched)]^n  = unSwitched^n   +  ...  + (1-unSwitched)^n
					// [unSwitched-(1-unSwitched)]^n  = unSwitched^n   -  ...  + (1-unSwitched)^n
					// prob(switched on after k turn) = ([unSwitched+(1-unSwitched)]^n - [unSwitched-(1-unSwitched)]^n)/2
					expect += (1 - pow(1 - 2 * probSwitchedCell, k)) / 2;
				}
			}
		}

		cout << "Case " << caseCount << ": " << fixed << setprecision(10)
				<< expect << endl;
	}
	return 0;
}