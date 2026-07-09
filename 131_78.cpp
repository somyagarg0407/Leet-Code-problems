#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> curr;

void solve(int index, vector<int>& nums) {
    if (index == nums.size()) {
        ans.push_back(curr);
        return;
    }

    curr.push_back(nums[index]);

    solve(index + 1, nums);

    curr.pop_back();

    solve(index + 1, nums);
}

vector<vector<int>> subsets(vector<int>& nums) {
    ans.clear();
    curr.clear();

    solve(0, nums);

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    for (auto subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}