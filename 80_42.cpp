#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int count = 0; // leftMax & rightMax important hai isme

        while (left < right) {
            if (nums[left] < nums[right]) {
                if (nums[left] >= leftMax) {
                    leftMax = nums[left];
                } else {
                    count += leftMax - nums[left];
                }
                left++;
            } else {
                if (nums[right] >= rightMax) {
                    rightMax = nums[right];
                } else {
                    count += rightMax - nums[right];
                }
                right--;
            }
        }
        return count;
    }
};