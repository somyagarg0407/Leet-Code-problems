#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;

        int maxLength = 0;
        int prefixSum = 0;

        mp[0] = -1;   // Base case

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) {
                prefixSum--;
            } else {
                prefixSum++;
            }

            if (mp.find(prefixSum) != mp.end()) {
                maxLength = max(maxLength, i - mp[prefixSum]);
            } else {
                mp[prefixSum] = i;   // Store first occurrence only
            }
        }

        return maxLength;
    }
};

int main() {

    Solution obj;
    vector<int> nums = {1, 1, 1, 0, 0};
    cout << "Maximum Length = " << obj.findMaxLength(nums);
    return 0;
}