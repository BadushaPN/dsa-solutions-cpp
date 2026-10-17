#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    // Iterative reversal (LeetCode 206)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    // Recursive reversal
    ListNode* reverseListRecursive(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

// Helpers for tests
ListNode* make_list(const vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* tail = dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

vector<int> to_vector(ListNode* head) {
    vector<int> out;
    while (head) {
        out.push_back(head->val);
        head = head->next;
    }
    return out;
}

void print_vector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main() {
    Solution sol;

    vector<int> a1 = {1,2,3,4,5};
    ListNode* l1 = make_list(a1);
    ListNode* r1 = sol.reverseList(l1);
    print_vector(to_vector(r1)); // expected: 5 4 3 2 1

    vector<int> a2 = {1,2};
    ListNode* l2 = make_list(a2);
    ListNode* r2 = sol.reverseListRecursive(l2);
    print_vector(to_vector(r2)); // expected: 2 1

    vector<int> a3 = {};
    ListNode* l3 = make_list(a3);
    ListNode* r3 = sol.reverseList(l3);
    print_vector(to_vector(r3)); // expected: (empty line)

    return 0;
}
