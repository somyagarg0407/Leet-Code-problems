#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumRight;
        int sumLeft;
        int pivotIndex = 0;

        while (pivotIndex < nums.size()) {
            sumRight = 0;
            sumLeft = 0;

            for (int i = pivotIndex - 1; i >= 0; i--) {
                sumLeft += nums[i];
            }

            for (int j = pivotIndex + 1; j < nums.size(); j++) {
                sumRight += nums[j];
            }

            if (sumLeft == sumRight) {
                return pivotIndex;
            }
            pivotIndex++;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 7, 3, 6, 5, 6};  // sample input
    int result = sol.pivotIndex(nums);

    cout << result << endl;

    return 0;
}
