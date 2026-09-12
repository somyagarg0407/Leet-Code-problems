#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // {value, row, column}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        // Insert first element of every row
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        // Remove k - 1 smallest elements
        for (int i = 0; i < k - 1; i++) {
            vector<int> curr = pq.top();
            pq.pop();

            int row = curr[1];
            int col = curr[2];

            // Add next element from the same row
            if (col + 1 < n) {
                pq.push({matrix[row][col + 1], row, col + 1});
            }
        }

        return pq.top()[0];
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    cout << "Kth smallest element: "
         << obj.kthSmallest(matrix, k) << endl;

    return 0;
}