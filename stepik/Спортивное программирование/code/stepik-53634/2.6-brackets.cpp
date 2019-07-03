#include <fstream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n;
string ans;

void gen_brackets(int idx, int balance) {
	if (idx == 2 * n) {
		if (balance == 0) {
			cout << ans << endl;
		}
		return;
	}
	ans[idx] = '(';
	gen_brackets(idx + 1, balance + 1);

	if (balance > 0) {
		ans[idx] = ')';
		gen_brackets(idx + 1, balance - 1);
	}
}
int main() {

	cin >> n;
	ans.resize(2 * n);
	gen_brackets(0, 0);

	return 0;
}