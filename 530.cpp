//============================================================================
// Name        : 530.cpp
// Author      :
// Version     :
// Copyright   : copyright notice
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#ifndef ONLINE_JUDGE
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE acm
#include <boost/test/unit_test.hpp>
#endif

long long combinations(long long int n, long long int k) {
	long long int ans = 1;
	if (k > n - k) {
		k = n - k;
	}

	for (long long int idx = 1; idx <= k; idx++) {
		ans *= (n - idx + 1);
		ans = ans / idx;
	}
	return ans;
}

#ifdef ONLINE_JUDGE
int main() {
	long long int n, k;
	while (cin >> n >> k) {
		if (n == 0 && k == 0) {
			break;
		}

		cout << combinations(n, k) << endl;
	}
	return 0;
}
#else
BOOST_AUTO_TEST_SUITE(test)

BOOST_AUTO_TEST_CASE(testSmall) {
	BOOST_CHECK(combinations(0, 0) == 1);
	BOOST_CHECK(combinations(2, 2) == 1);
	BOOST_CHECK(combinations(2, 1) == 2);
	BOOST_CHECK(combinations(4, 2) == 6);
	BOOST_CHECK(combinations(6, 3) == 20);
	BOOST_CHECK(combinations(10, 5) == 252);
}

BOOST_AUTO_TEST_CASE(testLarge) {
	BOOST_CHECK(combinations(49, 6) == 13983816);
}

BOOST_AUTO_TEST_SUITE_END()
#endif
