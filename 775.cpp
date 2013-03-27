//============================================================================
// Name        : 775.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool dfs(int n, map<int, set<int> > &neighbor, vector<int> &cycle,
		const set<int> &unvisited) {
	if (unvisited.empty()) {
		if (neighbor[cycle.back()].find(1) != neighbor[cycle.back()].end()) {
			cycle.push_back(1);
			return true;
		} else {
			return false;
		}
	} else {
		set<int> unvisitedBuffer = unvisited;
		for (set<int>::const_iterator iter = unvisited.begin();
				iter != unvisited.end(); ++iter) {
			if (neighbor[cycle.back()].find(*iter)
					!= neighbor[cycle.back()].end()) {
				unvisitedBuffer.erase(*iter);
				cycle.push_back(*iter);
				if (dfs(n, neighbor, cycle, unvisitedBuffer)) {
					return true;
				}
				cycle.pop_back();
				unvisitedBuffer.insert(*iter);
			}
		}
		return false;
	}
}

int main() {
	unsigned int n = 0;
	while (cin >> n) {
		int a, b;
		char c;
		map<int, set<int> > neighbor;
		while (cin >> a >> b) {
			neighbor[a].insert(b);
			neighbor[b].insert(a);
		}
		cin.clear();
		cin >> c;

		vector<int> cycle;
		set<int> unvisited;
		for (unsigned int i = 1; i <= n; i++) {
			unvisited.insert(i);
		}

		cycle.push_back(1);
		unvisited.erase(1);
		dfs(n, neighbor, cycle, unvisited);

		if (cycle.size() == n + 1) {
			for (vector<int>::const_iterator iter = cycle.begin();
					iter != cycle.end(); ++iter) {
				if (iter != cycle.begin()) {
					cout << ' ';
				}
				cout << *iter;
			}
			cout << endl;
		} else {
			cout << "N" << endl;
		}
	}

	return 0;
}
