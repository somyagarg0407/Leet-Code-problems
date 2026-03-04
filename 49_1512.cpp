#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    int final = 0;

    for (auto& p : freq) {       //-----------------IMPORTANT--------------
        int f = p.second;
        final += (f * (f - 1)) / 2;
    }

    return final;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << numIdenticalPairs(nums);
    return 0;
}