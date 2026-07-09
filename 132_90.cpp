#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;
vector<int> curr;

void solve(int index, vector<int>& nums) {
    if (index == nums.size()) {
        ans.push_back(curr);
        return;
    }

    // Include current element
    curr.push_back(nums[index]);
    solve(index + 1, nums);
    curr.pop_back();

    // Skip all duplicates
    while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
        index++;
    }

    // Exclude current element
    solve(index + 1, nums);
}

int main() {
    vector<int> nums = {1, 2, 2};

    sort(nums.begin(), nums.end()); // --------IMPORTANT----------

    solve(0, nums);

    cout << "Subsets:\n";
    for (auto subset : ans) {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}