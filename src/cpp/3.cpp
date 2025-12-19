
#include "test.h"
#include "global.h"
using namespace std;

#define DEBUG

/**
 * Prolem 3: Longest Substring Without Repeating Characters
 * @input: a string s
 * @output: the length of the longest substring without duplicate characters
 */
int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    
    unordered_set<char> seen;
    int left = 0, right = 0;
    int maxLength = 0;
    
    while (right < (int)s.size()) {
        // If character at right is not in current window
        if (seen.find(s[right]) == seen.end()) {
            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        } else {
            // Remove characters from left until duplicate is removed
            seen.erase(s[left]);
            left++;
        }
    }
    
    return maxLength;
}

void test3() {
    struct Case {
        string s;
        int exp;
    };

    vector<Case> cases = {
        {"pwwkew", 3},
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"", 0},
        {"au", 2},
        {"dvdf", 3},
        {"abba", 2},
        {"tmmzuxt", 5},
        {"aab", 2},
        {"abcdef", 6}
    };

    int i = 0;
    for (const auto& c : cases) {
        ++i;
        int res = lengthOfLongestSubstring(c.s);
        assertTest(res, c.exp, i);
    }
}