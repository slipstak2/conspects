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

ifstream cin("input.txt");
ofstream cout("output.txt");

vvll C;

ll solve(int n, int k) {
	if (C[n][k] != 0) return C[n][k];
	if (k == 0) return 1;
	if (k == n) return 1;

	ll &res = C[n][k];
	res = solve(n - 1, k - 1) + solve(n - 1, k);
	return res;
}
int main() {

	int n, k;
	cin >> n >> k;
	C.resize(n + 1, vll(n + 1));

	cout << solve(n, k);
	return 0;
}