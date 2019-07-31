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

ifstream cin("friends2.in");
ofstream cout("output.txt");

inline int bit_val(int mask, int bit) {
	return (mask & (1 << bit)) == 0 ? 0 : 1;
}

vector<vector<bool>> adj;

int bit_count(int mask) {
	int cnt = 0;
	while (mask) {
		++cnt;
		mask &= mask -1;
	}
	return cnt;
}
int main() {

	int n, m;
	cin >> n >> m;
	adj.resize(n, vb(n));

	int u, v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		--u; --v;
		adj[u][v] = true;
		adj[v][u] = true;
	}

	vector<bool> dp(1 << n, false);
	dp[0] = true;
	int click_size = 0;
	for (int mask = 1; mask < (1 << n); ++mask) {
		for (int hbit = n - 1; hbit >= 0; --hbit) {
			if (bit_val(mask, hbit) == 1) {
				bool hbitFriend = true;
				for (int bit = hbit - 1; bit >= 0; --bit) {
					if (bit_val(mask, bit) == 1) {
						hbitFriend &= adj[hbit][bit];
					}
				}
				dp[mask] = hbitFriend & dp[mask & ~(1 << hbit)];
				if (dp[mask]) {
					click_size = max(click_size, bit_count(mask));
				}
				break;
			}
		}
	}
	cout << click_size;


	return 0;
}