#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> final;
        for (int i = 0; i < nums.size(); i++) {
            final.push_back(nums[nums[i]]);
        }
        return final;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 2, 1, 5, 3, 4};

    vector<int> result = sol.buildArray(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
