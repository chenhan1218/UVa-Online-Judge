//============================================================================
// Name        : 11195.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

const int MAX_N = 14;
const int BITSIZE = MAX_N * 2;

void queen(int n, const int *grid, int *position, int mask, int diag1,
		int diag2, int depth, long long int &solutions) {
	if (depth == n) {
		solutions++;
	}

	int notPickable = grid[depth] | mask | (diag1 >> (n - depth))
			| (diag2 >> depth);
	for (int i = 0; i < n; i++) {
		int b = (1 << i);
		if ((notPickable & b) == 0) {
			mask ^= b;
			diag1 ^= (b << (n - depth));
			diag2 ^= (b << depth);
			position[depth] = i;

			queen(n, grid, position, mask, diag1, diag2, depth + 1, solutions);

			diag2 ^= (b << depth);
			diag1 ^= (b << (n - depth));
			mask ^= b;
		}
	}
}

int main() {
	int caseIdx = 0;
	int n = 0;

	while (cin >> n && n != 0) {
		++caseIdx;
		char c;
		int position[MAX_N] = { 0 };
		int grid[MAX_N] = { 0 };
		int diag1 = 0;
		int diag2 = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> c;
				if (c == '*') {
					grid[i] |= (1 << j);
				}
			}
		}

		long long int solutions = 0;
		int mask = 0;
		queen(n, grid, position, mask, diag1, diag2, 0, solutions);
		cout << "Case " << caseIdx << ": " << solutions << endl;
	}

	return 0;
}
