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

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (root == nullptr) {
            return false;
        }

        // Check only at leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        targetSum = targetSum - root->val;

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};

int main() {

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution obj;

    int targetSum = 22;

    if (obj.hasPathSum(root, targetSum)) {
        cout << "Path exists!" << endl;
    }
    else {
        cout << "Path does not exist!" << endl;
    }

    return 0;
}