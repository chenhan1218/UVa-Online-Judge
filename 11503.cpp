//============================================================================
// Name        : 11503.cpp
// Author      : swem
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <map>
using namespace std;

map<string, string> parent;
map<string, int> rank;

string getParent(const string &name) {
	if ("" == parent[name]) {
		parent[name] = name;
		rank[name] = 1;
	}

	if (parent[name] != name) {
		parent[name] = getParent(parent[name]);
	}

	return parent[name];
}

int getRank(const string &name) {
	if (getParent(name) == name) {
		return rank[name];
	} else {
		return getRank(getParent(name));
	}
}

bool union_set(const string &a, const string &b) {
	string a_parent = getParent(a);
	string b_parent = getParent(b);

	if (a_parent != b_parent) {
		if (getRank(a_parent) < getRank(b_parent)) {
			parent[a_parent] = b_parent;
			rank[b_parent] += rank[a_parent];
		} else {
			parent[b_parent] = a_parent;
			rank[a_parent] += rank[b_parent];
		}
	}
	return true;
}

int main() {
	int t;

	cin >> t;

	for (int caseIdx = 1; caseIdx <= t; caseIdx++) {
		int f = 0;
		parent.clear();
		rank.clear();
		cin >> f;
		for (int i = 0; i < f; i++) {
			string a, b;
			cin >> a >> b;

			union_set(a, b);
			cout << getRank(a) << endl;
		}
	}
	return 0;
}
