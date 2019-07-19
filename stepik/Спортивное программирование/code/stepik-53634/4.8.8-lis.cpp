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


ifstream cin("lis.in");
ofstream cout("output.txt");


int main() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vi len(n);
	vll cnt(n);
	for (int i = 0; i < n; ++i) {
		len[i] = 1;
		cnt[i] = 1;
		for (int j = 0; j <= i - 1; ++j) {
			if (a[j] < a[i]) {
				if (len[i] < len[j] + 1) {
					len[i] = len[j] + 1;
					cnt[i] = cnt[j];
				} else if (len[i] == len[j] + 1) {
					cnt[i] += cnt[j];
				}
			}
		}
	}

	int max_len = *max_element(len.begin(), len.end());

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		if (len[i] == max_len) {
			res += cnt[i];
		}
	}
	cout << res;
	return 0;
}