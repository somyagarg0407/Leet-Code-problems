#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i]] > nums.size() / 2) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; // sample input
    int result = sol.majorityElement(nums);

    cout << result << endl;

    return 0;
}
