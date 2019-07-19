#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("ice2.in");
ofstream cout("output.txt");

int main() {
	int n;
	cin >> n;
	string name;
	set<string> cur;

	int cnt = 1;
	for (int i = 0; i < n; ++i) {
		cin >> name;
		if (cur.find(name) == cur.end()) {
			cur.insert(name);
		} else {
			cur.clear();
			cur.insert(name);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}