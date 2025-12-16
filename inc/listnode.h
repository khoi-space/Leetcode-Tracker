#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    // Initialization
    ListNode() {
        val = 0; 
        next = nullptr;
    };
    ListNode(int x) {
        val = x; 
        next = nullptr;
    };
    ListNode(int x, ListNode* _next) {
        val = x; 
        next = _next;
    };

    // Helper functions
    static ListNode* createList(const int *arr, int size) {
        if (size == 0) return nullptr;
        
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        
        for (int i = 1; i < size; ++i) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }

    void printList() const {
        const ListNode* cur = this;        
        while(cur != nullptr) {
            if (cur->next != nullptr) {
                cout << cur->val << "->";
            } else {
                cout << cur->val << '\n';
            }
            cur = cur->next;
        }
    }
};