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

    // Check every number
    for (auto it : mp) {

        vector<int> v = it.second;

        // At least 3 occurrences
        if (v.size() >= 3) {

            int gap = v[1] - v[0];
            bool special = true;

            // Check all consecutive gaps
            for (int i = 2; i < v.size(); i++) {

                if (v[i] - v[i - 1] != gap) {
                    special = false;
                    break;
                }
            }

            if (special) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {

    vector<int> nums = {5, 1, 5, 2, 5, 3, 5};

    cout << countSpecialIntegers(nums) << endl;

    return 0;
}