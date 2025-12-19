#include "test.h"
#include "global.h"
using namespace std;

int myAtoi(string s) {
    if (s.empty()) return 0;

    int i = 0;
    int n = s.size();

    // Skip leading whitespace
    while (i < n && s[i] == ' ') {
        ++i;
    }

    // Check if we've reached the end
    if (i == n) {
        return 0;
    }

    // Check sign
    int sign = 1;
    if (s[i] == '+') {
        sign = 1;
        ++i;
    } else if (s[i] == '-') {
        sign = -1;
        ++i;
    }

    // Read digits and convert to int
    long res = 0;
    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';
        res = res * 10 + digit;
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))) {
             return sign == 1 ? INT_MAX : INT_MIN; 
        }
        ++i;
    }
    return (int)(sign * res);
}

void test8() {

    struct Case {
        string s;
        int exp;
    };

    vector<Case> cases = {
        {"432", 432},
        {"42", 42},
        {" -042", -42},
        {"1337c0d3", 1337},
        {"0-1", 0},
        {"don't convert this", 0},
        {"-91283472332", INT_MIN},
        {"-2147483648", INT_MIN},
        {"91283472332", INT_MAX},
        {"2147483647", INT_MAX}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = myAtoi(c.s);
        assertTest(res, c.exp, i);
    }
}