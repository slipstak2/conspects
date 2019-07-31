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

ifstream cin("ones.in");
ofstream cout("output.txt");

int bits(int n) {
	int cnt = 0; 
	while (n) {
		n &= n -1;
		cnt ++;
	}
	return cnt;
}
int main() {
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (i == 0) cout << bits(a);
		else cout << ' ' << bits(a);
	}

	return 0;
}