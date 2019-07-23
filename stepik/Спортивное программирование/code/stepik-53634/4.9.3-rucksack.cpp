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

ifstream cin("rucksack.in");
ofstream cout("output.txt");

const int INF = (int)1e9;

int n, W;
vvi dp;
vi c, w;

void rescan(int idx, int s, vi& ans) {
	if (dp[idx][s] == 0) return;
	if (dp[idx][s] == dp[idx - 1][s]) {
		rescan(idx - 1, s, ans);
	} else {
		rescan(idx - 1, s - w[idx], ans);
		ans.push_back(idx);
	}
}
int main() {

	cin >> n >> W;
	dp.resize(n + 1, vi(W + 1, 0));
	c.resize(n + 1);
	w.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> w[i] >> c[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= W; ++j) {
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}


	cout << dp[n][W] << endl;

	vi ans;
	rescan(n, W, ans);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';



	return 0;
}