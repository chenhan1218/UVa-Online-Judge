//============================================================================
// Name        : 10401.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		size_t len = str.size();
		vector<long long int> possible(len + 2);

		for (size_t col = 0; col < len; col++) {
			vector<long long int> p(len + 2);

			if (0 == col) {
				fill_n(p.begin() + 1, len, 1);
			} else {
				fill_n(p.begin() + 1, len,
						accumulate(possible.begin(), possible.end(),
								(long long int) 0));

				transform(p.begin() + 1, p.begin() + len + 1, possible.begin(),
						p.begin() + 1, minus<long long int>());
				transform(p.begin() + 1, p.begin() + len + 1,
						possible.begin() + 1, p.begin() + 1,
						minus<long long int>());
				transform(p.begin() + 1, p.begin() + len + 1,
						possible.begin() + 2, p.begin() + 1,
						minus<long long int>());
			}

			possible = p;
			if (isxdigit(str[col])) {
				int idx = strtol(string(1, str[col]).c_str(), NULL, 16);
				long long int constrainedArrange = possible[idx];
				fill(possible.begin(), possible.end(), 0);
				possible[idx] = constrainedArrange;
			}
		}

		cout << accumulate(possible.begin(), possible.end(), (long long int) 0)
				<< endl;
	}

	return 0;
}
