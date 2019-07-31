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

ifstream cin("salesman2.in");
ofstream cout("output.txt");

inline int bit_val(int mask, int bit) {
	return (mask & (1 << bit)) == 0 ? 0 : 1;
}

const int INF = (int)1e9;
int n;
vvi adj;

struct Item {
	int val;
	int prv;
	Item(int val, int prv): val(val), prv(prv) {}
};

void output(const vector<vector<Item>>& dp, int lst, int mask) {
	if (lst == 0) return;
	cout << ' ' << lst;
	output(dp, dp[lst][mask].prv, mask & ~(1 << lst));
}

int main() {
	cin >> n;
	adj.resize(n, vi(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> adj[i][j];
		}
	}
	vector<vector<Item>> dp(n, vector<Item>(1 << n, Item(INF, INF)));
	dp[0][1 << 0] = {0, -1};

	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int lst = 0; lst < n; ++lst) {
			if (dp[lst][mask].val != INF) {
				for (int nxt = 0; nxt < n; ++nxt) {
					if (bit_val(mask, nxt) == 0) {
						int nxt_mask = mask | (1 << nxt);
						Item& res = dp[nxt][nxt_mask];
						if (res.val > dp[lst][mask].val + adj[lst][nxt]) {
							res.val  = dp[lst][mask].val + adj[lst][nxt];
							res.prv  = lst;
						}
					}
				}
			}
		}
	}
	int mask = (1 << n) - 1;
	int ans_lst = 1;
	for (int lst = 1; lst < n; ++lst) {
		if (dp[ans_lst][mask].val + adj[ans_lst][0] > dp[lst][mask].val + adj[lst][0]) {
			ans_lst = lst;
		}
	}
	cout << dp[ans_lst][mask].val + adj[ans_lst][0] << endl;

	cout << 0;
	output(dp, ans_lst, mask);
	return 0;
}