#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n;
vector<int> ans;

void output(int len) {
	for (int i = 0; i < len; ++i) {
		if (i) {
			cout << "+";
		}
		cout << ans[i];
	}
	cout << endl;
}
void gen(int idx, int rest, int last) {
	if (rest == 0) {
		output(idx);
		return;
	}
	for (int cur = last; cur <= rest; ++cur) {
		ans[idx] = cur;
		gen(idx + 1, rest - cur, cur);
	}
}

int main() {
	cin >> n;
	ans.resize(n);
	gen(0, n, 1);
	return 0;
}