#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("schedule2.in");
ofstream cout("output.txt");

struct Order {
	int day;
	int cost;
};

bool operator < (const Order &a, const Order &b) {
	return a.cost > b.cost;
}
int main() {

	int n;
	cin >> n;
	vector<Order> orders(n);
	int max_day = -1;
	for (int i = 0; i < n; ++i) {
		cin >> orders[i].day >> orders[i].cost;
		max_day = max(max_day, orders[i].day);
	}

	sort(orders.begin(), orders.end());

	vi used(max_day + 1, 0);
	for (auto const &order : orders) {
		int idx = order.day;
		while (idx > 0 && used[idx] != 0) --idx;
		if (idx > 0) {
			used[idx] = order.cost;
		}
	}

	cout << accumulate(used.begin(), used.end(), 0LL);

	return 0;
}