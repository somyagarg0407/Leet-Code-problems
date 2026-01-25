#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> first;
        vector<int> last;
        vector<int> final;

        for (int i = 0; i < nums.size() / 2; i++) {
            first.push_back(nums[i]);
        }

        for (int i = nums.size() / 2; i < nums.size(); i++) {
            last.push_back(nums[i]);
        }

        for (int i = 0; i < first.size(); i++) {
            final.push_back(first[i]);
            final.push_back(last[i]);
        }

        return final;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    vector<int> result = sol.shuffle(nums, n);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
