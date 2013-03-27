/*
 * 821.cpp
 *
 *  Created on: Sep 25, 2012
 *      Author: stanleyhsiao
 */

#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

int main() {
	int caseIdx = 0;
	int a, b;
	const int MAX_PAGE = 100;
	int clicks[MAX_PAGE + 1][MAX_PAGE + 1] = { { 0 } };

	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}

		caseIdx++;
		set<int> pages;
		int sumClicks = 0;
		for (int i = 1; i <= MAX_PAGE; i++) {
			for (int j = 1; j <= MAX_PAGE; j++) {
				clicks[i][j] = MAX_PAGE;
			}
		}

		do {
			if (a == 0 && b == 0)
				break;

			clicks[a][b] = 1;
			pages.insert(a);
			pages.insert(b);
		} while (cin >> a >> b);

		//Floyd–Warshall algorithm
		for (set<int>::const_iterator k = pages.begin(); k != pages.end();
				k++) {
			for (set<int>::const_iterator a = pages.begin(); a != pages.end();
					a++) {
				for (set<int>::const_iterator b = pages.begin();
						b != pages.end(); b++) {
					clicks[*a][*b] = min(clicks[*a][*b],
							clicks[*a][*k] + clicks[*k][*b]);
				}
			}
		}

		// accumulate all clicks
		for (set<int>::const_iterator a = pages.begin(); a != pages.end();
				a++) {
			for (set<int>::const_iterator b = pages.begin(); b != pages.end();
					b++) {
				if (a != b) {
					sumClicks += clicks[*a][*b];
				}
			}
		}

		cout << fixed;
		cout << "Case " << caseIdx << ": average length between pages = "
				<< setprecision(3)
				<< sumClicks / (double) (pages.size() * (pages.size() - 1))
				<< " clicks" << endl;
	}

	return 0;
}

