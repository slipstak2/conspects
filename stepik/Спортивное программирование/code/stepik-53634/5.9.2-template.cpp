#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ifstream cin("input.txt");
ofstream cout("output.txt");

string s;
vi idxs;
string placement;
void gen_placement(int idx) {
	if (idx == placement.size()) {
		for (int i = 0, pos = 0; i < s.size(); ++i) {
			if (s[i] != '?') cout << s[i];
			else cout << placement[pos++];
		}
		cout << endl;
		return;
	}
	for (char c = 'a'; c <= 'e'; ++c) {
		placement[idx] = c;
		gen_placement(idx + 1);
		placement[idx] = ' ';  // debug
	}
}
int main() {

	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '?') {
			idxs.push_back(i);
		}
	}
	placement.resize(idxs.size(), ' ');

	gen_placement(0);

	return 0;
}