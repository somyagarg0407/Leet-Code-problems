#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};  // sample input
    sol.sortColors(nums);

    // print sorted array
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
