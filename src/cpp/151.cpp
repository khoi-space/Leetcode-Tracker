#include "test.h"
#include "global.h"
using namespace std;

//#define DEBUG
#define APR 2

/**
 * Problem 151: Reverse Words in a String
 * @input: "the sky is blue"
 * @output: "blue is sky the"
*/
string reverseWords(string s) {
    #if APR == 1
    stringstream ss(s);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    string res;
    for (int i = words.size() - 1; i >= 0; --i) {
        res += words[i];
        if (i != 0) {
            res += " ";
        }
    }
    return res;

    #elif APR == 2
    stringstream ss(s);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    int l = 0, r = words.size() - 1;
    while (l < r) {
        swap(words[l], words[r]);
        ++l;
        --r;
    }

    string res;
    for (const string& w : words) {
        if (!res.empty()) {
            res += " ";
        }
        res += w;
    }
    return res;
    #endif
}

void test151() {
    cout << "Approach:" << endl;
    #if APR == 1
    cout << "1. Add from the back of vector" << endl;
    #elif APR == 2
    cout << "2. Add from the front of vector" << endl;
    #endif

    struct Case {
        string s;
        string exp;
    };

    vector<Case> cases = {
        {"the sky is blue", "blue is sky the"},
        {"  hello world  ", "world hello"},
        {"a good   example", "example good a"}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        string res = reverseWords(c.s);
        assertTest(res, c.exp, i);
    }
}
