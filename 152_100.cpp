#include <iostream>
using namespace std;

// Definition of TreeNode
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL) {
            return true;
        }

        if (p == NULL || q == NULL) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {

    // Tree 1
    //       1
    //      / \
    //     2   3

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Tree 2
    //       1
    //      / \
    //     2   3

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(root1, root2))
        cout << "Trees are Same";
    else
        cout << "Trees are Different";

    return 0;
}