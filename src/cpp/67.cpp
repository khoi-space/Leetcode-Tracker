#include "test.h"
#include "global.h"
using namespace std;

/**
 * Problem 67: Add Binary
 * @input: 
 * @output: 
*/
string addBinary(string a, string b) {
    string res = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) carry += a[i--] - '0';
        if (j >= 0) carry += b[j--] - '0';

        res += (carry % 2) + '0';
        carry /= 2;
    }

    reverse(res.begin(), res.end());
    return res;

}

void test67() {
    struct Case {
        string a;
        string b;
        string exp;
    };

    vector<Case> cases = {
        {"11", "1", "100"},
        {"1010", "1011", "10101"}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        string res = addBinary(cases[i].a, cases[i].b);
        assertTest(res, cases[i].exp, i);
    }
}
