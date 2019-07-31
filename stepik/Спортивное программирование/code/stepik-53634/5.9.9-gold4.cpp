#include <string>
#include <numeric>
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

ifstream cin("gold4.in");
ofstream cout("output.txt");

int main() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	ll f = accumulate(a.begin(), a.begin() + n/2, 0LL);
	ll s = accumulate(a.begin() + n/2, a.begin() + n, 0LL);

	cout << abs(f - s);

	return 0;
}