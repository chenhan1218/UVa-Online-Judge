#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	int i = 0; // loop counter

	while (cin >> n && n != 0) {
		int maxSum = 0;
		int sum = 0;
		int temp = 0;
		bool isPrevPositive = false;
		for (i = 1; i <= n; i++) {
			cin >> temp;
			sum = max(temp, temp + sum);
			isPrevPositive = temp > 0;
			maxSum = max(maxSum, sum);
		}

		if (maxSum == 0) {
			cout << "Losing streak." << endl;
		} else {
			cout << "The maximum winning streak is " << maxSum << "." << endl;
		}
	}

	return 0;
}
