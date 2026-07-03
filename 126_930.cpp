#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {

    unordered_map<int, int> mp;

    int count = 0;
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); i++) {

        prefixSum += nums[i];

        if (prefixSum == goal) {
            count++;
        }

        if (mp.find(prefixSum - goal) != mp.end()) {
            count += mp[prefixSum - goal];
        }

        mp[prefixSum]++;
    }

    return count;
}

int main() {

    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << "Answer = " << numSubarraysWithSum(nums, goal) << endl;

    return 0;
}