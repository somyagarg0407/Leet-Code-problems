#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int counter = 0;

        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            int temp = nums[i];   // important: use a temp variable

            while (temp > 0) {
                temp = temp / 10;
                count++;
            }

            if (count % 2 == 0) {
                counter++;
            }
        }

        return counter;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {12, 345, 2, 6, 7896};

    cout << sol.findNumbers(nums);

    return 0;
}
