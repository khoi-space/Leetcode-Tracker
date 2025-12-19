#include "test.h"
 #include "global.h"
using namespace std;

#define DEBUG
#define APR 1

/**
 * Problem 162: Find Peak Element
 * @input: a 0-indexed array
 * @output: a peak element
 */
int findPeakElement(vector<int>& nums) {
    #if APR == 1
    // O(n)
    if (nums.size() == 0 || nums.size() == 1) return 0;
    int n = nums.size();
    bool wait_for_lower = false; // 1 indicates taller, -1 indicates shorter
    for (int i = 1; i < n; ++i) {
        if (nums[i - 1] < nums[i]) {
            wait_for_lower = true;
        } else if (nums[i - 1] > nums[i]) {
            if (wait_for_lower == true) return (i - 1); // i-1 is a peak
        }
    }
    if (wait_for_lower == false) return 0;
    else if (wait_for_lower == true) return n-1;
    return 0;
    #elif APR == 2
    // Binary search - O(logn)
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
        #if DEBUG
        cout << left << " " << mid << " " << right << endl;
        #endif
    }
    return left;
    #endif
    if (approach == 1) {
    } else if (approach == 2) {
    }
    return 0;
}

void test162() {
    cout << "Approach " << APR << endl;

    struct Case {
        vector<int> nums;
        vector<int> peaks; // Danh sách các chỉ số đỉnh hợp lệ
    };

    vector<Case> cases = {
        {{1,2,3,1}, {2}},
        {{1,2,1,3,5,6,4}, {1,5}},
        {{2,2,2,2,2,2}, {0,1,2,3,4,5}} // mọi vị trí đều là đỉnh
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        int res = findPeakElement(cases[i].nums);
        bool found = false;
        for (int peak : cases[i].peaks) {
            if (res == peak) {
                found = true;
                break;
            }
        }
        assertTest(found, true, i);
    }
}