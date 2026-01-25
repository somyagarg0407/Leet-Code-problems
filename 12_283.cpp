#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> zero;
        vector<int> nonzero;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero.push_back(nums[i]);
            } else {
                nonzero.push_back(nums[i]);
            }
        }

        nums = nonzero;
        nums.insert(nums.end(), zero.begin(), zero.end());
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 0, 3, 12};

    sol.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
