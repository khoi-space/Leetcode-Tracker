
#include "test.h"
#include "global.h"
using namespace std;

#define DEBUG
#define APR 1

/**
 * Problem 13: Roman to Integer
 * @input: a roman numeral string (I=1, V=5, X=10, L=50, C=100, D=500, M=1000)
 * @output: int of roman numeral string
 */
int romanToInt(string s) {
    #if APR == 1
    // Right-left & int array
    static int val[256] = {};

    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;

    int prev_val = 0;
    int result = 0;

    for (int i = s.length() - 1; i >= 0; --i) { // Move from right to left (no more jumping)
        int cur_val = val[(unsigned char)s[i]];
        result += (cur_val < prev_val) ? -cur_val : cur_val;
        prev_val = cur_val;
    }

    return result;
    #elif APR == 2
    // Left-right & hash map
    unordered_map<char, int> val;
    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;
    int result = 0;

    for (size_t i = 0; i < s.length(); ++i) { // Move from left to right
        if (i+1 < s.length() && val[s[i]] < val[s[i+1]]) {
            result += val[s[i + 1]] - val[s[i]];
            ++i;
        } else {
            result += val[s[i]];
        }
    }

    return result;
    #endif

void Test::test13() {
    cout << "Approach " << APR << endl;

    struct Case {
        string s;
        int exp;
    };

    vector<Case> cases = {
        {"I", 1},
        {"III", 3},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000},
        {"LVIII", 58},     // L(50) + V(5) + III(3)
        {"MCMXCIV", 1994}, // M(1000) + CM(900) + XC(90) + IV(4)
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = romanToInt(c.s);
        assertTest(res, c.exp, i);
    }
}