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

void inorder(TreeNode* root, vector<int>& v) {

    if (root == NULL) {
        return;
    }

    inorder(root->left, v);

    v.push_back(root->val);

    inorder(root->right, v);
}

bool isValidBST(TreeNode* root) {

    vector<int> v;

    inorder(root, v);

    for (int i = 0; i < v.size() - 1; i++) {

        if (v[i] >= v[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {

    /*
            5
           / \
          3   7
         / \   \
        2   4   8

        This is a valid BST.
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(8);

    if (isValidBST(root)) {
        cout << "Valid BST" << endl;
    }
    else {
        cout << "Not a Valid BST" << endl;
    }

    return 0;
}