#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("cont2.in");
ofstream cout("output.txt");

struct Item {
	int w, c;
	int value() const {
		return c / w;
	}
};

bool operator < (const Item &a, const Item &b) {
	return a.value() > b.value();
}

int main() {
	int n, W;
	cin >> n >> W;
	vector<Item> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].w >> a[i].c;
	}
	sort(a.begin(), a.end());

	int resCost = 0;
	for (int i = 0; i < n && W; ++i) {
		int curW = min(W, a[i].w);
		resCost += curW * a[i].value();
		W -= curW;
	}

	cout << resCost;

	return 0;
}