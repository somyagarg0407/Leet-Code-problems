#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {

    unordered_map<int, int> mp;
    int count = 0;

    vector<int> prefix(nums.size());

    if (nums.size() == 1 && nums[0] != k) {
        return 0;
    }

    prefix[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    for (int i = 0; i < nums.size(); i++) {

        if (prefix[i] == k) {
            count++;
        }

        if (mp.find(prefix[i] - k) != mp.end()) {
            count += mp[prefix[i] - k];
        }

        mp[prefix[i]]++;
    }

    return count;
}

int main() {

    vector<int> nums = {1, 2, 3};
    int k = 3;

    cout << "Answer = " << subarraySum(nums, k);

    return 0;
}