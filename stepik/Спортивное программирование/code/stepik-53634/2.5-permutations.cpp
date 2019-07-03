#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n;
vi permutation;
vb used;

void output() {
	for (int i = 0; i < n; ++i) {
		if (i) {
			cout << " ";
		}
		cout << permutation[i];
	}
	cout << endl;
}

void gen_permutations(int idx) {
	if (idx == n) {
		output();
		return;
	}
	for (int num = 1; num <= n; ++num) {
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
	permutation.resize(n);
	used.resize(n + 1);

	gen_permutations(0);


	return 0;
}