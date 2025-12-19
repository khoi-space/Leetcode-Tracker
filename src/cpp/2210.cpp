#include "test.h"
 #include "global.h"
using namespace std;

#define DEBUG
#define APR 2

/**
 * Problem 2210: Count Hills and Valleys in an Array
 * @input: a 0-indexed integer array
 * @output: num of hills and valleys
 */
int countHillValley(vector<int>& nums) {
    #if APR == 1
    // O(n^2)
    int cnt = 0;
    int n = nums.size();
    for (int i = 1; i < n - 1; ++i) {
        if (nums[i] == nums[i - 1]) continue;

        int left_flag = 0; // left_flag = 1 if peak, left_flag = -1 if valley
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                left_flag = -1;
                break;
            } else if (nums[j] > nums[i]) {
                left_flag = 1;
                break;
            }
        }

        int right_flag = 0;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[i]) {
                right_flag = -1; 
                break;
            } else if (nums[j] > nums[i]) {
                right_flag = 1;
                break;
            }
        }

        if (left_flag == right_flag && left_flag*right_flag != 0) {
            ++cnt;
        }
        
    }
    return cnt;
    #elif APR == 2
    // O(n)
    int cnt = 0;
    int n = nums.size();
    int is_taller = 0; // 0 is neither, 1 indicates taller, -1 indicates shorter

    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1]) continue;

        if (nums[i - 1] < nums[i]) {
            cnt += (is_taller == -1) ? 1 : 0; // found a valley
            is_taller = 1;
        } else if (nums[i - 1] > nums[i]) {
            cnt += (is_taller == 1) ? 1 : 0; // found a hill
            is_taller = -1;
        }
    }
    return cnt;
    #endif
}

void test2210() {
    cout << "Approach " << APR << endl;

    struct Case {
        vector<int> nums;
        int exp;
    };

    vector<Case> cases = {
        {{2,4,1,1,6,5}, 3},
        {{6,6,5,5,4,1}, 0},
        {{5,4,4,3,3,3,10,0,-1,5}, 3}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        int res = countHillValley(cases[i].nums);
        assertTest(res, cases[i].exp, i);
    }
}