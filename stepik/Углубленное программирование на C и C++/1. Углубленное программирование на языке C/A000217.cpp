#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

bool correct_input(ull &z) {
    const int MAX_SIZE = 1000;
    char* buffer = new char(MAX_SIZE);
    scanf("%s", buffer);
    z = 0;
    sscanf(buffer, "%llu", &z);
    if (buffer[0] == '+') {
        buffer++;
    }

    char check_buffer[MAX_SIZE];
    sprintf(check_buffer, "%llu", z);
    if (strcmp(check_buffer, buffer) != 0) {
        return false;
    }
    return 0 < z && z <= 9223372036854775807LL;
}

int main() {
    ull z;
    if (!correct_input(z)) {
        printf("0");
        return 0;
    }

    ull num = 1;
    ull cur = 1;
    ull s = 0;
    while (s <= z) {
        s += cur;
        if (s == z) {
            printf("%d", num);
            return 0;
        }
        cur++;
        num++;
    }
    printf("0");

    return 0;
}