#include "test.h"
#include "global.h"
using namespace std;

#define DEBUG
#define APR 1

/**
 * Problem 334: Increasing Triplet Subsequence
 * @input: integer array
 * @output: if nums[i] < nums[j] < nums[k]
*/
bool increaseTriplet(vector<int> nums) {
    int first = INT_MAX;
    int second = INT_MAX;
    for (int num : nums) {
        if (num <= first) first = num;
        else if (num <= second) second = num;
        else return true;
    }
    return false;
}

void test334() {
    cout << "Approach " << APR << endl;

    struct Case {
        vector<int> nums;
        bool exp;
    };

    vector<Case> cases = {
        {{5,4,3,2,1}, false},
        {{2,1,5,0,4,6}, true},
        {{20,100,10,12,5,13}, true}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        bool res = increaseTriplet(c.nums);
        assertTest(res, c.exp, i);
    }
}
