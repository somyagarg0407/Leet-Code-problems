#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for (int i = 0; i < accounts.size(); i++) {
            int currSum = 0;
            for (int j = 0; j < accounts[i].size(); j++) {
                currSum += accounts[i][j];
            }
            maxWealth = max(maxWealth, currSum);
        }

        return maxWealth;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> accounts = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 3, 2}
    };

    cout << "Maximum Wealth: " << obj.maximumWealth(accounts) << endl;

    return 0;
}
