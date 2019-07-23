#include <set>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("arithm2.in");
ofstream cout("output.txt");

struct Item {
	int val;
	int prv;
	Item(int val, int prv): val(val), prv(prv) {}
};

bool operator < (const Item& a, const Item& b) {
	return a.val < b.val;
}

void recout(const vector<set<Item>>& dp, int n, int sum) {
	if (n == -1) return;
	Item item = *dp[n].find(Item(sum, 0));
	recout(dp, n - 1, sum - item.prv);
	if (item.prv > 0 && n != 0) {
		cout << '+';
	}
	cout << item.prv;

}
int main() {
	int n, S;
	cin >> n >> S;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<set<Item>> dp(n);
	dp[0].insert(Item(a[0], a[0]));

	for (int i = 0; i < n - 1; ++i) {
		for (const Item& cur : dp[i]) {
			dp[i + 1].insert(Item(cur.val + a[i + 1], +a[i + 1]));
			dp[i + 1].insert(Item(cur.val - a[i + 1], -a[i + 1]));
		}
	}
	recout(dp, n - 1, S);
	return 0;
}