#include <fstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n;
string ans;
stack<char> s;

string open_brackets  = "([";
string close_brackets = ")]";

string brackets = "()[]";

void gen_brackets(int idx) {
	if (idx == 2 * n) {
		if (s.empty()) {
			cout << ans << endl;
		}
		return;
	}

	for (char c : brackets) {
		if (-1 != open_brackets.find(c)) { // is_open
			ans[idx] = c;
			s.push(c);
			gen_brackets(idx + 1);
			s.pop();
			ans[idx] = ' ';
		} else { // is_close
			if (!s.empty()) {
				char open_bracket = s.top();
				char close_bracket = close_brackets[open_brackets.find(open_bracket)];
				if (close_bracket == c) {
					s.pop();
					ans[idx] = close_bracket;
					gen_brackets(idx + 1);
					s.push(open_bracket);
					ans[idx] = ' ';
				}
			}
		}
	}
}
int main() {

	cin >> n;
	ans.resize(2 * n);
	gen_brackets(0);

	return 0;
}