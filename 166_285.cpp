#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

    TreeNode* successor = NULL;

    while (root != NULL) {

        if (p->val >= root->val) {
            root = root->right;
        }
        else {
            successor = root;
            root = root->left;
        }
    }

    return successor;
}

int main() {

    /*
            5
           / \
          3   7
         / \   \
        2   4   8
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(8);

    // Find successor of 5
    TreeNode* p = root;

    TreeNode* result = inorderSuccessor(root, p);

    if (result != NULL) {
        cout << "Inorder Successor of "
             << p->val << " is "
             << result->val << endl;
    }
    else {
        cout << "No Inorder Successor" << endl;
    }

    return 0;
}