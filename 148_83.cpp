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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != NULL) {
            if (prev->val == curr->val) {
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = prev->next;
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

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

// Free Memory
void deleteList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 5};

    ListNode* head = createLinkedList(arr);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    deleteList(head);

    return 0;
}