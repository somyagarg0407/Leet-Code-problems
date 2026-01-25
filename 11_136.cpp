#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> hash;

        // count frequency
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        // find the element with frequency 1
        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i]] == 1) {
                return nums[i];
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {4, 1, 2, 1, 2};

    cout << sol.singleNumber(nums);

    return 0;
}
