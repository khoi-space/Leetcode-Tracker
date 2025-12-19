#include "test.h"
#include "global.h"
#include <iostream>
using namespace std;

#define DEBUG
#define APR 1

/**
 * Problem 6: Zigzag Conversion
 * @input: The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
        P   A   H   N
        A P L S I I G
        Y   I   R
 * @output: string that read line by line of the input string (such as "PAHNAPLSIIGYIR")
 */
string convertZigzag(string s, int numRows) {
    #if APR == 1
    // Row-wise simulation
    if (numRows == 1 || (int)s.size() <= numRows) return s;
    vector<string> rows(numRows);
    int row = 0, step = 1;
    for (char c : s) {
        rows[row] += c;
        if (row == 0) step = +1; // Move forward
        else if (row == numRows - 1) step = -1; // Move backward
        row += step;
    }

    string result;
    for (const string& r : rows) result += r;
    return result;
    #elif APR == 2
    // Row-by-row Traversal
    if (numRows == 1 || (int)s.size() <= numRows) return s;
    string result;
    int n = s.size();
    int cycleLen = 2 * numRows - 2;

    for (int row = 0; row < numRows; ++row) {
        for (int i = row; i < n; i += cycleLen) {
            result += s[i];
            // If not first row or last row, make a gap
            int secondIdx = i + cycleLen - 2 * row;
            if (row != 0 && row != numRows - 1 && secondIdx < n) {
                result += s[secondIdx];
            }
        }
    }
    return result;
    #endif
}

void test6() {
    cout << "Approach " << APR << endl;

    struct Case {
        string s;
        int numRows;
        string exp;
    };

    vector<Case> cases = {
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
        {"A", 1, "A"},
        {"AB", 1, "AB"},
        {"ABC", 2, "ACB"},
        {"", 3, ""},
        {"HELLO", 2, "HLOEL"},
    };

    int i = 0;
    for (const auto& c : cases) {
        ++i;
        string res = convertZigzag(c.s, c.numRows);
        assertTest(res, c.exp, i);
    }
}