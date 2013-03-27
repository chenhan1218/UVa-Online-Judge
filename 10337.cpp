//============================================================================
// Name        : 10337.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main() {
	const int MAX_HEIGHT = 9;
	const int MIN_HEIGHT = 0;
	map<int, map<int, long long int> > wind;
	map<int, map<int, long long int> > fuels;

	for (int altitude = MIN_HEIGHT - 1; altitude <= MAX_HEIGHT + 1;
			altitude++) {
		fuels[altitude][0] = INT_MAX;
	}
	fuels[MIN_HEIGHT][0] = 0;

	int n = 0;
	cin >> n;
	while (n > 0) {
		n--;

		int hundredMiles = 0;
		cin >> hundredMiles;
		hundredMiles /= 100;
		for (int altitude = MAX_HEIGHT; altitude >= MIN_HEIGHT; altitude--) {
			for (int miles = 0; miles < hundredMiles; miles++) {
				cin >> wind[altitude][miles];
			}
		}

		for (int miles = 1; miles <= hundredMiles; miles++) {
			fuels[MIN_HEIGHT - 1][miles] = INT_MAX;
			for (int altitude = MIN_HEIGHT; altitude <= MAX_HEIGHT;
					altitude++) {
				fuels[altitude][miles] = INT_MAX;
				fuels[altitude][miles] = min(fuels[altitude][miles],
						fuels[altitude - 1][miles - 1] + 60
								- wind[altitude - 1][miles - 1]);
				fuels[altitude][miles] = min(fuels[altitude][miles],
						fuels[altitude][miles - 1] + 30
								- wind[altitude][miles - 1]);
				fuels[altitude][miles] = min(fuels[altitude][miles],
						fuels[altitude + 1][miles - 1] + 20
								- wind[altitude + 1][miles - 1]);

				//		cout << fuels[altitude][miles] << "\t";
			}
			fuels[MAX_HEIGHT + 1][miles] = INT_MAX;
			//cout << endl;
		}

		cout << fuels[MIN_HEIGHT][hundredMiles] << endl;
		cout << endl;
	}

	return 0;
}
