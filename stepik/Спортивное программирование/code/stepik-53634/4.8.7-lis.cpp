#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("lis.in");
ofstream cout("output.txt");

int main() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vi dp(n);
	for (int i = 0; i < n; ++i) {
		int max_len = 0;
		for (int j = 0; j <= i - 1; ++j) {
			if (a[j] < a[i]) {
				max_len = max(max_len, dp[j]);
			}
		}
		dp[i] = max_len + 1;
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}