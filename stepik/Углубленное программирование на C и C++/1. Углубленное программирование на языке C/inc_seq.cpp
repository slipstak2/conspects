#include <iostream>
#include <vector>
#include <string>
#include <cstring>

//#define _LOCAL_

using namespace std;
const int MAX_LEN = 100;
char buf[MAX_LEN];

enum READ_RESULT {
    NO_DATA = -1,
    OK = 0,
    BAD_DATA= 1
};

READ_RESULT readInt(int& res) {
    try {
        int read_result = scanf("%s", buf);
        if (read_result != EOF) { // branch prediction
            size_t pos = 0;
            res = stoi(buf, &pos);
            return pos == strlen(buf) ? READ_RESULT::OK : READ_RESULT::BAD_DATA;
        } else {
            return READ_RESULT::NO_DATA;
        }
    } catch (std::exception &e) {
        return READ_RESULT::BAD_DATA;
    }
}

READ_RESULT readDouble(double &res) {
    try {
        int read_result = scanf("%s", buf);
        if (read_result != EOF) { // branch prediction
            size_t pos = 0;
            res = stod(buf, &pos);
            return pos == strlen(buf) ? READ_RESULT::OK : READ_RESULT::BAD_DATA;
        } else {
            return READ_RESULT::NO_DATA;
        }
    } catch (std::exception &e) {
        return READ_RESULT::BAD_DATA;
    }
}

void solve(const vector<double> &a) {
    int best_beg = -1;
    int max_len = -1;

    for (int i = 0; i < a.size(); ) {
        int beg = i++;
        while (i < a.size()) {
            if (a[i - 1] <= a[i]) { // bad impl!!!
                ++i;
            } else {
                break;
            }
        }
        int len = i - beg;
        if (len > max_len) {
            best_beg = beg;
            max_len = len;
        }
    }
    if (max_len == 1) {
        printf("0");
    } else {
        printf("%d %d", max_len, best_beg + 1);
    }
}
int main() {

#if defined(_LOCAL_)
    freopen("input.txt", "r", stdin);
#endif

    bool isError = false;
    int n;
    vector<double> a;
    READ_RESULT res = readInt(n);
    if (res == READ_RESULT::OK) {
        for (int i = 0; i < n; ++i) {
            double cur;
            res = readDouble(cur);
            if (res == READ_RESULT::OK) { // branch prediction
                a.push_back(cur);
            } else {
                isError = true;
                break;
            }
        }
        if (a.size() <= 1) {
            isError = true;
        }
    } else {
        isError = true;
    }

    if (isError) {
        printf("[error]");
    } else {
        solve(a);
    }
    return 0;

}