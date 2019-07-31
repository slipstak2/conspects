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

	int n = 3;
	int x = 0;
	for (int i = 0; i < n; i++)
		x |= (1 << i);
	cout << x;
	return 0;
}