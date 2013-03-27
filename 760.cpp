#include <iostream>
#include <string>
#include <set>
using namespace std;

const int MAX_LENGTH = 300;
bool common[MAX_LENGTH + 1][MAX_LENGTH][MAX_LENGTH] = { { { 0 } } };

int main() {
	bool firstCase = true;
	string a;
	string b;

	for (int i = 0; i < MAX_LENGTH; i++) {
		for (int j = 0; j < MAX_LENGTH; j++) {
			common[0][i][j] = true;
		}
	}

	while (getline(cin, a) && getline(cin, b)) {
		string::size_type longest_common = 0;

		for (string::size_type common_length = 1;
				common_length <= min(a.length(), b.length()); common_length++) {
			for (string::size_type i = 0; i < a.length(); i++) {
				for (string::size_type j = 0; j < b.length(); j++) {
					if (common[common_length - 1][i][j]
							&& i + common_length - 1 < a.length()
							&& j + common_length - 1 < b.length()
							&& a[i + common_length - 1]
									== b[j + common_length - 1]) {
						common[common_length][i][j] = true;
						longest_common = max(longest_common, common_length);
					} else {
						common[common_length][i][j] = false;
					}
				}
			}
		}

		if (firstCase) {
			firstCase = false;
		} else {
			cout << endl;
		}

		if (longest_common == 0) {
			cout << "No common sequence." << endl;
		} else {
			set<string> common_set;
			for (string::size_type i = 0; i < a.length(); i++) {
				for (string::size_type j = 0; j < b.length(); j++) {
					if (common[longest_common][i][j]) {
						common_set.insert(a.substr(i, longest_common));
					}
				}
			}

			for (set<string>::const_iterator iter = common_set.begin();
					iter != common_set.end(); iter++) {
				cout << *iter << endl;
			}
		}

		getline(cin, a);
	}

	return 0;
}

/* runtime error
 #include <iostream>
 #include <string>
 #include <set>
 using namespace std;

 const int MAX_LENGTH = 300;
 bool common[MAX_LENGTH + 1][MAX_LENGTH][MAX_LENGTH] = { { { 0 } } };

 int main() {
 bool firstCase = true;
 string a;
 string b;

 for (int i = 0; i < MAX_LENGTH; i++) {
 for (int j = 0; j < MAX_LENGTH; j++) {
 common[0][i][j] = true;
 }
 }

 while (cin >> a && cin >> b) {
 set<string> s[MAX_LENGTH + 1];
 for (string::size_type common_length = 1; common_length <= a.length();
 common_length++) {
 for (string::size_type i = 0; i < a.length() - common_length + 1;
 i++) {
 for (string::size_type j = 0;
 j < b.length() - common_length + 1; j++) {
 if (common[common_length - 1][i][j]
 && a[i + common_length - 1]
 == b[j + common_length - 1]) {
 common[common_length][i][j] = true;
 s[common_length].insert(a.substr(i, common_length));
 } else {
 common[common_length][i][j] = false;
 }
 }
 }
 }

 string::size_type longest_common = a.length();
 while (longest_common > 0) {
 if (s[longest_common].empty()) {
 longest_common--;
 } else {
 break;
 }
 }

 if (firstCase) {
 firstCase = false;
 } else {
 cout << endl;
 }

 if (longest_common == 0) {
 cout << "No common sequence." << endl;
 } else {
 for (set<string>::const_iterator iter = s[longest_common].begin();
 iter != s[longest_common].end(); iter++) {
 cout << *iter << endl;
 }
 }
 }

 return 0;
 }

 */
