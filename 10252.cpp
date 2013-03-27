#include <iostream>
#include <string>
using namespace std;

int main() {
	const int NUM_LETTERS = 26;
	string a;
	string b;

	while (getline(cin, a) && getline(cin, b)) {
		int letters[2][NUM_LETTERS] = { { 0 } };
		for (string::size_type i = 0; i < a.length(); i++) {
			letters[0][a[i] - 'a']++;
		}
		for (string::size_type i = 0; i < b.length(); i++) {
			letters[1][b[i] - 'a']++;
		}

		for (int i = 0; i < NUM_LETTERS; i++) {
			for (int j = 0; j < min(letters[0][i], letters[1][i]); j++) {
				cout << (char) ('a' + i);
			}
		}
		cout << endl;
	}

	return 0;
}
