//============================================================================
// Name        : 196.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;

typedef map<int, int> ROW;
typedef map<int, ROW> GRID;

const int MAX_ROW = 999;
const int MAX_COLUMN = 18278;
string spreadsheets[MAX_ROW + 1][MAX_COLUMN + 1];
GRID cacheValue;

void readString(string &str) {
	cin >> str;
}

bool isNotDigit(char c) {
	return !(isdigit(c));
}

int letterColumn2idx(const char *str) {
	int base = 0;
	int count = 0;
	while ((*str) != 0) {
		count = count * 26 + *str - 'A';
		base = base * 26 + 1;
		str++;
	}
	return count + base;
}

void testletterColumn2idx() {
	assert(letterColumn2idx("A")==1);
	assert(letterColumn2idx("Z")==26);
	assert(letterColumn2idx("AA")==27);
	assert(letterColumn2idx("ZZ")==702);
	assert(letterColumn2idx("AAA")==703);
	assert(letterColumn2idx("ZZZ")==18278);
	cout << "testletterColumn2idx" << endl;
}

int itemValue(int r, int c) {
	ROW::const_iterator iter =

	cacheValue[r].find(c);
	if (iter == cacheValue[r].end()) {
		assert(spreadsheets[r][c].size() != 0);
		if (isalnum(spreadsheets[r][c][0])) {
			cacheValue[r][c] = atoi(spreadsheets[r][c].c_str());
		} else {
			string::iterator columnTag, rowTag, end;
			end = spreadsheets[r][c].begin();

			cacheValue[r][c] = 0;
			int (*unaryIsAlpha)(int) =isalpha;
			int (*unaryIsDigit)(int) =isdigit;
			while (1) {
				columnTag = find_if(end, spreadsheets[r][c].end(),
						unaryIsAlpha);
				rowTag = find_if(columnTag, spreadsheets[r][c].end(),
						unaryIsDigit);
				end = find_if(rowTag, spreadsheets[r][c].end(), isNotDigit);
				if (columnTag == spreadsheets[r][c].end()) {
					break;
				}

				cacheValue[r][c] += itemValue(
						atoi(
								spreadsheets[r][c].substr(
										rowTag - spreadsheets[r][c].begin(),
										end - rowTag).c_str()),
						letterColumn2idx(
								spreadsheets[r][c].substr(
										columnTag - spreadsheets[r][c].begin(),
										rowTag - columnTag).c_str()));
			}
		}
	}

	return cacheValue[r][c];
}

int main() {
	int caseCount = 0;

	cin >> caseCount;
	for (int caseIdx = 1; caseIdx <= caseCount; ++caseIdx) {
		int r, c;
		cin >> c >> r;

		for (int i = 1; i <= r; i++) {
			for_each(spreadsheets[i] + 1, spreadsheets[i] + c + 1, readString);
		}

		cacheValue.clear();
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (j != 1) {
					cout << " ";
				}
				cout << itemValue(i, j);
			}
			cout << endl;
		}
	}

	return 0;
}
