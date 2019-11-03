#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vd> vvd;

enum SLAU_RESULT {
	NO		= 0,
	YES	= 1,
	INF	= (int)1e9
};

const double EPS = 1e-8;
bool double_equal(const double& a, const double& b) {
	return fabs(a - b) <= EPS;
}

SLAU_RESULT gauss(vvd& a, vd& ans) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;
	vi where(m, -1);
	for (int row = 0, col = 0; row < n && col < m; ++col) {
		int pivot_row = row;
		for (int i = row; i < n; ++i) {
			if (abs(a[i][col]) > abs(a[pivot_row][col])) {
				pivot_row = i;
			}
		}
		if (double_equal(a[pivot_row][col], 0)) {
			continue;
		}
		for (int j = col; j <= m; ++j) {
			swap(a[pivot_row][j], a[row][j]);
		}

		where[col] = row;

		for (int i = 0; i < n; ++i) {
			if (i != row) {
				double mul = a[i][col] / a[row][col];
				for (int j = col; j <= m; ++j) {
					a[i][j] -= mul * a[row][j];
				}
			}
		}
		++row;
	}
	ans.assign(m, 0);
	for (int j = 0; j < m; ++j) {
		if (where[j] != -1) {
			ans[j] = a[where[j]][m] / a[where[j]][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		double sum = 0;
		for (int j = 0; j < m; ++j) {
			sum += ans[j] * a[i][j];
		}
		if (!double_equal(sum, a[i][m])) {
			return SLAU_RESULT::NO;
		}
	}

	for (int j = 0; j < m; ++j) {
		if (where[j] == -1) {
			return SLAU_RESULT::INF;
		}
	}
	return SLAU_RESULT::YES;
}


int main() {
#if _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vvd a(n, vd(m + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	vd ans(m);
	SLAU_RESULT res = gauss(a, ans);
	
	if (res == SLAU_RESULT::INF) cout << "INF";
	if (res == SLAU_RESULT::NO)  cout << "NO";
	if (res == SLAU_RESULT::YES) {
		cout << "YES" << endl;
		for (int i = 0; i < m; ++i) {
			cout << ans[i] << ' ';
		}
	}
	return 0;
}