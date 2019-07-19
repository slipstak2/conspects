#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("change.in");
ofstream cout("output.txt");

const int INF = 1e9;
int main() {
	int n, T;
	cin >> n >> T;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vi dp(T + 1, INF);

	dp[0] = 0;
	for (int i = 1; i <= T; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - a[j] >= 0) {
				dp[i] = min(dp[i], dp[i - a[j]] + 1);
			}
		}
	}

	cout << dp[T];
	return 0;
}