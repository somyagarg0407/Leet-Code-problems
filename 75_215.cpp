#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return nums[k - 1];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = obj.findKthLargest(nums, k);

    cout << "Kth largest element: " << result << endl;

    return 0;
}