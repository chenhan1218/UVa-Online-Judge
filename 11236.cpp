//============================================================================
// Name        : 11236.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	const int MAX_PRICE = 2000;
	const int INTERVAL = 1000000;

	long long int ta = MAX_PRICE * INTERVAL;
	for (long long int a = 1; a * 4 <= MAX_PRICE && a * a * a * a <= ta; a++) {
		long long int tb = ta / a;
		for (long long int b = a; a + b * 3 <= MAX_PRICE && b * b * b <= tb;
				b++) {
			long long int tc = tb / b;
			for (long long int c = b; a + b + c * 2 <= MAX_PRICE && c * c <= tc;
					c++) {
				if (a * b * c > 1000000
						&& ((a + b + c) * 1000000) % (a * b * c - 1000000)
								== 0) {
					long long int d = ((a + b + c) * 1000000)
							/ (a * b * c - 1000000);

					if (d >= c && a + b + c + d <= MAX_PRICE) {
						cout << a / 100 << "." << setfill('0') << setw(2)
								<< a % 100 << " " << b / 100 << "."
								<< setfill('0') << setw(2) << b % 100 << " "
								<< c / 100 << "." << setfill('0') << setw(2)
								<< c % 100 << " " << d / 100 << "."
								<< setfill('0') << setw(2) << d % 100 << endl;
					}
				}
			}
		}
	}
	return 0;
}
