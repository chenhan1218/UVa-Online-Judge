//============================================================================
// Name        : 11385.cpp
// Author      :
// Version     :
// Copyright   : copyright notice
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

#ifndef ONLINE_JUDGE
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE acm
#include <boost/test/unit_test.hpp>
#endif

#ifdef ONLINE_JUDGE
int main() {
	int caseCount = 0;
	map<long long int, long long int> fibonacci;
	map<long long int, long long int> fiIndex;
	fibonacci[1] = 1;
	fibonacci[2] = 2;
	fiIndex[1] = 1;
	fiIndex[2] = 2;
	for (int i = 3; i <= 90; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		fiIndex[fibonacci[i]] = i;
	}
	cin >> caseCount;

	for (int caseIdx = 1; caseIdx <= caseCount; ++caseIdx) {
		string cipher;
		string decrypted;
		int n = 0;
		cin >> n;

		vector<long long int> series(n);
		for (int i = 0; i < n; ++i) {
			cin >> series[i];
		}
		getline(cin, cipher);
		getline(cin, cipher);
		int count = 0;
		for (string::const_iterator iter = cipher.begin();
				iter != cipher.end() && count < n; ++iter) {
			if (isalpha(*iter) && isupper(*iter)) {
				if (fiIndex[series[count]] > decrypted.size()) {
					decrypted.resize(fiIndex[series[count]], ' ');
				}

				decrypted[fiIndex[series[count]] - 1] = *iter;
				count++;
			}
		}
		cout << decrypted << endl;
	}
	return 0;
}
#else
BOOST_AUTO_TEST_SUITE(test);
BOOST_AUTO_TEST_CASE(testSmall) {
	//BOOST_CHECK(combinations(0, 0) == 1);
}
BOOST_AUTO_TEST_SUITE_END()
#endif
