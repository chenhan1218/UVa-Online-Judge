//============================================================================
// Name        : 793.cpp
// Author      : swem
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <sstream>
#include <map>
using namespace std;

map<int, int> parent;

int getParent(const int &name) {
	if (0 == parent[name]) {
		parent[name] = name;
	}

	if (parent[name] != name) {
		parent[name] = getParent(parent[name]);
	}

	return parent[name];
}

bool union_set(const int &a, const int &b) {
	int a_parent = getParent(a);
	int b_parent = getParent(b);

	if (a_parent != b_parent) {
		parent[a_parent] = b_parent;
	}
	return true;
}

int main() {
	int t;

	cin >> t;

	for (int caseIdx = 1; caseIdx <= t; caseIdx++) {
		int f = 0;
		int connected = 0;
		int unConnected = 0;
		parent.clear();
		cin >> f;
		string buffer;
		getline(cin, buffer);
		while (getline(cin, buffer) && buffer.size() != 0) {
			istringstream iss(buffer);
			char command;
			int a, b;
			iss >> command >> a >> b;

			if ('c' == command) {
				union_set(a, b);
			} else {
				if (getParent(a) == getParent(b)) {
					connected++;
				} else {
					unConnected++;
				}
			}
		}

		if (caseIdx != 1) {
			cout << endl;
		}
		cout << connected << "," << unConnected << endl;
	}
	return 0;
}
