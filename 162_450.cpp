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

class Solution {
public:

    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }

        return findLastRight(root->right);
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }

        else if (root->right == NULL) {
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);

        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return root;
        }

        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;

        while (root != NULL) {

            if (root->val > key) {

                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }

                else {
                    root = root->left;
                }
            }

            else {

                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }

                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};

// Inorder traversal to check the BST
void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    // Creating BST
    //
    //          5
    //        /   \
    //       3     7
    //      / \   / \
    //     2   4 6   8

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << "Before deletion: ";
    inorder(root);

    Solution obj;

    int key = 3;

    root = obj.deleteNode(root, key);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}