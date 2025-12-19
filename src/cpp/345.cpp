#include "test.h"
#include "global.h"
using namespace std;

// #define DEBUG
#define APR 2

/**
 * Problem 345: Reverse Vowels of a String
 * @explain: vowels are 'a', 'e', 'i', 'o' and 'u' in both lower and upper cases
*/
string reverseVowels(string s) {
    #if APR == 1
    unordered_set<char> vowels_set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int l = 0;
    int r = s.length() - 1;
    while (l < r) {
        while (vowels_set.find(s[l]) == vowels_set.end() && l < r) {
            ++l;
        }

        while (vowels_set.find(s[r]) == vowels_set.end() && l < r) {
            --r;
        }

        // swap s[l] and s[r]
        swap(s.at(l), s.at(r));
        #ifdef DEBUG
        cout << s << endl;
        #endif

        // Move the pointer to the next
        ++l;
        --r;
    }
    return s;
    
    #elif APR == 2
    unordered_set<char> vowels_set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int l = 0;
    int r = s.length() - 1;
    while (l < r) {
        if (vowels_set.find(s[l]) == vowels_set.end()) {
            ++l;
        } else if (vowels_set.find(s[r]) == vowels_set.end()) {
            --r;
        } else {
            // swap s[l] and s[r]
            swap(s.at(l), s.at(r));
            #ifdef DEBUG
            cout << res << endl;
            #endif
    
            // Move the pointer to the next
            ++l;
            --r;
        }
    }
    return s;
    #endif
}

void test345() {
    cout << "Approach:" << endl;
    #if APR == 1
    cout << "1. 2 whiles" << endl;
    #elif APR == 2
    cout << "2. 1 while (optimal)" << endl;
    #endif

    struct Case {
        string s;
        string exp;
    };

    vector<Case> cases = {
        {"IceCreAm", "AceCreIm"},
        {"leetcode", "leotcede"}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        string res = reverseVowels(c.s);
        assertTest(res, c.exp, i);
    }
}
