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
	vi f(11);
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	f[3] = 2;
	for (int i = 4; i <= 10; ++i) {
		f[i] = f[i-1] + f[i-3];
	}
	cout << f[10];
	return 0;
}