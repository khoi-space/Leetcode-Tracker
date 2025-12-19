
#include "test.h"
#include "global.h"
#include <iostream>
using namespace std;

#define DEBUG
#define APR 1

/**
 * Problem 1: Two Sum
 * @input: given an array of integers nums and an integer target, 
 * @output: indices of the two numbers such that they add up to target.
 */
vector<int> twoSum(vector<int>& nums, int target) {
    #if APR == 1 
    // Using hash map - O(n)
    unordered_map<int, int> map;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int need = target - nums[i];

        if (map.find(need) != map.end()) {
            return {map[need], i};
        }

        map[nums[i]] = i; // key=nums[i], value=i
    }
    return {};

    #elif APR == 2
    // Brute-force - O(n^2)
    for (int i = 0 ; i < (int)nums.size() - 1; ++i) {
        for (int j = i + 1; j < (int)nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
    #endif
}

void test1() {
    cout << "Approach " << APR << endl;

    struct Case {
        vector<int> nums;
        int target;
        vector<int> exp;
    };

    vector<Case> cases = {
        {{2,7,8,6,4,3}, 9, {0,1}},
        {{3,2,4}, 6, {1,2}},
        {{3,3}, 6, {0,1}},
        {{1,2,3}, 7, {}}, // no solution
    };

    int i = 0;
    for (auto& c : cases) {
        ++i;
        vector<int> res = twoSum(c.nums, c.target);
        assertTest(res, c.exp, i);
    }
}