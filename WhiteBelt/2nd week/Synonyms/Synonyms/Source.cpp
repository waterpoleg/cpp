#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
	int q;
	cin >> q;
	map<string, set<string>> synonyms;

	for (int i = 1; i <= q; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		}
		else if (cmd == "COUNT") {
			string word;
			cin >> word;
			cout << synonyms[word].size() << endl;
		}
		else if (cmd == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			if (synonyms[word1].count(word2)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}