#include "test.h"
#include "global.h"
using namespace std;

int approach = 0;

/**
 * Problem 27: Remove Element
 * @input: array of nums and val need to be deleted in nums
 * @output: size of nums left (don't change actual size) and nums after deleted val
*/
int removeElement(vector<int>& nums, int val) {
    if (approach == 1) {
        // Approach 1: New vector
        int n = nums.size();
        vector<int> new_nums;
        int remain_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == val) continue;
            new_nums.push_back(nums[i]);
            ++remain_cnt;
        }
        nums = new_nums;
        return remain_cnt;
    } else if (approach == 2) {
        // Approach 2: In-place
        int k = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }

        nums.resize(k);
        return k;
    }
    return 0;
}

void test27() {
    cout << "Approach:\n";
    cout << "1. Create new vector\n";
    cout << "2. In-place\n";
    cout << ">>> "; cin >> approach;

    struct Case {
        vector<int> nums;
        int val;
        int exp;
    };

    vector<Case> cases = {
        {{3,2,2,3}, 3, 2},
        {{0,1,2,2,3,0,4,2}, 2, 5}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        cout << "Initial nums: " << cases[i].nums << endl;

        int res = removeElement(cases[i].nums, cases[i].val);

        cout << "Nums after remove val " << cases[i].val << ": " << cases[i].nums << endl;
        assertTest(res, cases[i].exp, i);
    }
}
