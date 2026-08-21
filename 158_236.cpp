#include <iostream>
using namespace std;

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if (root == nullptr) {
        return nullptr;
    }

    if (root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // p and q found in different subtrees
    if (left != nullptr && right != nullptr) {
        return root;
    }

    // If only left found, return left
    if (left != nullptr) {
        return left;
    }

    // If only right found
    return right;
}

int main() {

    // Creating the tree
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // p = 5, q = 4
    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;

    TreeNode* ans = lowestCommonAncestor(root, p, q);

    cout << "LCA = " << ans->val << endl;

    return 0;
}