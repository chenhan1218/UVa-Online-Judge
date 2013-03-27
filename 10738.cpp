#include <iostream>
#include <iomanip>
using namespace std;

#define MaxPrime 1000000

int previous[MaxPrime + 1] = { 0 };
int next[MaxPrime + 1] = { 0 };
int mu[MaxPrime + 1] = { 0 };
int m[MaxPrime + 1] = { 0 };
const int MAX_N = 1000000;

void initial(long long int n) {
	long long int i = 0; // loop counter

	previous[1] = 0;
	next[1] = 2;
	previous[2] = -1;
	next[2] = 3;
	previous[3] = 2;
	next[3] = 5;
	for (i = 3; i <= n; i += 2) {
		previous[i] = i - 2;
		next[i] = i + 2;
	}
}

void remove(int x) {
	next[previous[x]] = next[x];
	previous[next[x]] = previous[x];

	previous[x] = 0;
	next[x] = 0;
}

void cal(long long int n) {
	long long int numPrimes = 0;
	long long int prime = 0;
	long long int fact = 0;
	long long int mult = 0;

	initial(n);

	for (prime = 3; prime * prime <= n; prime = next[prime]) {
		for (fact = prime; prime * fact <= n; fact = next[fact]) {
			for (mult = prime * fact; mult <= n; mult *= prime) {
				remove(mult);
			}
		}
	}
}

bool exploreFactor(long long int n, long long int prime, int numFactor) {
	if (n <= MAX_N) {
		if (numFactor % 2 == 0) {
			mu[n] = 1;
		} else {
			mu[n] = -1;
		}

		while ((prime = next[prime]) && n * prime <= MAX_N) {
			exploreFactor(n * prime, prime, numFactor + 1);
		}
	}
	return true;
}

int main() {
	int n = 0;

	cal(MaxPrime);
	exploreFactor(1, 1, 0);

	for (int i = 1; i <= MAX_N; i++) {
		m[i] = m[i - 1] + mu[i];
	}

	while (cin >> n && n != 0) {
		cout << setw(8) << n << setw(8) << mu[n] << setw(8) << m[n] << endl;
	}

	return 0;
}

