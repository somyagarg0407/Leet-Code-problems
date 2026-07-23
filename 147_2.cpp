#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* next) {
        val = x;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int x;
        int y;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {

            if (l1 != nullptr) {
                x = l1->val;
            } else {
                x = 0;
            }

            if (l2 != nullptr) {
                y = l2->val;
            } else {
                y = 0;
            }

            int sum = x + y + carry;

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (carry) {
            tail->next = new ListNode(carry);
        }

        return head->next;
    }
};


ListNode* createList(vector<int> arr) {

    if (arr.empty())
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;

    for (int i = 1; i < arr.size(); i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }

    return head;
}

void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // --------------342 + 465 = 807 ------------------
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    Solution obj;
    ListNode* ans = obj.addTwoNumbers(l1, l2);

    cout << "Answer: ";
    printList(ans);

    return 0;
}