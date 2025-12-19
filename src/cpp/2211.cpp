#include "test.h"
 #include "global.h"
#include <iostream>
using namespace std;

int approach = 0;

/**
 * Problem 2211: Count Collision on a Road
 * @desc: Cars run at same speed. 
 *  Count += 2 if two cars move in opposite dir
 *  Count += 1 if one car stays and collides with another car
 * @dict: 'L' - left, 'R' - right, 'S' - stay
 * @input: a string of direction of each car
 * @output: number of collisions
 */
int countCollisions(string directions) {
    #if APR == 1
    // Simulation
    int collision_count = 0;
    int right_move_count = -1;
    for (char direction : directions) {
        if (direction == 'L') {
            if (right_move_count >= 0) {
                collision_count += right_move_count + 1;
                right_move_count = 0;
            }
        } else if (direction == 'S') {
            if (right_move_count > 0) {
                collision_count += right_move_count;
            }
            right_move_count = 0;
        } else if (direction == 'R') {
            if (right_move_count >= 0) {
                ++right_move_count;
            } else {
                right_move_count = 1;
            }
        } else {
            return -1;
        }
    }
    return collision_count;
    #elif APR == 2
    // Counting
    int collision_count = 0;
    int n = directions.size();
    int l = 0, r = n - 1;
    // Skip all left at head
    while (l < n && directions[l] == 'L') {
        ++l;
    }
    // Skip all right at tail
    while (r >= l && directions[r] == 'R') {
        --r;
    }

    // Count values that not 'S' in the rest
    for (int i = l; i <= r; ++i) {
        char d = directions[i];
        if (d == 'S') continue;
        if (d != 'L' && d != 'R') return -1; // Invalid
        ++collision_count;
    }
    return collision_count;
    #endif
}

void test2211() {
    cout << "Approach " << APR << endl;

    struct Case {
        string directions;
        int exp;
    };

    vector<Case> cases = {
        {"RLRSLL", 5},
        {"LLRR", 0},
        {"SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR", 20},
        {"S", 0},
        {"R", 0},
        {"L", 0},
        {"RS", 1},
        {"SL", 1},
        {"RRLL", 4},
        {"RRSLL", 4},
        {"LRLSL", 3},
        {"RLRL", 4},
        {"SR", 0},
        {"LS", 0},
        {"SSSS", 0},
        {"", 0},
        {"RRS", 2},
        {"LLS", 0},
        {"SRS", 1},
        {"RSL", 2},
        {"RXRL", -1} // Invalid directions
    };

    int i = 0;
    for (const auto& c : cases) {
        ++i;
        int res = countCollisions(c.directions);
        assertTest(res, c.exp, i);
    }
}

 