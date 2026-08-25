#include <iostream>
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

TreeNode* insertIntoBST(TreeNode* root, int val) {

    if (root == NULL) {
        return new TreeNode(val);
    }

    TreeNode* cur = root;

    while (true) {

        if (cur->val <= val) {

            if (cur->right != NULL) {
                cur = cur->right;
            }
            else {
                cur->right = new TreeNode(val);
                break;
            }

        }
        else {

            if (cur->left != NULL) {
                cur = cur->left;
            }
            else {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }

    return root;
}

int main() {

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->right->right = new TreeNode(14);

    // Insert 7
    root = insertIntoBST(root, 7);

    return 0;
}