#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("bug2.in");
ofstream cout("output.txt");

void recout(int i, int j, const vvi &p) {
	if (i == 0 && j == 0) {
		return;
	}
	if (p[i][j] == 0) {
		recout(i - 1, j, p);
		cout << 'D';
	}
	if (p[i][j] == 1) {
		recout(i, j - 1, p);
		cout << 'R';
	}
}

int main() {
	int n, m;
	cin >> n >> m ;
	vvi a(n, vi(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	vvi dp(n, vi(m));
	vvi p(n, vi(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = a[i][j];
			if (i > 0 && dp[i][j] < dp[i - 1][j] + a[i][j]) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
				p[i][j] = 0;
			}
			if (j > 0 && dp[i][j] < dp[i][j - 1] + a[i][j]) {
				dp[i][j] = dp[i][j - 1] + a[i][j];
				p[i][j] = 1;
			}
		}
	}
	cout << dp[n - 1][m - 1] << endl;
	recout(n - 1, m - 1, p);

	return 0;
}