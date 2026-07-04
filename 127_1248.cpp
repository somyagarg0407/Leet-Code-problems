#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int goal) {

    unordered_map<int, int> mp;

    int count = 0;
    int odd = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] % 2 != 0) {
            odd++;
        }

        if (odd == goal) {
            count++;
        }

        if (mp.find(odd - goal) != mp.end()) {
            count += mp[odd - goal];
        }

        mp[odd]++;
    }

    return count;
}

int main() {

    vector<int> nums = {1, 1, 2, 1, 1};
    int goal = 3;

    cout << "Answer = " << numberOfSubarrays(nums, goal) << endl;

    return 0;
}