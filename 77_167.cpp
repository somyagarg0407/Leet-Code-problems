#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target)
                return {left + 1, right + 1};

            else if (sum < target)
                left++;

            else
                right--;
        }

        return {};
    }
};

int main() {
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> target;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}