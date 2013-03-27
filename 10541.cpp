//============================================================================
// Name        : 10541.cpp
// Author      :
// Version     :
// Copyright   : copyright notice
//============================================================================

#include <iostream>
using namespace std;

#ifdef UNIT_TEST
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE acm
#include <boost/test/unit_test.hpp>
#endif

#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <cstring>
//
// need to include <sstream>, <iomanip>, <cstdlib>, <algorithm>, <string>
//
class bigint {
	friend ostream& operator<<(ostream& os, const bigint& b) {
		os << b.toString();
		return os;
	}
	friend istream& operator>>(istream& is, bigint& b) {
		string input;
		is >> input;
		b = bigint(input);
		return is;
	}

public:
	int v[10000];
	int size;
	static const int N, Ndigit;
	bigint(int x) {
		memset(v, 0, sizeof(v));
		v[0] = x % N, size = 1, x /= N;
		while (x != 0)
			v[size] = x % N, size++, x /= N;
	}
	bigint() {
		memset(v, 0, sizeof(v));
		size = 1;
	}

	bigint(string input) {
		int i = 0;
		while (input.size() > 1 && input[0] == '0')
			input.erase(0, 1);
		size = 0;
		while (input.size() >= Ndigit) {
			v[size] = atoi(input.substr(input.size() - Ndigit).c_str());
			size++;
			input = input.substr(0, input.size() - Ndigit);
		}
		if (input.size() != 0) {
			v[size] = atoi(input.c_str());
			size++;
		}
	}

	int compare(const bigint& x) {
		if (size != x.size)
			return size - x.size;
		for (int i = size - 1; i >= 0; i--) {
			if (v[i] != x.v[i])
				return v[i] - x.v[i];
		}
		return 0;
	}

	bool operator==(const bigint& x) {
		if (size != x.size)
			return false;
		for (int i = size - 1; i >= 0; i--) {
			if (v[i] != x.v[i])
				return false;
		}
		return true;
	}

	int compare(int x) {
		bigint bigintX(x);
		return compare(bigintX);
	}

	bigint& operator=(const bigint& x) {
		memset(v, 0, sizeof(v));
		copy(x.v, x.v + x.size, v);
		size = x.size;
		return *this;
	}

	bigint& operator=(int x) {
		memset(v, 0, sizeof(v));
		v[0] = x % N, size = 1, x /= N;
		while (x != 0)
			v[size] = x % N, size++, x /= N;
		return *this;
	}

	bigint operator+(const bigint& x) {
		bigint sum = 0;
		long long int carry = 0;
		int i = 0;
		for (i = 0; i < x.size || i < size; i++) {
			carry += v[i] + x.v[i];
			if (carry >= N)
				sum.v[i] = carry - N, carry = 1;
			else
				sum.v[i] = carry, carry = 0;
		}
		if (carry > 0)
			sum.v[i] = carry, i += 1;
		sum.size = i;
		return sum;
	}

	bigint& operator+=(const bigint& x) {
		*this = *this + x;
		return *this;
	}

	bigint operator*(int x) const {
		bigint mul = 0;
		if (x == 0)
			return mul;
		long long int i = 0, carry = 0;
		for (i = 0; i < size; i++) {
			carry += (long long int) v[i] * x;
			mul.v[i] = carry % N;
			carry /= N;
		}
		while (carry > 0)
			mul.v[i] = carry % N, carry /= N, i++;
		mul.size = i;
		return mul;
	}

	bigint& operator*=(int x) {
		*this = *this * x;
		return *this;
	}

	bigint operator*(const bigint& x) const {
		bigint mul = 0;
		int i = 0;
		if (x.size <= size) {
			for (i = x.size - 1; i >= 0; i--) {
				mul *= N;
				mul += *this * x.v[i];
			}
		} else {
			for (i = size - 1; i >= 0; i--) {
				mul *= N;
				mul += x * v[i];
			}
		}
		return mul;
	}

	bigint& operator*=(const bigint& x) {
		*this = *this * x;
		return *this;
	}

	bigint operator-(const bigint& x) {
		bigint sub;
		long long int i = 0, carry = 0;
		for (i = 0; i < x.size; i++) {
			carry = v[i] - x.v[i] + carry;
			if (carry < 0)
				sub.v[i] = carry + N, carry = -1;
			else
				sub.v[i] = carry, carry = 0;
		}
		for (; i < size; i++) {
			carry = v[i] + carry;
			if (carry < 0)
				sub.v[i] = carry + N, carry = -1;
			else
				sub.v[i] = carry, carry = 0;
		}
		sub.size = size;
		while (sub.v[sub.size - 1] == 0 && sub.size > 1)
			sub.size -= 1;
		return sub;
	}

