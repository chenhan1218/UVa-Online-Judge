//============================================================================
// Name        : 526.cpp
// Author      : swem
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

#define MaxCharacters 80

typedef pair<string::size_type, string::size_type> cell;

int d[MaxCharacters + 1][MaxCharacters + 1] = { { 0 } };
cell parent[MaxCharacters + 1][MaxCharacters + 1];

bool minimalInstruction(const string &a, const string &b) {
	string::size_type i = 0; // loop counter
	string::size_type j = 0; // loop counter

	for (i = 1; i <= a.size(); i++) {
		d[i][0] = i;
		parent[i][0] = cell(i - 1, 0);
	}

	for (j = 1; j <= b.size(); j++) {
		d[0][j] = j;
		parent[0][j] = cell(0, j - 1);
	}

	for (i = 1; i <= a.size(); i++) {
		for (j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				d[i][j] = d[i - 1][j - 1];
				parent[i][j] = cell(i - 1, j - 1);
			} else {
				d[i][j] = min(min(d[i - 1][j - 1] + 1, d[i - 1][j] + 1),
						d[i][j - 1] + 1);
				parent[i][j] = cell(i - 1, j - 1);

				if (d[i][j] == d[i - 1][j - 1] + 1) {
					parent[i][j] = cell(i - 1, j - 1);
				} else if (d[i][j] == d[i - 1][j] + 1) {
					parent[i][j] = cell(i - 1, j);
				} else {
					parent[i][j] = cell(i, j - 1);
				}
			}
		}
	}

	return true;
}

string backTrace(const string &a, const string &b) {
	string answer;
	string::size_type row = a.size();
	string::size_type column = b.size();

	while (row != 0 || column != 0) {
		assert(row < 100 && column < 100);
		ostringstream s;

		if (parent[row][column].first == row - 1
				&& parent[row][column].second == column - 1) {
			if (a[row - 1] != b[column - 1]) {
				s << d[row][column] << " Replace " << column << ","
						<< b[column - 1] << endl;
			}
			row--;
			column--;
		} else {
			if (parent[row][column].first == row - 1) {
				s << d[row][column] << " Delete " << column + 1 << endl;
				row--;
			} else {
				s << d[row][column] << " Insert " << column << ","
						<< b[column - 1] << endl;
				column--;
			}
		}

		answer = s.str() + answer;
	}

	return answer;
}

int main() {
	string a;
	string b;
	string ans;
	bool firstCase = true;

	while (getline(cin, a) && getline(cin, b)) {
		if (firstCase == true)
			firstCase = false;
		else
			cout << endl;

		minimalInstruction(a, b);
		cout << d[a.size()][b.size()] << endl;
		cout << backTrace(a, b);
	}

	return 0;
}
