#include <iostream>
#include <algorithm>
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
    int count = 0;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        count = max(count, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return count;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Diameter = "
         << obj.diameterOfBinaryTree(root)
         << endl;

    return 0;
}