#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> finalArr;
        for (int i = 0; i < nums.size(); i++) {
            finalArr.push_back(nums[i] * nums[i]);
        }
        sort(finalArr.begin(), finalArr.end());
        return finalArr;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-4, -1, 0, 3, 10};   // sample input
    vector<int> result = sol.sortedSquares(nums);

    // print output
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
