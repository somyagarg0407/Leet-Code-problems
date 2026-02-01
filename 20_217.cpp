#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i]] >= 2) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 1}; // sample input
    bool result = sol.containsDuplicate(nums);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
