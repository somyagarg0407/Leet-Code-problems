#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> ans;

    if (root == nullptr) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        int size = q.size();

        vector<int> level;

        for (int i = 0; i < size; i++) {

            TreeNode* current = q.front();
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

vector<int> rightSideView(TreeNode* root) {

    vector<int> final;

    vector<vector<int>> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++) {

        final.push_back(ans[i][ans[i].size() - 1]);
    }

    return final;
}

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> result = rightSideView(root);

    cout << "Right Side View: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}