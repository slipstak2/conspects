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

ifstream cin("gold2.in");
ofstream cout("output.txt");

int S;
int n;
vi W;
int main() {
	cin >> n;
	W.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> W[i];
		S += W[i];
	}
	vector<bool> dp(S + 1);
	dp[0] = true;
	for (int w : W) {
		for (int i = S; i >= 0; --i) {
			if (i - w >= 0 && dp[i - w]) {
				dp[i] = true;
			}
		}
	}
	int res = S;
	for (int i = 0; i <= S; ++i) {
		if (dp[i]) {
			res = min(res, abs(S - 2 * i));
		}
	}
	cout << res;

	return 0;
}