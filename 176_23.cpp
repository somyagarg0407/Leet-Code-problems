#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        if (a)
            tail->next = a;
        else
            tail->next = b;

        return dummy.next;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int left, int right) {

        // Only one list
        if (left == right) {
            return lists[left];
        }

        int mid = left + (right - left) / 2;

        ListNode* a = mergeSort(lists, left, mid);
        ListNode* b = mergeSort(lists, mid + 1, right);

        return mergeTwoLists(a, b);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) {
            return nullptr;
        }

        return mergeSort(lists, 0, lists.size() - 1);
    }
};

ListNode* createList(vector<int> arr) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int x : arr) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    vector<ListNode*> lists;

    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    Solution obj;

    ListNode* result = obj.mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}