	bigint& operator-=(const bigint& x) {
		*this = *this - x;
		return *this;
	}

	void divideBy2() {
		long long int i = 0, carry = 0;
		for (i = size - 1; i >= 0; i--) {
			carry = v[i] + carry * N;
			v[i] = carry / 2;
			carry %= 2;
		}
		if (v[size - 1] == 0 && size > 1)
			size--;
	}

	bigint operator/(const bigint& x) {
		bigint quotient;
		bigint remainder = *this;
		bigint quotientPart(1);
		bigint Xpow2s = x;

		while (remainder.compare(Xpow2s) > 0) {
			Xpow2s += Xpow2s, quotientPart += quotientPart;
		}

		while (remainder.compare(x) >= 0) {
			if (remainder.compare(Xpow2s) >= 0)
				remainder -= Xpow2s, quotient += quotientPart;
			Xpow2s.divideBy2(), quotientPart.divideBy2();
		}

		return quotient;
	}

	bigint operator%(const bigint& x) {
		bigint quotient;
		bigint remainder = *this;
		bigint quotientPart(1);
		bigint Xpow2s = x;

		while (remainder.compare(Xpow2s) > 0) {
			Xpow2s += Xpow2s, quotientPart += quotientPart;
		}

		while (remainder.compare(x) >= 0) {
			if (remainder.compare(Xpow2s) >= 0)
				remainder -= Xpow2s, quotient += quotientPart;
			Xpow2s.divideBy2(), quotientPart.divideBy2();
		}

		return remainder;
	}

	string toString() const {
		ostringstream buffer;
		buffer << v[size - 1];
		for (int i = size - 2; i >= 0; i--)
			buffer << setw(Ndigit) << setfill('0') << v[i];
		return buffer.str();
	}
};

const int bigint::N = 1000000000;
const int bigint::Ndigit = 9;

bigint combinations(long long int n, long long int k) {
	bigint ans(1);
	if (k > n - k) {
		k = n - k;
	}

	for (long long int idx = 1; idx <= k; idx++) {
		ans *= (n - idx + 1);
		ans = ans / idx;
	}
	return ans;
}

bigint combination_multiset(long long int n, long long int k) {
	return combinations(n + k - 1, k - 1);
}

#ifdef UNIT_TEST
BOOST_AUTO_TEST_SUITE(test)

BOOST_AUTO_TEST_CASE(testbiginteger) {
	bigint a(1);
	a = a * bigint(2);
	BOOST_CHECK(a == bigint(2));
	a = a * bigint(3);
	BOOST_CHECK(a == bigint(6));
	a = a * bigint(4);
	BOOST_CHECK(a == bigint(24));
	a = a * bigint(5);
	BOOST_CHECK(a == bigint(120));
	a = a * bigint(6);
	BOOST_CHECK(a == bigint(720));
	a = a / bigint(1);
	BOOST_CHECK(a == bigint(720));
	a = a / bigint(2);
	BOOST_CHECK(a == bigint(360));
	a = a / bigint(3);
	BOOST_CHECK(a == bigint(120));
}

BOOST_AUTO_TEST_CASE(testcombinations) {
	BOOST_CHECK(combinations(2, 2) == bigint(1));
	BOOST_CHECK(combinations(6, 3) == bigint(20));
	BOOST_CHECK(combinations(0, 0) == bigint(1));
}

BOOST_AUTO_TEST_CASE(testcombination_multiset) {
	BOOST_CHECK(combination_multiset(1, 3) == bigint(3));
	BOOST_CHECK(combination_multiset(2, 2) == bigint(3));
	BOOST_CHECK(combination_multiset(6, 3) == bigint(28));
	BOOST_CHECK(combination_multiset(0, 0) == bigint(1));
}
BOOST_AUTO_TEST_SUITE_END()
#else
int main() {
	int cases = 0;
	cin >> cases;
	for (int caseIdx = 1; caseIdx <= cases; ++caseIdx) {
		int n, k, num, white;

		cin >> n >> k;
		white = n;
		for (int i = 0; i < k; ++i) {
			cin >> num;
			white -= num;
		}

		if (k == 0) {
			cout << 1 << endl;
		} else {
			if (white >= k - 1) {
				cout << combination_multiset(white - (k - 1), k + 1) << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}

	return 0;
}
#endif
