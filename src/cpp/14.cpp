#include "test.h"
 #include "global.h"
#include <sstream>
using namespace std;

/**
 * Problem 14: Longest Common Prefix
 * @input: an array of strings
 * @output: the longest common prefix string amongst them
 */
string longestCommonPrefix(vector<string>& strs) {
    stringstream result;
    if (strs.empty()) return "";
    for (size_t i = 0; i < strs[0].size(); ++i) {
        char c = strs[0][i];
        for (size_t j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != c)
                return result.str();
        }
        result << c;
    }
    return result.str();
}

void Test::test14() {
    struct Case {
        vector<string> strs;
        string exp;
    };

    vector<Case> cases = {
        {{"flower","flow","flight"}, "fl"},
        {{"dog","racecar","car"}, ""},
        {{"interview","internet","internal"}, "inter"},
        {{"a"}, "a"},
        {{"",""}, ""},
        {{"ab", "a"}, "a"},
        {{"cir","car"}, "c"},
        {{}, ""}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        string res = longestCommonPrefix(const_cast<vector<string>&>(c.strs));
        assertTest(res, c.exp, i);
    }
}