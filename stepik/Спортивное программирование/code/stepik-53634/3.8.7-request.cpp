#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ifstream cin("request2-3.8.in");
ofstream cout("output.txt");

struct Request {
	int l, r;
};

bool operator < (const Request &a, const Request &b) {
	return a.l < b.l;
}

int main() {
	int n;
	cin >> n;
	vector<Request> lect(n);
	for (int i = 0; i < n; ++i) {
		cin >> lect[i].l >> lect[i].r;
	}

	sort(lect.begin(), lect.end());

	vector<int> audit_time_free;
	for (int i = 0; i < lect.size(); ++i) {
		int idx = -1;
		for (int j = 0; j < audit_time_free.size(); ++j) {
			if (audit_time_free[j] <= lect[i].l) {
				idx = j;
				break;
			}
		}
		if (idx == -1) {
			audit_time_free.push_back(lect[i].r);
		} else {
			audit_time_free[idx] = lect[i].r;
		}
	}

	cout << audit_time_free.size();

	return 0;
}