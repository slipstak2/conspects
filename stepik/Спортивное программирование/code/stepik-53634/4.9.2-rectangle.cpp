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

ifstream cin("rectangle.in");
ofstream cout("output.txt");

int n, m;
vvll dp;

int main() {
	
	cin >> n >> m;
	vvi a(n + 1, vi(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	dp = vvll(n + 1, vll(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
		}
	}
	int q;
	int x1, y1, x2, y2;
	cin >> q;
	ll res = 0;
	for (int i = 0; i < q; ++i) {
		cin >> x1 >> x2 >> y1 >> y2;
		ll cur = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		res += cur;
	}
	cout << res;
	return 0;
}