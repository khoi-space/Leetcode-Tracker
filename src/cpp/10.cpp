#include "test.h"
#include "global.h"
using namespace std;

#define DEBUG
#define APR 1

/**
 * Problem 10: Regular Expression Matching
 * @input: string s and pattern p
 * * Note: In pattern p:
 * + '.': matches any single char
 * + '*': matches zero or more of the preceding element
 * @output: boolean expression
 */
bool isMatch(string s, string p) {
    #if APR == 1
    // Recursion
    if (p.empty()) return s.empty();

    bool first_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
    if (p.size() >= 2 && p[1] == '*') {
        return  isMatch(s, p.substr(2)) ||
                (first_match && isMatch(s.substr(1), p));
    } else {
        return first_match && isMatch(s.substr(1), p.substr(1));
    }
    return false;

    #elif APR == 2
    // Dynamic Programming
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[m][n] = true;
    for (int i = m; i >= 0; --i) {
        #ifdef DEBUG
        cout << "i=" << i << endl;
        #endif

        for (int j = n-1; j >= 0; --j) {
            bool first_match = (i < m && (s[i] == p[j] || p[j] == '.'));
            if (j+1 < n && p[j+1] == '*') {
                dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
            } else {
                dp[i][j] = first_match && dp[i+1][j+1];
            }

            #ifdef DEBUG
            cout << " dp[i][j]=" << dp[i] << endl;
            #endif
        }
    }
    return dp[0][0];
    #endif
}

void test10() {
    cout << "Approach " << APR << endl;

    struct Case {
        string s;
        string p;
        bool exp;
    };

    vector<Case> cases = {
        {"aa", "a", false},
        {"aa", "a*", true},
        {"ab", ".*", true}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        bool res = isMatch(cases[i].s, cases[i].p);
        assertTest(res, cases[i].exp, i);
    }
}