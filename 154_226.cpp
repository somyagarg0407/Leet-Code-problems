#include <iostream>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == nullptr) {
            return nullptr;
        }

        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert both subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Inorder traversal to check the result
void inorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}

int main() {

    /*
            Original Tree

                4
               / \
              2   7
             / \ / \
            1  3 6  9
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution obj;

    cout << "Before Inversion (Inorder): ";
    inorder(root);

    obj.invertTree(root);

    cout << "\nAfter Inversion (Inorder): ";
    inorder(root);

    return 0;
}