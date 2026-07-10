#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used;

    void solve(vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        used.assign(nums.size(), false);

        solve(nums);

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 1, 2};

    vector<vector<int>> ans = obj.permuteUnique(nums);

    for (auto &vec : ans) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}