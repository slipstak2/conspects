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

ifstream cin("time2.in");
ofstream cout("output.txt");

int main() {
	int n;
	cin >> n;
	vi T(n + 1), START(n + 1);
	int maxStart = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> T[i] >> START[i];
		maxStart = max(maxStart, START[i]);
	}
	vvi dp(n + 1, vi(2 * maxStart + 1, 0));
	dp[0][0] = 0;

	for (int t = 0; t <= maxStart; ++t) {
		for (int i = 0; i < n; ++i) {
			if (t <= START[i + 1]) {
				dp[i + 1][t + T[i + 1]] = max(dp[i + 1][t + T[i + 1]], dp[i][t] + 1);
			}
			dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
		}
	}
	cout << *max_element(dp[n].begin(), dp[n].end());

	return 0;
}