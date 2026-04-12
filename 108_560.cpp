#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;

            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];

                if (sum == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};
    int k = 3;

    cout << obj.subarraySum(nums, k);

    return 0;
}