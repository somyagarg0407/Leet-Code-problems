#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int value) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {

            if (curr->val == value) {
                prev->next = curr->next;
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};

// Create Linked List
ListNode* createLinkedList(vector<int> arr) {
    if (arr.empty()) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;

    for (int i = 1; i < arr.size(); i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }

    return head;
}

// Print Linked List
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Delete Entire Linked List
void deleteList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    vector<int> arr = {1, 2, 6, 3, 4, 5, 6};
    int value = 6;

    ListNode* head = createLinkedList(arr);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.removeElements(head, value);

    cout << "After Removing " << value << ": ";
    printList(head);

    deleteList(head);

    return 0;
}