
#include "test.h"
#include "global.h"
using namespace std;

#define DEBUG

/**
 * Problem 2: Add Two Numbers
 * @input: two non-empty linked lists representing two non-negative integers (reserve ordered)
 * @output: the sum as a linked list
 */
ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* curr = dummyHead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry) {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        int sum = x + y + carry;
        curr->next = new ListNode(sum % 10);
        carry = sum / 10;
        curr = curr->next;
        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }
    return dummyHead->next;
}

void test2() {
    struct Case {
        vector<int> arr1;
        vector<int> arr2;
        vector<int> exp;
    };

    vector<Case> cases = {
        {{9,9,9,9}, {1}, {0,0,0,0,1}},
        {{2,4,3}, {5,6,4}, {7,0,8}},
        {{0}, {0}, {0}},
        {{1,8}, {0}, {1,8}},
        {{5}, {5}, {0,1}},
    };

    int i = 0;
    for (const auto& c : cases) {
        ++i;
        ListNode* l1 = ListNode::createList(c.arr1.data(), c.arr1.size());
        ListNode* l2 = ListNode::createList(c.arr2.data(), c.arr2.size());
        ListNode* exp = ListNode::createList(c.exp.data(), c.exp.size());
        ListNode* res = addTwoNumber(l1, l2);
        assertTest(res, exp, i);
    }
}