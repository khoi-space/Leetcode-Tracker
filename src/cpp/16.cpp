#include "test.h"
 #include "global.h"
using namespace std;

#define DEBUG
#define APR 1

/**
 * Problem 16: 3Sum Closest
 * @input: an integer array and an integer target
 * @output: the sum of 3 int that closest to the target
 */
int threeSumClosest(vector<int>& nums, int target) {
    int ans = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    ans = nums[0] + nums[1] + nums[2]; // starting sum

    for (int i = 0; i < n-2; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // Did calculate this one before

        int j = i+1;
        int k = n-1;

        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];
            
            if (abs(total - target) < abs(ans - target)) {
                ans = total;
            }

            if (total < target) {
                ++j;
            } else if (total > target) {
                --k;
            } else {
                return ans;
            }
        }
    }
    return ans;
}

void test16() {
    struct Case {
        vector<int> nums;
        int target;
        int exp;
    };

    vector<Case> cases = {
        {{-1,2,1,-4}, 1, 2},
        {{0,0,0}, 1, 0}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        int res = threeSumClosest(cases[i].nums, cases[i].target);
        assertTest(res, cases[i].exp, i);
    }
}