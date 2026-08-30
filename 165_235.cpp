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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    while (root != NULL) {

        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }

        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }

        else {
            return root;
        }
    }

    return NULL;
}

int main() {

    /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5

        Find LCA of 2 and 8
        Answer = 6
    */

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;        // 2
    TreeNode* q = root->right;       // 8

    TreeNode* result = lowestCommonAncestor(root, p, q);

    if (result != NULL) {
        cout << "LCA = " << result->val << endl;
    }
    else {
        cout << "LCA not found" << endl;
    }

    return 0;
}