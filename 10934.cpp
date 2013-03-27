#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	const int MAX_K = 100;
	const int MAX_TRIAL = 63;
	long long int max_determine_floor[MAX_K + 1][MAX_TRIAL + 1] = { { 0 } };

	for (int k = 1; k <= MAX_K; k++) {
		for (int trial = 1; trial <= MAX_TRIAL; trial++) {
			if (trial == 1) {
				max_determine_floor[k][trial] = 1;
			} else {
				max_determine_floor[k][trial] =
						max_determine_floor[k][trial - 1]
								+ max_determine_floor[k - 1][trial - 1] + 1;
			}
		}
	}

	long long int n = 0;
	long long int k = 0;
	while (cin >> k >> n) {
		if (k == 0) {
			break;
		}

		int trial = upper_bound(&max_determine_floor[k][0],
				&max_determine_floor[k][MAX_TRIAL + 1], n - 1)
				- &max_determine_floor[k][0];

		if (trial <= MAX_TRIAL) {
			cout << trial << endl;
		} else {
			cout << "More than " << MAX_TRIAL << " trials needed." << endl;
		}
	}
	return 0;
}
