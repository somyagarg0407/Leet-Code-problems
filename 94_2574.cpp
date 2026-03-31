#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        vector<int> ans;
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            int right = total - left - nums[i];
            ans.push_back(abs(left - right));
            left += nums[i];
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = obj.leftRightDifference(nums);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}