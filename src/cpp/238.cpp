#include "test.h"
#include "global.h"
using namespace std;

//#define DEBUG
#define APR 4

/**
 * Problem 238: Product of Array Except Self
 * @input: integer array
 * @output: answer such that answer[i] is equal to the product of all other num except itself
 * @rule: must in O(n) and not use division
*/
vector<int> productExceptSelf(vector<int>& nums) {
    #if APR == 1 // O(n)
    // Dividing the product of array with the number
    int n = nums.size();
    vector<int> ans(n, 1);
    int pro = 1;
    for (int num : nums) {
        pro *= num;
    }

    for (int i = 0; i < n; ++i) {
        ans[i] = pro / nums[i];
    }
    return ans;
    #elif APR == 2 // O(n)
    // Finding prefix product and suffix product
    int n = nums.size();
    int prefix[] = new int[n];
    int suffix[] = new int[n];

    prefix[0] = 1;
    suffix[n - 1] = 1;

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    vector<int> ans(n, 1);
    for (int i = 0; i < n; ++i) {
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
    #elif APR == 3 // O(n^2)
    // Brute-force
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; ++i) {
        int pro = 1;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            pro *= nums[j];
        }
        ans[i] = pro;
    }

    return ans;
    #elif APR == 4 // O(n)
    // Directly store the product of prefix and suffix into the final answer array
    int n = nums.size();
    vector<int> ans(n, 1);
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        ans[i] *= cur;
        cur *= nums[i];
    }
    cur = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] *= cur;
        cur *= nums[i];
    }

    return ans;
    #endif
}

void test238() {
    cout << "Approach " << APR << endl;
    
    struct Case {
        vector<int> nums;
        vector<int> exp;
    };
    
    vector<Case> cases = {
        {{1,2,3,4}, {24,12,8,6}},
        {{-1,1,0,-3,3}, {0,0,9,0,0}}
    };
    
    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        vector<int> res = productExceptSelf(c.nums);
        assertTest(res, c.exp, i);
    }
}
