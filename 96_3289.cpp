#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    ans.push_back(nums[i]);
                    count++;
                }
                if (count == 2) {
                    break;
                }
            }
            if (count == 2) {
                break;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 2, 4, 1};

    vector<int> result = obj.getSneakyNumbers(nums);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}