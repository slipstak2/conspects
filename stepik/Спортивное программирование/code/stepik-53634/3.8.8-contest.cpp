#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("contest.in");
ofstream cout("output.txt");

int main() {
	int n, t;
	cin >> n >> t;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int solved = 0;
	int penalty = 0;
	int curTime = 0;
	for (int i = 0; i < n; ++i) {
		curTime += a[i];
		if (curTime <= t) {
			penalty += curTime;
			solved++;
		} else {
			break;
		}
	}
	cout << solved << ' ' << penalty;

	return 0;
}