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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        if (n == count) {
            return head->next;
        }

        int x = count - n;

        ListNode* nextNode = head;
        ListNode* prevNode = nullptr;
        int count2 = 0;

        while (count2 != x) {
            prevNode = nextNode;
            nextNode = nextNode->next;
            count2++;
        }

        prevNode->next = nextNode->next;
        nextNode->next = nullptr;

        return head;
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
    // Create: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove 2nd node from the end (4)

    Solution obj;
    head = obj.removeNthFromEnd(head, n);

    cout << "Updated List: ";
    printList(head);

    return 0;
}