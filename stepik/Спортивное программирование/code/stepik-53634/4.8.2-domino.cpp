#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("input.txt");
ofstream cout("output.txt");

int main() {
	int n, m;
	cin >> n >> m;
	vi f(n + 1);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = (f[i - 1] + f[i - 2]) % m;
	}
	cout << f[n];

	return 0;
}