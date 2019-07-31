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

ifstream cin("new2.in");
ofstream cout("output.txt");

const int INF = (int)1e9;

inline int bit_val(int mask, int bit) {
	return (mask & (1 << bit)) == 0 ? 0 : 1;
}

int bit_count(int mask) {
	int cnt = 0;
	while (mask) {
		++cnt;
		mask &= mask - 1;
	}
	return cnt;
}

int main() {

	int n, m;
	cin >> n >> m;
	int TARGET = (1 << n) - 1;
	vi adj(n);
	for (int i = 0; i < n; ++i) {
		adj[i] |= 1 << i;
	}
	int u, v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		--u, --v;
		adj[u] |= 1 << v;
		adj[v] |= 1 << u;
	}

	int res = INF;
	for (int mask = 0; mask < (1 << n); ++mask) {
		int all_mask = 0;
		for (int bit = 0; bit < n; ++bit) {
			if (bit_val(mask, bit)) {
				all_mask |= adj[bit];
			}
		}
		if (all_mask == TARGET) {
			res = min(res, bit_count(mask));
		}
	}

	cout << res;

	return 0;
}