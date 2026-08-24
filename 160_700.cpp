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

TreeNode* searchBST(TreeNode* root, int val) {

    while (root != NULL && root->val != val) {

        if (root->val < val) {
            root = root->right;
        }
        else {
            root = root->left;
        }
    }

    return root;
}

int main() {

    // Creating BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;

    TreeNode* result = searchBST(root, val);

    if (result != NULL) {
        cout << "Found: " << result->val << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    return 0;
}