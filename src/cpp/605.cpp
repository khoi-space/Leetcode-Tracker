#include "test.h"
#include "global.h"
using namespace std;

/**
 * Problem 605: Can Place Flowers
 * @input: flowerbed with 0 means empty and 1 means not empty
 * @output: true if n new flowers ccan be planted in the flowerbed with adjacent rule
*/
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    // Try to plant at the even idx (begin with 0)
    int len = flowerbed.size();
    int remain = n;
    for (int i = 0; i < len && remain != 0; ++i) {
        if (flowerbed[i] == 0) {
            bool empty_left = (i == 0) || (flowerbed[i-1] == 0);
            bool empty_right = (i == len - 1) || (flowerbed[i+1] == 0);

            if (empty_left && empty_right) {
                flowerbed[i] = 1;
                --remain;
            }
        }
    }
    return (remain == 0);
}

void test605() {
    struct Case {
        vector<int> flowerbed;
        int n;
        bool exp;
    };

    vector<Case> cases = {
        {{1,0,0,0,1}, 1, true},
        {{1,0,0,0,1}, 2, false},
        {{0,0,1,0,1}, 1, true}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        bool res = canPlaceFlowers(cases[i].flowerbed, cases[i].n);
        assertTest(res, cases[i].exp, i);
    }
}
