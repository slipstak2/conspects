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

ifstream cin("seq2.in");
ofstream cout("output.txt");

int n, m;
vi a, b;
void input(vi& a, int& size) {
	cin >> size;
	a.resize(size + 1);
	for (int i = 1; i <= size; ++i) {
		cin >> a[i];
	}
}

int main() {
	input(a, n);
	input(b, m);

	vvi lcs(n + 1, vi(m + 1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int& res = lcs[i][j];
			if (a[i] == b[j]) {
				res = max(res, lcs[i - 1][j - 1] + 1);
			} else {
				res = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	cout << lcs[n][m] << endl;

	return 0;
}