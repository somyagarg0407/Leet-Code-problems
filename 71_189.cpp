#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;

        vector<int> ans;

        for (int i = n - 1; i >= n - k; i--)
            ans.push_back(nums[i]);

        reverse(ans.begin(), ans.end());

        for (int i = 0; i < n - k; i++)
            ans.push_back(nums[i]);

        for (int i = 0; i < n; i++)
            nums[i] = ans[i];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    obj.rotate(nums, k);

    cout << "Rotated array: ";
    for (int x : nums)
        cout << x << " ";

    return 0;
}