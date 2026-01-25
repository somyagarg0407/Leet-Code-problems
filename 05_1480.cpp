#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum = 0;//-----------read code problem also--------

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            result.push_back(sum);
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};   // sample input
    vector<int> ans = sol.runningSum(nums);

    cout << "Running Sum: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
