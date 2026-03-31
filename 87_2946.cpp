#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans = mat;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                
                for (int j = 0; j < m; j++) {
                    ans[i][j] = mat[i][(j + k) % m];//-------------#############----------------
                }
            } else {
                
                for (int j = 0; j < m; j++) {
                    ans[i][j] = mat[i][(j - k % m + m) % m];//----------------------###################--------------
                }
            }
        }

        return ans == mat;
    }
};

int main() {
    Solution obj;

    int n, m, k;
    cout << "Enter rows, cols: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter k: ";
    cin >> k;

    if (obj.areSimilar(mat, k)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}