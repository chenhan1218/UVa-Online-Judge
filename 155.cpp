/*
 * 155.cpp
 *
 *  Created on: Sep 20, 2012
 *      Author: stanleyhsiao
 */

#include <iostream>
#include <iomanip>
using namespace std;

int abs(int i) {
	if (i >= 0)
		return i;
	else
		return -1 * i;
}

int main() {
	int k, x, y;

	while (cin >> k >> x >> y) {
		if (k == 0 && x == 0 && y == 0) {
			break;
		}

		x -= 1024;
		y -= 1024;
		int counter = 0;
		while (k > 0) {
			if (abs(x) <= k && abs(y) <= k) {
				counter++;
			}
			x = abs(x) - k;
			y = abs(y) - k;
			k /= 2;
		}

		cout << fixed ;
		cout << setw(3) << counter << endl;
	}

	return 0;
}

