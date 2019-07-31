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

ifstream cin("input.txt");
ofstream cout("output.txt");

int main() {

	int n;
	cin >> n;
	for (int mask = 0; mask < (1 << n); ++mask) {
		bool isFirst = true;
		cout << '{';
		for (int bit = n - 1; bit >= 0; --bit) {
			if ((mask & (1 << bit)) == 0) {
				cout << (!isFirst ? "," : "") << (n - bit);
				isFirst &= false;
			}
		}
		cout << '}' << endl;
	}

	return 0;
}