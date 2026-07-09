#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> curr;
vector<bool> used;

void solve(vector<int>& nums) {
    if (curr.size() == nums.size()) {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i])
            continue;

        used[i] = true;
        curr.push_back(nums[i]);

        solve(nums);

        curr.pop_back();
        used[i] = false;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};

    used.assign(nums.size(), false);

    solve(nums);

    cout << "Permutations:\n";

    for (auto &v : ans) {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}