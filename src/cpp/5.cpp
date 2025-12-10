#include "solution.h"
#include "test.h"
using namespace std;

int approach = 0;
bool checkPalindrome(string s, int i, int j); // Use in approach 1 to check if a substr of s is a palidrome
string expand(string s, int i, int j); // Use in approach 3 to expand the substring until it's not palindrome anymore

/**
 * Problem 5: Longest Palindromic Substring
 * @input: string s
 * @output: the longest palindromic substring of s
 */
string Solution::longestPalindrome(string s) {
    int appr = 1;
    if (appr == 1) {
        // Approach 1: Check All Substrings - O(n^3)
        for (size_t length = s.size(); length > 0; --length) {
            for (size_t start = 0; start <= s.size() - length; ++start) {
                if (checkPalindrome(s, start, start + length)) {
                    return s.substr(start, length);
                }
            }
        }
        return "";
    } else if (appr == 2) {
        // Approach 2: Dynamic Programming - O(n^2)
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        array<int, 2> ans = {0, 0};

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans = {i, i + 1};
            }
        }

        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        int i = ans[0];
        int j = ans[1];

        return s.substr(i, j - i + 1);
    } else if (appr == 3) {
        // Approach 3: Expand From Centers - O(n^2)
        string ans = "";

        for (size_t i = 0; i < s.size(); ++i) {
            string odd = expand(s, i, i); // Check an odd-size palindrome expaned from i
            if (odd.size() > ans.size()) {
                ans = odd;
            }

            string even = expand(s, i, i + 1); // Check an even-size palindrome expanded from i and i+1
            if (even.size() > ans.size()) {
                ans = even;
            }
        }

        return ans;
    } else if (appr == 4) {
        // Approach 4: Manacher's Algorithm - O(n)!!!!
        // Transform "abc" -> "#a#b#c#"
        string s_prime = "#";
        for (char c : s) {
            s_prime += c;
            s_prime += "#";
        }

        int n = s_prime.length();
        vector<int> palindrome_radii(n, 0);
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n - 1; i++) {
            int mirror = 2 * center - i;

            if (i < radius) {
                palindrome_radii[i] = min(radius - i, palindrome_radii[mirror]);
            }

            while (i + 1 + palindrome_radii[i] < n &&
                   i - 1 - palindrome_radii[i] >= 0 &&
                   s_prime[i + 1 + palindrome_radii[i]] ==
                       s_prime[i - 1 - palindrome_radii[i]]) {
                palindrome_radii[i]++;
            }

            if (i + palindrome_radii[i] > radius) {
                center = i;
                radius = i + palindrome_radii[i];
            }
        }

        int max_length = 0;
        int center_index = 0;
        for (int i = 0; i < n; i++) {
            if (palindrome_radii[i] > max_length) {
                max_length = palindrome_radii[i];
                center_index = i;
            }
        }

        int start_index = (center_index - max_length) / 2;
        string longest_palindrome = s.substr(start_index, max_length);

        return longest_palindrome;
    }
    return "";
}

bool checkPalindrome(string s, int i, int j) {
    int l = i;
    int r = j - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        ++l;
        --r;
    }
    return true;
}

string expand(string s, int i, int j) {
    int l = i;
    int r = j;

    while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
        --l;
        ++r;
    }

    return s.substr(l + 1, r - l - 1);
}

void Test::test5() {
    struct Case {
        string s;
        vector<string> exp; // Accept multiple correct answers
    };

    vector<Case> cases = {
        {"babad", {"bab", "aba"}},
        {"cbbd", {"bb"}},
        {"a", {"a"}},
        {"ac", {"a", "c"}},
        {"racecar", {"racecar"}},
        {"", {""}},
        {"abb", {"bb"}},
    };

    extern Solution sol;
    bool allPassed = true;

    cout << "Approach:\n";
    cout << "1. Check all substrings\n";
    cout << "2. Dynamic programming\n";
    cout << "3. Expand from centers\n";
    cout << "4. Manacher's Algorithm\n";
    cout << ">>> "; cin >> approach;
    for (const auto& c : cases) {
        string res = sol.longestPalindrome(c.s);
        bool match = false;
        for (const auto& e : c.exp) {
            if (res == e) {
                match = true;
                break;
            }
        }
        if (!match) {
            allPassed = false;
            printf("\033[31mFAILED\033[0m: s=%s, res=%s, exp=", c.s.c_str(), res.c_str());
            for (const auto& e : c.exp) printf("%s ", e.c_str());
            printf("\n");
        }
    }
    if (allPassed) {
        cout << "\033[32mPASSED\033[0m\n";
    }
}