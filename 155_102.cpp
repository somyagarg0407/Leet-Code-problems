#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q; // Queue to store nodes at each level
        q.push(root);

        while (!q.empty()) {

            int size = q.size(); // Get the number of nodes at the current level

            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* current = q.front(); // Get the front node in the queue
                q.pop();

                level.push_back(current->val);

                if (current->left != nullptr) {
                    q.push(current->left);
                }

                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};

int main() {

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";

    for (auto level : ans) {
        for (int value : level) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}