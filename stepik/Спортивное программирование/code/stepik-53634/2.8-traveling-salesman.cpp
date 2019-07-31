#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n;
vi permutation;
vb used;
vvi adj;

int min_len = (int)2e9;
vi min_permutation;

void calc() {
	int len = 0;
	for (int i = 0; i < n; ++i) {
		len += adj[permutation[i]][permutation[(i + 1) % n]];
	}
	if (len < min_len) {
		min_len = len;
		min_permutation = permutation;
	}
	else if (len == min_len) {
		min_permutation = min(min_permutation, permutation);
	}
}
void output(const vi& a) {
	for (int i = 0; i < n; ++i) {
		if (i) {
			cout << " ";
		}
		cout << a[i];
	}
}

void gen_permutations(int idx) {
	if (idx == n) {
		calc();
		return;
	}
	for (int num = 0; num < n; ++num) {
		if (!used[num]) {
			permutation[idx] = num;
			used[num] = true;
			gen_permutations(idx + 1);
			used[num] = false;
		}
	}
}
int main() {

	cin >> n;
	adj.resize(n, vi(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> adj[i][j];
		}
	}

	permutation.resize(n);
	used.resize(n + 1);

	gen_permutations(0);

	cout << min_len << endl;
	output(min_permutation);


	return 0;
}