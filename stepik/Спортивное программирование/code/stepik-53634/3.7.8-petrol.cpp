#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("petrol2.in");
ofstream cout("output.txt");

int main() {

	int n, dist, fullVolume;
	cin >> n >> dist >> fullVolume;

	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	a.push_back(dist);

	int curVolume = fullVolume;

	int cnt = 0;
	int last_p = 0;
	for (int i = 0; last_p != dist; ) {
		int nxt = -1;
		int idx = i;

		for (idx = i; idx < a.size(); ++idx) {
			if (a[idx] - last_p <= fullVolume) {
				nxt = idx;
			} else {
				break;
			}
		}
		i = nxt;
		last_p = a[i];

		if (last_p != dist) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}