#include "test.h"
 #include "global.h"
using namespace std;

#define DEBUG
#define APR 1

/**
 * Problem 3487: Maximum Unique Subarray Sum After Deletion
 * @input: integer array
 * @output: maximum sum of a subarray
 * @rule:
 * - All elements in the subarray are unique.
 * - The sum of the elements in the subarray is max.
 */
int maxSum(vector<int>& nums) {
    unordered_set<int> positiveNumSet;
    int max_sum = 0;
    for (int num : nums) {
        if (num > 0) {
            positiveNumSet.insert(num);
        }
    }

    if (positiveNumSet.empty()) {
        return *max_element(nums.begin(), nums.end());
    }
    
    for (int positive_num : positiveNumSet) {
        max_sum += positive_num;
    }
    return max_sum;
}

void test3487() {
    struct Case {
        vector<int> nums;
        int exp;
    };

    vector<Case> cases = {
        {{1,2,3,4,5}, 15}, //0
        {{1,1,0,1,1}, 1}, //1
        {{1,2,-1,-2,1,0,-1}, 3} //2
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        int res = maxSum(cases[i].nums);
        assertTest(res, cases[i].exp, i);
    }
}  