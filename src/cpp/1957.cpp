#include "solution.h"
#include "test.h"
using namespace std;

int approach = 0;

/**
 * Problem 1957: Delete Characters to Make Fancy String
 * @detail: a fancy string has no 3 consecutive equal characters
 */
string Solution::makeFancyString(string s) {
    if (approach == 1) {
        // Approach 1: Insert to new string
        if (s.size() < 3) return s;

        string new_fancy_str = "";
        int freq = 1;
        char prev = s[0];
        int n = s.size();

        new_fancy_str.push_back(s[0]);
        for (int i = 1; i < n; ++i) {
            if (s[i] == prev) {
                ++freq;
            } else {
                prev = s[i];
                freq = 1;
            }

            if (freq < 3) new_fancy_str.push_back(s[i]);
        }
        return new_fancy_str;
    } else if (approach == 2) {
        // Approach 2: In-place 2 pointers
        if (s.size() < 3) return s;

        int j = 2;
        for (int i = 2; i < (int)s.size(); ++i) {
            if (s[i] != s[j - 1] ||
                s[i] != s[j - 2]) 
            {
                s[j++] = s[i];
            }
        }

        s.resize(j);
        return s;
    }
    return "";
}

void Test::test1957() {
    cout << "Approach:\n";
    cout << "1. Insert to new string\n";
    cout << "2. In-place 2 pointers\n";
    cout << ">>> "; cin >> approach;

    struct Case {
        string s;
        string exp;
    };

    vector<Case> cases = {
        {"leeetcode", "leetcode"},
        {"aaabaaaa", "aabaa"}
    };

    extern Solution sol;

    for (int i = 0; i < (int)cases.size(); ++i) {
        string res = sol.makeFancyString(cases[i].s);
        Test::assertTest(res, cases[i].exp, i);
    }
}