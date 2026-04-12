#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            int rem = sum % k;

            // handle negative remainder
            if (rem < 0) rem += k;

            count += mp[rem];
            mp[rem]++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = obj.subarraysDivByK(nums, k);

    cout << "Answer: " << result << endl;

    return 0;
}