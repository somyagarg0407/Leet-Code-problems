#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
            }
            else {
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
            }
        }

        if (head1 == nullptr) {
            tail->next = head2;
        }
        else {
            tail->next = head1;
        }

        dummy = dummy->next;
        return dummy;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // List 1: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    // List 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution obj;
    ListNode* ans = obj.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(ans);

    return 0;
}