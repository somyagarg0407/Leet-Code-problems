#include <iostream>
#include <unordered_set>
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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited;

        while (head != nullptr) {
            if (visited.count(head)) {
                return true;
            }

            visited.insert(head);
            head = head->next;
        }

        return false;
    }
};

int main() {
    // Create nodes
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    // Create linked list: 3 -> 2 -> 0 -> -4
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Create cycle: -4 -> 2
    n4->next = n2;

    Solution obj;

    if (obj.hasCycle(n1))
        cout << "Cycle Found\n";
    else
        cout << "No Cycle\n";

    return 0;
}