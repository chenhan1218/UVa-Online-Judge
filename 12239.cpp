//============================================================================
// Name        : 12239.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	const int MAX_N = 90;
	int array[MAX_N + 1] = { 0 };
	unsigned int n = 0;
	int b = 0;
	while (cin >> n >> b && n != 0 && b != 0) {
		for (int i = 0; i < b; i++) {
			cin >> array[i];
		}
		sort(array, array + b);

		set<int> s;
		for (int i = 0; i < b; i++) {
			for (int j = i + 1; j < b; j++) {
				s.insert(array[j] - array[i]);
			}
		}

		if (s.size() == n) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
	}

	return 0;
}
