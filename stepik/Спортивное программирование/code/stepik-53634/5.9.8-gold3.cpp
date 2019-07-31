#include <set>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("gold3.in");
ofstream cout("output.txt");

int main() {
	int n;
	cin >> n;
	vector<int> W(n);
	long long S = 0;
	for (int i = 0; i < n; ++i) {
		cin >> W[i];
		S += W[i];
	}
	set<long long> dp;
	dp.insert(0);
	
	for (int w : W) {
		for (auto it = dp.rbegin(); it != dp.rend(); ++it) {
			dp.insert(*it + w);
		}
	}
	long long res = S;
	for (auto x: dp) {
		res = min(res, abs(S - 2 * x));
	}
	cout << res;

	return 0;
}