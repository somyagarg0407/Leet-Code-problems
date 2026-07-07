#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minSubarray(vector<int>& nums, int p) {
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    int need = sum % p;

    if (need == 0) {
        return 0;
    }

    unordered_map<int, int> mp;
    mp[0] = -1;

    long long sums = 0;
    int ans = nums.size();

    for (int i = 0; i < nums.size(); i++) {
        sums += nums[i];

        int rem = sums % p;
        int target = (rem - need + p) % p;

        if (mp.find(target) != mp.end()) {
            ans = min(ans, i - mp[target]);
        }

        mp[rem] = i;
    }

    if (ans == nums.size()) {
        return -1;
    } else {
        return ans;
    }
}

int main() {
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;

    cout << minSubarray(nums, p) << endl;

    return 0;
}