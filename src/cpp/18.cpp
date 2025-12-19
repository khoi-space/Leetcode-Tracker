#include "test.h"
 #include "global.h"
using namespace std;

/**
 * Problem 18: 4Sum
 * @input: array nums of n integers
 * @output: an array of all unique quadruplets that have sum equal to target
 */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n-3; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue;

        for (int j = i + 1; j < n-2; ++j) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;

            int left = j+1;
            int right = n-1;

            while (left < right) {
                long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (total > target) {
                    --right;
                } else if (total < target) {
                    ++left;
                } else { // total == target
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    ++left;
                    --right;
                    
                    while (left < right && nums[left] == nums[left-1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right+1]) {
                        --right;
                    }
                }
            }
        }
    }
    return ans;
}

void test18() {
    struct Case {
        vector<int> nums;
        int target;
        vector<vector<int>> exp;
    };

    vector<Case> cases = {
        // 0
        {{1,0,-1,0,-2,2}, 0, {{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}}},
        // 1
        {{2,2,2,2,2}, 8, {{2,2,2,2}}},
        // 2
        {{1000000000,1000000000,1000000000,1000000000}, 0, {}}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        vector<vector<int>> res = fourSum(c.nums, c.target);
        assertTest(res, c.exp, i);
    }
}