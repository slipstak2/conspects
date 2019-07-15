#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("request2.in");
ofstream cout("output.txt");

struct Request {
	int l, r;
};

bool operator < (const Request &r1, const Request &r2) {
	return r1.r < r2.r;
}

int main() {

	int n;
	cin >> n;
	vector<Request> requests(n);
	for (int i = 0; i < n; ++i) {
		cin >> requests[i].l >> requests[i].r;
	}
	sort(requests.begin(), requests.end());
	
	int cnt = 0;
	int last_r = -1;
	for (const auto &req : requests) {
		if (last_r <= req.l) {
			last_r = req.r;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}