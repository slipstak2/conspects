#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vd> vvd;

const double EPS = 1e-8;
bool equal(double a, double b) {
	return fabs(a - b) <= EPS;
}

double det(vvd& a) {
	double res = 1;
	int n = a[0].size();
	for (int col = 0, row = 0; row < n && col < n; ++row,++col) {
		
		int sign = 1;
		int pivot_row = -1;
		for (int i = row; i < n; ++i) {
			if (!equal(a[i][col], 0)) {
				pivot_row = i;
				break;
			}
		}
		if (pivot_row == -1) return 0;
		if (pivot_row != row) {
			sign = -1;
			for (int j = col; j < n; ++j) {
				swap(a[row][j], a[pivot_row][j]);
			}
		}

		for (int i = row + 1; i < n; ++i) {
			double mul = - a[i][col] / a[row][col];
			for (int j = col; j < n; ++j) {
				a[i][j] += mul * a[row][j];
			}
		}
		res *= sign * a[row][col];
	}

	return res;
}

int main() {
#if _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vvd a(n, vd(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	cout << ll(round(det(a)));

	return 0;
}