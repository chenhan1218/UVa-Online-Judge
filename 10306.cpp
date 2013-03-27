//============================================================================
// Name        : 10306.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

int main() {
	const int MAX_S = 300;
	int n = 0;
	cin >> n;
	while (n > 0) {
		n--;
		int m, s;
		cin >> m >> s;
		long long int coins[MAX_S + 1][MAX_S + 1] = { { 0 } };
		for (int row = 0; row <= s; row++) {
			for (int col = 0; col <= s; col++) {
				coins[row][col] = INT_MAX;
			}
		}
		coins[0][0] = 0;

		int convention = 0;
		int infoTech = 0;
		for (int i = 0; i < m; i++) {
			cin >> convention;
			cin >> infoTech;

			for (int row = convention; row <= s; row++) {
				for (int col = infoTech; col <= s; col++) {
					if (row * row + col * col <= s * s) {
						coins[row][col] = min(coins[row][col],
								coins[row - convention][col - infoTech] + 1);
					}
				}
			}
		}

		long long int answer = INT_MAX;
		convention = 0;
		infoTech = s;
		while (convention <= s) {
			while (convention * convention + infoTech * infoTech > s * s) {
				infoTech--;
			}

			if (convention * convention + infoTech * infoTech == s * s) {
				answer = min(answer, coins[convention][infoTech]);
			}

			convention++;
		}

		if (answer == INT_MAX) {
			cout << "not possible" << endl;
		} else {
			cout << answer << endl;
		}
	}
	return 0;
}
