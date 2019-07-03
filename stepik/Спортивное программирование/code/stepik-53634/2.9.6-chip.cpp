#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

ifstream cin("input.txt");
ofstream cout("output.txt");


int n, m;
vi a;

void output() {
	for (int i = 0; i < n; ++i) {
		cout << (a[i] ? '*' : '.');
	}
	cout << endl;
}

void rec(int idx, int rest, int last_idx) {
	if (idx == n) {
		if (rest == 0) {
			output();
		}
		return;
	}
	if (last_idx + 1 < idx) {
		a[idx] = 1;
		rec(idx + 1, rest - 1, idx);
		a[idx] = 0;
	}
	rec(idx + 1, rest, last_idx);
}
int main() {
	cin >> n >> m;
	a.resize(n);
	rec(0, m, -2);

	return 0;
}