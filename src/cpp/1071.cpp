#include "test.h"
#include "global.h"
using namespace std;

int approach = 0;

string joinWords(string str, int k) {
    string ret = "";
    for (int i = 0; i < k; ++i) {
        ret += str;
    }
    return ret;
}

bool valid(string str1, string str2, int k) {
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 % k > 0 || len2 % k > 0) {
        return false;
    } else {
        string base = str1.substr(0, k);
        int n1 = len1 / k, n2 = len2 / k;
        return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
    }
}

/**
 * Problem 1071: Greatest Common Divisor of Strings
 * @explain: "ABABAB" & "ABAB" -> "AB" is a divisor
*/
string gcdOfStrings(string str1, string str2) {
    if (approach == 1) {
        // Approach 1: Brute force
        int len1 = str1.length(), len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; --i) {
            if (valid(str1, str2, i)) {
                return str1.substr(0, i);
            }
        }
        return "";
    } else if (approach == 2) {
        // Approach 2: Greatest Common Divisor
        if (str1 + str2 != str2 + str1) return "";

        int gcd_len = __gcd(str1.size(), str2.size());
        return str1.substr(0, gcd_len);
    }
    return "";
}

void test1071() {
    cout << "Approach:\n";
    cout << "1. Brute force\n";
    cout << "2. Greatest Common Divisor\n";
    cout << ">>> "; cin >> approach;

    struct Case {
        string str1;
        string str2;
        string exp;
    };

    vector<Case> cases = {
        {"ABCABC", "ABC", "ABC"},
        {"ABABAB", "ABAB", "AB"},
        {"LEET", "CODE", ""},
        {"AAAAAB", "AAA", ""}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        string res = gcdOfStrings(cases[i].str1, cases[i].str2);
        assertTest(res, cases[i].exp, i);
    }
}
