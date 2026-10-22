#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxAlternatingSum(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
        }
    }

    sort(nums.begin(), nums.end());

    long long score = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        long long x = nums[i];

        if (i < n / 2) {
            score -= x * x;
        } else {
            score += x * x;
        }
    }

    return score;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxAlternatingSum(nums) << endl;

    return 0;
}