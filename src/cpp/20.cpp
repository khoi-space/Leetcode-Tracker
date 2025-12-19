#include "test.h"
 #include "global.h"
using namespace std;

bool isPair(char last, char cur);

/**
 * Problem 20: is Valid Parentheses
 * @input: a string s containing just the characters '(', ')', '{', '}', '[' and ']'
 * @output: determine if the input string is valid.
 */
bool isValidParentheses(string s) {
    stack<char> st;
    for (char c : s) {
        if(!st.empty()) {
            if (isPair(st.top(), c)) {
                st.pop();
                continue;
            }
        }
        // If !st.empty() or !isPair(last, cur), push cur to st
        st.push(c);
    }
    
    return st.empty();
}

bool isPair(char last, char cur) {
    return  (last == '{' && cur == '}') ||
            (last == '[' && cur == ']') ||
            (last == '(' && cur == ')');
}

void Test::test20() {
    struct Case {
        string s;
        bool exp;
    };

    vector<Case> cases = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([)]", false},
        {"{[]}", true},
        {"", true},
        {"(((((", false},
        {"(([]){})", true},
        {"([)", false},
        {"[", false},
        {"]", false}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        bool res = isValidParentheses(c.s);
        assertTest(res, c.exp, i);
    }
}