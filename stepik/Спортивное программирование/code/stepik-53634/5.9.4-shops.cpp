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

ifstream cin("shops2.in");
ofstream cout("output.txt");

int main() {
	int n;
	cin >> n;
	vll a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	vll b(n);
	for (int i = 0; i < n; ++i) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long delta = 0;
	for (int i = 0; i < n; ++i) {
		delta += abs(a[i] - b[i]);
	}
	cout << delta;
	return 0;
}