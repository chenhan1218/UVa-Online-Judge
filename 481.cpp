//============================================================================
// Name        : 481.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void print(int i) {
	cout << i << endl;
}

void printtab(int i) {
	cout << i << "\t";
}

int main() {
	vector<int> item;
	vector<int> seq;
	vector<int> position;
	int in = 0;

	while (cin >> in) {
		item.push_back(in);
		if (seq.empty()) {
			seq.push_back(in);
			position.push_back(0);
		} else {
			vector<int>::iterator iter = lower_bound(seq.begin(), seq.end(),
					in);
			position.push_back(iter - seq.begin());

			if (iter == seq.end()) {
				seq.push_back(in);
			} else {
				*iter = in;
			}
		}
	}

	unsigned int len = seq.size();
	seq.clear();
	vector<int>::reverse_iterator iter = position.rbegin();
	for (unsigned int itemIdx = len; itemIdx-- > 0;) {
		iter = find(iter, position.rend(), itemIdx);
		assert(iter != position.rend());
		seq.push_back(item[position.rend() - iter - 1]);
	}

	cout << seq.size() << endl;
	cout << '-' << endl;
	for_each(seq.rbegin(), seq.rend(), print);

	return 0;
}
