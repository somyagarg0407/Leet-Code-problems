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

int kthSmallest(TreeNode* root, int k) {

    vector<int> v;

    inorder(root, v);

    return v[k - 1];
}

int main() {

    // Creating BST
    //
    //          5
    //        /   \
    //       3     7
    //      / \     \
    //     2   4     8

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(8);

    int k = 3;

    cout << "Kth smallest element: "
         << kthSmallest(root, k) << endl;

    return 0;
}