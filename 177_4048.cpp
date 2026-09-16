#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSpecialIntegers(vector<int>& nums) {

    unordered_map<int, vector<int>> mp;

    // Store indices of every number
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    int ans = 0;

    // Check each number
    for (auto it : mp) {

        vector<int> v = it.second;

        // Exactly 3 occurrences
        if (v.size() == 3) {

            // Equally spaced
            if (v[1] - v[0] == v[2] - v[1]) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {

    vector<int> nums = {1, 8, 1, 5, 1, 5, 8, 5};

    cout << countSpecialIntegers(nums);

    return 0;
}